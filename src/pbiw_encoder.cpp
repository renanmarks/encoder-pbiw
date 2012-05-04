/* 
 * File:   pbiw_encoder.cpp
 * Author: helix
 *
 * Created on July 20, 2011, 3:15 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "VexParser/driver.h"
#include "VexParser/VexContext.h"
#include "pbiw_encoder.h"
#include "rVex/Printers/rVexPrinter.h"
#include "rVex/Printers/VHDLPrinter.h"
#include "PBIW/FullPBIW.h"
#include "PBIW/Printers/PartialPBIWPrinter.h"
#include "PBIW/Printers/PartialPBIWDebugPrinter.h"
#include "VexParser/VexTypes.h"
#include "PBIW/BaseOptimizer.h"
//#include "PBIW/PBIWOptimizerJoinPatterns.h"
//#include "Time/ExecutionTime.h"


bool execute(const std::string&, const std::string&, bool, bool, bool);

int
main(int argc, char** argv)
{
  //  Time::ExecutionTime time;  
  //  time.start();
  std::string flags;
  std::string version = "2.0";

  bool result=false;
  bool traceParsing=false;
  bool traceScanning=false;
  bool debugEnabled=false;

  std::cout << "rVex Assembler and PBIW encoder - Version "<< version << std::endl;
  std::cout << "---\n" << std::endl;
  
  if (argc == 1)
    std::cout << "Please specify an Vex assembly file to process." << std::endl;
  
  for (int ai=1; ai < argc; ++ai) // O(|argc|)
  {
    if (argv[ai] == std::string("-h") || argv[ai] == std::string("--help"))
    {
      std::cout << "\n\tUsage: " << argv[0] << " [options] input.s\n" << std::endl
        << "This will generate 3 files:" << std::endl
        << "- input.s.vhd: Contains the binary VHDL assembly to run in rVex;" << std::endl
        << "- input.s.pbiw.vhd: Contains the PBIW instructions binary VHDL assembly to run in rVex;" << std::endl
        << "- input.s.pcache.vhd: Contains the PBIW patterns binary VHDL assembly to run in rVex;\n" << std::endl;
      
      std::cout << "Options:" << std::endl
        << "-p\tTrace parsing" << std::endl
        << "-s\tTrace scanning" << std::endl
        << "-d\tEnable verbose debug" << std::endl
        << std::endl;

      return 0;
    } else if (argv[ai] == std::string("-p"))
    {
      flags.append("-p ");
      traceParsing=true;
    }
    else if (argv[ai] == std::string("-s"))
    {
      flags.append("-s ");
      traceScanning=true;
    }
    else if (argv[ai] == std::string("-d"))
    {
      flags.append("-d ");
      // Lets be verbose! :)
      debugEnabled=true;
      
      std::cout << "Debugging information: " << std::endl;
    } else
    {
      std::string filename=argv[ai];

      execute(filename, flags, debugEnabled, traceParsing, traceScanning);
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

  //  time.finish();

  return 0;
}

/**
 * Execute the parser and the PBIW encoder.
 *
 * @returns if the parsing was OK or not;
 */
bool
execute(const std::string& filename, const std::string& flags, bool debugEnabled, bool traceParsing, bool traceScanning)
{
  // read a file with expressions
  std::fstream infile(filename.c_str());

  if (!infile.good())
  {
    std::cerr << "Could not open file: " << filename << std::endl;
    return 0;
  }

  // Assembler debug printer
  rVex::Printers::rVexPrinter debugPrinter(std::cout);

  // Assembler VHDL printer
  std::ofstream assembledFile;
  rVex::Printers::VHDLPrinter vhdlPrinter(assembledFile);

  // Pointer to ease changing them
  rVex::Printers::IPrinter* printer= &vhdlPrinter;

  if (debugEnabled)
  {
    printer= &debugPrinter;
  } 
  else
  {
    std::string outputFilename=filename;
    outputFilename+=".vhd";

    std::cout << "Assembled file: " << outputFilename << std::endl;
    
    assembledFile.open(outputFilename.c_str());

    vhdlPrinter.setFileName(filename);
    vhdlPrinter.setAssemblerFlags(flags);
  }

  // Create the full parser stack!
  VexParser::VexContext context(*printer);
  context.enableDebugging(debugEnabled);

  VexParser::Driver driver(context);
  driver.trace_parsing=traceParsing;
  driver.trace_scanning=traceScanning;

  // Do the parsing
  bool result=driver.parse_stream(infile, filename); // O(1)
  driver.context.endParsing();

  context.processLabels(); // O(1)
  context.print(); // O(|instructions|)

//  PBIW::PBIWOptimizerJoinPatterns optmizer;
    
  // Instantiate the PBIW encoder
  PBIW::FullPBIW pbiw;
  pbiw.setDebug(context.isDebuggingEnabled());
  
  if (context.isDebuggingEnabled())
  {
    PBIW::PartialPBIWDebugPrinter pbiwDebugPrinter(std::cout);
    context.encodePBIW(pbiw); // O(|codedPatterns|^2)
    
//    pbiw.registerOptimizer(optmizer);
//    pbiw.runOptimizers();
    
    pbiw.printInstructions(pbiwDebugPrinter);
    pbiw.printPatterns(pbiwDebugPrinter);
    pbiw.printStatistics(pbiwDebugPrinter);
    
    std::cout << " --- Begin post optimizer data ---" << std::endl;
    
//    optmizer.printInstructions(pbiwDebugPrinter);
//    optmizer.printPatterns(pbiwDebugPrinter); 
//    optmizer.printStatistics(pbiwDebugPrinter, context.getInstructions().size());
  } 

  else
  {
    std::string imemFilename=filename;
    imemFilename+=".pbiw.vhd";

    std::string pcacheFilename=filename;
    pcacheFilename+=".pcache.vhd";

    std::ofstream imemFile(imemFilename.c_str());
    std::ofstream pcacheFile(pcacheFilename.c_str());

    std::cout 
      << "PBIW instructions file: " << imemFilename << std::endl
      << "PBIW patterns file: " << pcacheFilename << std::endl
      << std::endl;
    
    PBIW::PartialPBIWPrinter statisticsPBIWPrinter(std::cout);
    PBIW::PartialPBIWPrinter imemPBIWPrinter(imemFile);
    PBIW::PartialPBIWPrinter pachePBIWPrinter(pcacheFile);

    context.encodePBIW(pbiw); // O(|codedPatterns|^2)
    
//    pbiw.registerOptimizer(optmizer);
//    pbiw.runOptimizers();
    
    pbiw.printStatistics(statisticsPBIWPrinter);
//    pbiw.printInstructions(imemPBIWPrinter);
//    pbiw.printPatterns(pachePBIWPrinter);
    
//    optmizer.printStatistics(statisticsPBIWPrinter, context.getInstructions().size());
//    optmizer.printInstructions(imemPBIWPrinter);
//    optmizer.printPatterns(pachePBIWPrinter);    
  }

  return result;
}