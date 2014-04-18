/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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
Copyright (C) 2013 Renan Albuquerque Marks\n\
\n\
This program comes with ABSOLUTELY NO WARRANTY;\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions.\n\
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
    << "-c\tEnable rVex PBIW constrained encoding (Default)" << std::endl
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
