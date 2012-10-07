/* 
 * File:   pbiw_encoder.cpp
 * Author: helix
 *
 * Created on July 20, 2011, 3:15 PM
 */

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "pbiw_encoder.h"
#include "Encoder/rVexEncoder.h"

using namespace std;

void printHelp(const std::string& binaryName)
{
  std::string version = "3.0";
  
  
  typedef std::list<std::string> StringList;
  StringList archs;
  archs.push_back("rVex Processor");
  
  //--------------------
  
  std::cout << 
"PBIW Encoder - Version "<< version << "\n\
This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
---\n" 
  << std::endl;

  //--------------------
  
  std::cout << "Architectures supported in this version:" << std::endl;

  StringList::const_iterator it;
  for (it = archs.begin(); it != archs.end(); it++)
    std::cout << "  " << *it << std::endl;

  std::cout << "---\n" << std::endl;

  //--------------------
  
  std::cout << "\tUsage: " << binaryName << " [options] input.s\n" << std::endl
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
    << "-do\tEnable Dinero Tool output data" << std::endl
    << std::endl;

  return;
}

/**
 * Main function.
 */
int
main(int argc, char** argv)
{
  if (argc == 1)
    std::cout << "Please specify an input file to process." << std::endl;
  
  typedef std::list<std::string> StringList;
  StringList flags;
  
  for (int ai=1; ai < argc; ++ai) // O(|argc|)
  {
    flags.push_back(argv[ai]);
    
    if (argv[ai] == std::string("-h") || argv[ai] == std::string("--help"))
    {
      printHelp(argv[0]);
      return 0;
    } 
  }
  
  Encoder::rVexEncoder encoder(flags);
  encoder.run();

  return 0;
}
