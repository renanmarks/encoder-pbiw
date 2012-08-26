/* 
 * File:   pbiw_encoder.cpp
 * Author: helix
 *
 * Created on July 20, 2011, 3:15 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "src/rVex/Parser/driver.h"
#include "src/rVex/Parser/VexContext.h"
#include "pbiw_encoder.h"
#include "src/rVex/Printers/rVexPrinter.h"
#include "src/rVex/Printers/VHDLPrinter.h"

#include "src/rVex/PBIWPartial/PartialPBIW.h"
#include "src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.h"
#include "src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.h"

#include "src/rVex/PBIWFull/FullPBIW.h"
#include "src/rVex/PBIWFull/Printers/FullPBIWPrinter.h"
#include "src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.h"

#include "src/rVex/Parser/VexTypes.h"
#include "src/PBIW/BaseOptimizer.h"
#include "src/PBIW/PBIWOptimizerJoinPatterns.h"
#include "src/PBIW/Interfaces/IPBIWPattern.h"
#include "src/PBIW/PBIWOptimizerDataSet.h"
//#include "Time/ExecutionTime.h"

/**
 * Parses, processes and assembles the rVex assembly file(s).
 */
void assembleVex(VexParser::VexContext& context,
              const std::string& filename, 
              const std::string& flags,
              bool debugEnabled,
              bool traceParsing, 
              bool traceScanning)
{
  // read a file with expressions
  std::fstream infile(filename.c_str());

  if (!infile.good())
  {
    std::cerr << "Could not open file: " << filename << std::endl;
    return;
  }

  // Create the full parser stack!
  VexParser::Driver driver(context);
  driver.trace_parsing = traceParsing;
  driver.trace_scanning = traceScanning;

  // Do the parsing
  driver.parse_stream(infile, filename); // O(1)
  driver.context.endParsing();
  
  context.enableDebugging(debugEnabled);
  context.processLabels(); // O(1)
  
  if (debugEnabled)
  {
    // Assembler debug printer
    rVex::Printers::rVexPrinter debugPrinter(std::cout);
    
    context.print(debugPrinter); // O(|instructions|)
  } 
  else
  {
    std::string outputFilename=filename;
    outputFilename+=".vhd";
    
    // Assembler VHDL printer
    std::ofstream assembledFile(outputFilename.c_str());
    rVex::Printers::VHDLPrinter vhdlPrinter(assembledFile);

    std::cout << "Assembled file: " << outputFilename << std::endl;
    
    vhdlPrinter.setFileName(filename);
    vhdlPrinter.setAssemblerFlags(flags);
    
    context.print(vhdlPrinter); // O(|instructions|)
  }
}

/**
 * Template function to be the framework of PBIW encoder execution
 * for the rVex processor.
 */
template <class TPBIWPrinter>
void
encodePBIW(const std::string& filename,
                  const VexParser::VexContext& context,
                  PBIW::Interfaces::IPBIW& pbiwContext,
                  bool optimize)
{
  // Instantiate the PBIW optimizer
  PBIW::PBIWOptimizerJoinPatterns patternJoinOptimizer;
  
  if (context.isDebuggingEnabled())
  {
    TPBIWPrinter printer(std::cout);
    
    pbiwContext.setDebug(context.isDebuggingEnabled());
    pbiwContext.encode(context.getInstructions());
    
    if (optimize)
    {
      pbiwContext.registerOptimizer(patternJoinOptimizer);
      pbiwContext.runOptimizers();
      
      std::cout << " --- Optimizer debug information ---" << std::endl;
    
      patternJoinOptimizer.printInstructions(printer);
      patternJoinOptimizer.printPatterns(printer); 
      patternJoinOptimizer.printStatistics(printer, 
                                      context.getInstructions().size(), 
                                      pbiwContext.getPatterns().size(), 
                                      pbiwContext.getInstructions().size());
      
      return;
    }
    
    pbiwContext.printInstructions(printer);
    pbiwContext.printPatterns(printer);
    pbiwContext.printStatistics(printer);
    
    return;
  }
  
  // Create the output filenames
  std::string imemFilename = filename;
  imemFilename += ".pbiw.vhd";

  std::string pcacheFilename = filename;
  pcacheFilename += ".pcache.vhd";

  std::cout << "PBIW instructions file: " << imemFilename << std::endl
            << "PBIW patterns file: " << pcacheFilename << std::endl
            << std::endl;
  
  // Create the files
  std::ofstream imemFile(imemFilename.c_str());
  std::ofstream pcacheFile(pcacheFilename.c_str());

  TPBIWPrinter pbiwInstructionPrinter(imemFile);
  TPBIWPrinter pbiwPatternPrinter(pcacheFile);
  TPBIWPrinter pbiwStatisticsPrinter(std::cout);
  
  // UNLEASH THE PBIW ENCODER!
  pbiwContext.encode(context.getInstructions());

  // If they like to squash size...
  if (optimize)
  {
    pbiwContext.registerOptimizer(patternJoinOptimizer);
    pbiwContext.runOptimizers();

    std::cout << " --- Begin Full post optimizer data (Debug)---" << std::endl;

    patternJoinOptimizer.printInstructions(pbiwInstructionPrinter);
    patternJoinOptimizer.printPatterns(pbiwPatternPrinter); 
    patternJoinOptimizer.printStatistics(pbiwStatisticsPrinter, 
                                      context.getInstructions().size(), 
                                      pbiwContext.getPatterns().size(), 
                                      pbiwContext.getInstructions().size());
    
    return;
  }

  pbiwContext.printInstructions(pbiwInstructionPrinter);
  pbiwContext.printPatterns(pbiwPatternPrinter);
  pbiwContext.printStatistics(pbiwStatisticsPrinter);
  
  return;
}

/**
 * The function used to call the Partial PBIW encode scheme on the
 * rVex assembly context.
 */
void encodePartialPBIW(const std::string& filename,
                       const VexParser::VexContext& context,
                       bool optimize)
{
  PBIWPartial::PartialPBIW pbiwContext;
  
  if (context.isDebuggingEnabled())
    encodePBIW<PBIWPartial::PartialPBIWDebugPrinter>(filename, context, pbiwContext, optimize);
  else
    encodePBIW<PBIWPartial::PartialPBIWPrinter>(filename, context, pbiwContext, optimize);
  
  return;
}

/**
 * The function used to call the Full PBIW encode scheme on the
 * rVex assembly context.
 */
void encodeFullPBIW(const std::string& filename,
                    const VexParser::VexContext& context,
                    bool optimize)
{
  PBIWFull::FullPBIW pbiwContext;
  
    if (context.isDebuggingEnabled())
      encodePBIW<PBIWFull::FullPBIWDebugPrinter>(filename, context, pbiwContext, optimize);
    else
      encodePBIW<PBIWFull::FullPBIWPrinter>(filename, context, pbiwContext, optimize);
  
  return;
}

/**
 * Main function.
 */
int
main(int argc, char** argv)
{
  std::string version = "3.0";
  
  if (argc == 1)
    std::cout << "Please specify an input file to process." << std::endl;
  
  bool traceParsing = false;
  bool traceScanning = false;
  bool debugEnabled = false;
  bool fullPBIW = false;
  bool optimizePBIW = false;
  
  std::string flags;
  
  for (int ai=1; ai < argc; ++ai) // O(|argc|)
  {
    if (argv[ai] == std::string("-h") || argv[ai] == std::string("--help"))
    {
      std::cout 
      << 
"PBIW Encoder - Version "<< version << "\n\
This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
---\n" 
      << 
      std::endl;
      
      {
        typedef std::list<std::string> StringList;
        StringList archs;

        archs.push_back("rVex Processor");

        std::cout << "Architectures supported in this version:" << std::endl;

        StringList::const_iterator it;

        for (it = archs.begin(); it != archs.end(); it++)
          std::cout << "  " << *it << std::endl;

        std::cout << "\n---\n" << std::endl;
      }
      
      std::cout << "\n\tUsage: " << argv[0] << " [options] input.s\n" << std::endl
        << "This will generate 3 files:" << std::endl
        << "- input.s.vhd: Contains the binary VHDL assembly to run in rVex;" << std::endl
        << "- input.s.pbiw.vhd: Contains the PBIW instructions binary VHDL assembly to run in rVex;" << std::endl
        << "- input.s.pcache.vhd: Contains the PBIW patterns binary VHDL assembly to run in rVex;\n" << std::endl;
      
      std::cout << "Options:" << std::endl
        << "-p\tTrace parsing" << std::endl
        << "-s\tTrace scanning" << std::endl
        << "-O\tEnable PBIW optimization" << std::endl
        << "-u\tEnable rVex PBIW constrained encoding (Default)" << std::endl
        << "-uc\tEnable rVex PBIW unconstrained encoding" << std::endl
        << std::endl;

      return 0;
    } 
    else if (argv[ai] == std::string("-p"))
    {
      flags.append("-p ");
      traceParsing=true;
      
      std::cout << "Info: Parser debug printing enabled." << std::endl;
    }
    else if (argv[ai] == std::string("-s"))
    {
      flags.append("-s ");
      traceScanning=true;
      
      std::cout << "Info: Lexer debug printing enabled." << std::endl;
    }
    else if (argv[ai] == std::string("-d"))
    {
      flags.append("-d ");
      // Lets be verbose! :)
      debugEnabled=true;
      
      std::cout << "Info: Debug information printing enabled." << std::endl;
    } 
    else if (argv[ai] == std::string("-O"))
    {
      flags.append("-O ");
      optimizePBIW=true;
      
      std::cout << "Info: PBIW optimization enabled." << std::endl;
    }
    else if (argv[ai] == std::string("-c"))
    {
      flags.append("-c ");
      fullPBIW = false;
      
      std::cout << "Info: Constrained PBIW encoding enabled." << std::endl;
    }
    else if (argv[ai] == std::string("-uc"))
    {
      flags.append("-uc ");
      fullPBIW = true;
      
      std::cout << "Info: Unconstrained PBIW encoding enabled." << std::endl;
    } 
    else
    {
      std::string filename=argv[ai];

      VexParser::VexContext context;
      assembleVex(context, filename, flags, debugEnabled, traceParsing, traceScanning);
      
      if (fullPBIW)
        encodeFullPBIW(filename, context, optimizePBIW);
      else
        encodePartialPBIW(filename, context, optimizePBIW);
      
//      PBIW::PBIWOptimizerDataSet dataSet;
//      encodePBIW(filename, flags, debugEnabled, traceParsing, traceScanning, dataSet);
    }
  }

  // Clean the memory
  std::vector<VexParser::VexOpcode>::iterator it;

  for (it=operationTable.begin();
       it < operationTable.end();
       it++)
  {
    if (it->syllableConstructor != NULL)
      delete it->syllableConstructor;
  }

  return 0;
}
