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
#include <map>
#include "pbiw_encoder.h"
#include "GenericEncoder/GenericEncoderInterface.h"
#include "rVex/Encoder/rVexEncoder.h"
#include "Sparc/pbiw/Encoder/Encoder.h"

using namespace std;

std::string version = "3.0";

void printHeader()
{
	std::cout <<
"PBIW Encoding Framework - Version "<< version << "\n\
Copyright (C) 2013-2015 Renan Albuquerque Marks\n\
\n\
This program comes with ABSOLUTELY NO WARRANTY;\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions.\n\
---\n"
	<< std::endl;
}

void printHelp(const std::string& binaryName, const std::map<std::string, PBIWFramework::GenericEncoderInterface*>& encoders)
{
    typedef std::list<std::string> StringList;
    typedef std::map<std::string, PBIWFramework::GenericEncoderInterface*> EncoderList;
    StringList archs;

    printHeader();

    std::cout << "Architectures supported in this version:" << std::endl;

    for (EncoderList::const_iterator encoder = encoders.begin(); encoder != encoders.end(); encoder++)
    {
        StringList encoderCPUS = (encoder->second)->getSupportedCPUList();

        archs.assign(encoderCPUS.begin(), encoderCPUS.end());

        for (StringList::const_iterator it = archs.begin(); it != archs.end(); it++)
            std::cout << "  " << *it << std::endl;
    }

    std::cout << "---\n" << std::endl
    << "To generate code to a specific target, use --target [name] directive." << std::endl
    << "To see extended help for each target, type --morehelp." << std::endl;

  return;
}

void printExtendedHelp(const std::string& binaryName, const PBIWFramework::GenericEncoderInterface& encoder)
{
	typedef std::list<std::string> StringList;
    StringList encoderCPUS = encoder.getSupportedCPUList();

	std::cout << "------------" << std::endl;
	std::cout << "Help for target(s): ";

    for (StringList::const_iterator it = encoderCPUS.begin(); it != encoderCPUS.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "---" << std::endl;
	std::cout << std::endl << encoder.getUsage();
	std::cout << "------------" << std::endl;

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
		flags.push_back(argv[ai]);

    rVex::Encoder::rVexEncoder rvexEncoder(flags);
    Sparc::PBIW::Encoder sparcEncoder(flags);
	std::map<std::string, PBIWFramework::GenericEncoderInterface*> codecs;

    codecs[rvexEncoder.getTargetFlag()] = &rvexEncoder;
    codecs[sparcEncoder.getTargetFlag()] = &sparcEncoder;

    bool printedHelp = false;
	StringList::const_iterator target = flags.end();
	StringList::const_iterator it;

	for (it = flags.begin(); it != flags.end(); it++) // O(|argc|)
	{
		if (*it == "-t" || *it == "--target")
		{
			target = it; target++;
		}

		if (*it == "--morehelp")
		{
			if (target != flags.end())
			{
				printExtendedHelp(argv[0], *codecs[*target]);
                printedHelp = true;
				return 0;
			}

			std::cout << "Please specify a target BEFORE the --morehelp flag." << std::endl;
			return 0;
		}

		if (*it == "-h" || *it == "--help")
		{
            printHelp(argv[0], codecs);
            printedHelp = true;
			return 0;
		}
	}

    if (it == flags.end() && target != flags.end())
		codecs[*target]->run();

  return 0;
}
