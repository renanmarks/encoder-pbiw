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

int
main( int argc, char** argv )
{
//  rVex::Printers::rVexPrinter printer(std::cout);
  rVex::Printers::VHDLPrinter printer(std::cout);
  VexParser::VexContext context(printer);
  VexParser::Driver driver(context);
  std::string flags;
  bool result = false;
  
  for (int ai=1; ai < argc; ++ai)
  {
    if (argv[ai] == std::string("-h") || argv[ai] == std::string("--help"))
    {
      std::cout << "rVex Assembler" << std::endl
        << "--------------" << std::endl
        << "Options:" << std::endl
        << "-p\tTrace parsing" << std::endl
        << "-s\tTrace scanning" << std::endl
        << "-d\tEnable verbose debug" << std::endl
        << std::endl;
      
      return 0;
    }
    else if (argv[ai] == std::string("-p"))
    {
      flags.append("-p ");
      driver.trace_parsing=true;
    } 
    else if (argv[ai] == std::string("-s"))
    {
      flags.append("-s ");
      driver.trace_scanning=true;
    } 
    else if (argv[ai] == std::string("-d"))
    {
      flags.append("-d ");
      // Lets be verbose! :)
      context.enableDebugging(true);
    }
    else
    {
      // read a file with expressions
      std::fstream infile(argv[ai]);
      
      std::string filename = argv[ai];
      printer.setFileName(filename);
      printer.setAssemblerFlags(flags);
      
      if (!infile.good())
      {
        std::cerr << "Could not open file: " << argv[ai] << std::endl;
        return 0;
      }

      result = driver.parse_stream(infile, argv[ai]);
      
      context.processLabels();
      context.print();
    }
  }
  
  return result ? 0 : 1;
}
