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
 * File:   Encoder.cpp
 * Author: helix
 * 
 * Created on October 6, 2012, 10:50 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "rVexEncoder.h"

#include "rVex/Parser/driver.h"
#include "rVex/Parser/VexContext.h"
#include "rVex/Printers/rVexPrinter.h"
#include "rVex/Printers/VHDLPrinter.h"

#include "rVex/PBIWPartial/PartialPBIW.h"
#include "rVex/PBIWPartial/Printers/PartialPBIWPrinter.h"
#include "rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.h"

#include "rVex/PBIWFull/FullPBIW.h"
#include "rVex/PBIWFull/Printers/FullPBIWPrinter.h"
#include "rVex/PBIWFull/Printers/FullPBIWDebugPrinter.h"

#include "rVex/Parser/VexTypes.h"
#include "PBIW/BaseOptimizer.h"
#include "PBIW/PBIWOptimizerJoinPatterns.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "rVex/Printers/DineroTool/PBIWPrinter.h"
#include "rVex/Printers/DineroTool/AssemblyPrinter.h"

namespace rVex
{
	namespace Encoder
	{
		rVexEncoder::rVexEncoder(const std::list<std::string>& inputFlags)
			: flagList(inputFlags), patternSetOptimizer(8, 12, 16)
		{
			std::list<std::string>::const_iterator it;
			std::string flags;

			for (it = inputFlags.begin(); it != inputFlags.end(); it++)
			{
				flags += *it;
				flags += " ";

				if (*it == "-p")
				{
					config[Config::TraceParsing] = true;
					std::cout << "Info: Parser debug printing enabled." << std::endl;
				}
				else if (*it == "-s")
				{
					config[Config::TraceScanning] = true;
					std::cout << "Info: Lexer debug printing enabled." << std::endl;
				}
				else if (*it == "-d")
				{
					config[Config::DebugMode] = true;
					std::cout << "Info: Debug information printing enabled." << std::endl;
				}
				else if (*it == "-do")
				{
					config[Config::PrintDineroData] = true;
					std::cout << "Info: Dinero Tool output data enabled." << std::endl;
				}
				else if (*it == "-c")
				{
					algorithm = Algorithm::Constrained;
					std::cout << "Info: Constrained PBIW encoding enabled." << std::endl;
				}
				else if (*it == "-uc")
				{
					algorithm = Algorithm::Unconstrained;
					std::cout << "Info: Unconstrained PBIW encoding enabled." << std::endl;
				}
				else if (*it == "-O")
				{
					optimizations[Optimization::PatternJoin] = true;
					std::cout << "Info: PBIW Pattern Join optimization enabled." << std::endl;
				}
				else if (*it == "-i")// The filenames to assembly and codify!
				{
					std::list<std::string>::const_iterator nameIt = it; nameIt++;
					inputFilenames.push_back(*nameIt);
				}
			}

			flagString = flags;
		}

		rVexEncoder::~rVexEncoder()
		{
			std::vector<VexParser::VexOpcode>::iterator it;

			for (it=operationTable.begin(); it < operationTable.end(); it++)
			{
				// Clean the memory
				if (it->syllableConstructor != NULL)
					delete it->syllableConstructor;
			}
		}

		void rVexEncoder::processPBIW(const std::string& filename, VexParser::VexContext& context)
		{
			if (algorithm == Algorithm::Unconstrained)
				encodeFullPBIW(filename, context);
			else
				encodePartialPBIW(filename, context);
		}

		void rVexEncoder::run()
		{
			std::list<std::string>::const_iterator it;

			for(it = inputFilenames.begin(); it != inputFilenames.end(); it++)
			{
				VexParser::VexContext context;
				assemble(*it, context);
				processPBIW(*it,context);
			}

			if (inputFilenames.size() > 1)
			{
				patternSetOptimizer.minimumPatterns();
				patternSetOptimizer.printStatistics();
			}
		}

		std::list<std::string> rVexEncoder::getSupportedCPUList() const
		{
			std::list<std::string> cpus;

			cpus.push_back(getTargetFlag() + " (rVex Processor)");

			return cpus;
		}

		std::string rVexEncoder::getUsage() const
		{
			std::stringstream ss;

			ss << "  Usage: " << " [options] -i input.s\n" << std::endl
				 << "  This will generate 3 files:" << std::endl
				 << "  - input.s.vhd: Contains the binary VHDL assembly to run in rVex;" << std::endl
				 << "  - input.s.pbiw.vhd: Contains the PBIW instructions binary VHDL assembly to run in rVex;" << std::endl
				 << "  - input.s.pcache.vhd: Contains the PBIW patterns binary VHDL assembly to run in rVex;\n" << std::endl;

			ss << "  Options:" << std::endl
				 << "  -p\tTrace parsing" << std::endl
				 << "  -s\tTrace scanning" << std::endl
				 << "  -O\tEnable PBIW optimization" << std::endl
				 << "  -c\tEnable rVex PBIW constrained encoding (Default)" << std::endl
				 << "  -uc\tEnable rVex PBIW unconstrained encoding" << std::endl
				 << "  -do\tEnable Dinero Tool output data" << std::endl;

			return ss.str();
		}

		std::string rVexEncoder::getTargetFlag() const
		{
			return "rvex";
		}

		/**
	 * Parses, processes and assembles the rVex assembly file(s).
	 */
		void rVexEncoder::assemble(const std::string& filename, VexParser::VexContext& context)
		{
			const bool debugEnabled = config[Config::DebugMode];
			const bool traceParsing = config[Config::TraceParsing];
			const bool traceScanning = config[Config::TraceScanning];
			const bool printDineroData = config[Config::PrintDineroData];

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

				return;
			}

			if (printDineroData)
			{
				std::string outputFilename = filename;
				outputFilename+=".dinero";

				std::ofstream dineroFile(outputFilename.c_str());

				rVex::Printers::DineroTool::AssemblyPrinter printer(dineroFile);
				context.print(printer); // O(|instructions|)

				return;
			}

			std::string outputFilename=filename;
			outputFilename+=".vhd";

			// Assembler VHDL printer
			std::ofstream assembledFile(outputFilename.c_str());
			rVex::Printers::VHDLPrinter vhdlPrinter(assembledFile);

			std::cout << "Assembled file: " << outputFilename << std::endl;

			vhdlPrinter.setFileName(filename);
			vhdlPrinter.setAssemblerFlags(flagString);

			context.print(vhdlPrinter); // O(|instructions|)
		}

		void rVexEncoder::encodeAlgorithm(PBIW::Interfaces::IPBIWPrinter& instructionPrinter,
																			PBIW::Interfaces::IPBIWPrinter& patternPrinter,
																			PBIW::Interfaces::IPBIWPrinter& statisticPrinter,
																			PBIW::Interfaces::IPBIW& pbiwContext,
																			VexParser::VexContext& context)
		{
			pbiwContext.setDebug(context.isDebuggingEnabled());

			// UNLEASH THE PBIW ENCODER!
			pbiwContext.encode(context.getInstructions());

			// By default, the context will be printed and optimized...
			PBIW::Interfaces::IPBIWSet* pbiwSetAlias = &pbiwContext;

			PBIW::PBIWOptimizerJoinPatterns patternJoinOptimizer;

			if (optimizations[Optimization::PatternJoin])
			{
				// ... UNLESS we use the optimizer!
				pbiwSetAlias = &patternJoinOptimizer;

				pbiwContext.registerOptimizer(patternJoinOptimizer);
				pbiwContext.runOptimizers();

				std::cout << " --- Optimizer debug information ---" << std::endl;
			}

			pbiwSetAlias->printInstructions(instructionPrinter);
			pbiwSetAlias->printPatterns(patternPrinter);
			pbiwSetAlias->printStatistics(statisticPrinter);

			patternSetOptimizer.addPatternSet(pbiwSetAlias->getPatterns(), pbiwSetAlias->getInstructions().size(), context.getInstructions().size());

			return;
		}

		/**
	 * Template function to be the framework of PBIW encoder execution
	 * for the rVex processor.
	 */
		template <class TPBIWPrinter>
		void
		rVexEncoder::encodePBIW(const std::string& filename, PBIW::Interfaces::IPBIW& pbiwContext, VexParser::VexContext& context)
		{
			if (context.isDebuggingEnabled())
			{
				TPBIWPrinter printer(std::cout);

				encodeAlgorithm(printer, printer, printer, pbiwContext, context);

				return;
			}

			// Create the output filenames
			std::string imemFilename = filename;
			std::string pcacheFilename = filename;

			imemFilename += ".pbiw.vhd";
			pcacheFilename += ".pcache.vhd";

			if (config[Config::PrintDineroData])
			{
				imemFilename = filename;
				pcacheFilename = filename;

				imemFilename += ".dinero.pbiw";
				pcacheFilename += ".dinero.pcache";
			}

			std::cout << "PBIW instructions file: " << imemFilename << std::endl
								<< "PBIW patterns file: " << pcacheFilename << std::endl
								<< std::endl;

			// Create the files
			std::ofstream imemFile(imemFilename.c_str());
			std::ofstream pcacheFile(pcacheFilename.c_str());

			TPBIWPrinter pbiwInstructionPrinter(imemFile);
			TPBIWPrinter pbiwPatternPrinter(pcacheFile);
			TPBIWPrinter pbiwStatisticsPrinter(std::cout);

			encodeAlgorithm(pbiwInstructionPrinter, pbiwPatternPrinter, pbiwStatisticsPrinter, pbiwContext, context);

			return;
		}

		/**
		* The function used to call the Partial PBIW encode scheme on the
		* rVex assembly context.
		*/
		void rVexEncoder::encodePartialPBIW(const std::string& filename, VexParser::VexContext& context)
		{
			PBIWPartial::PartialPBIW pbiwContext;

			if (config[Config::PrintDineroData])
			{
				encodePBIW<rVex::Printers::DineroTool::PBIWPrinter>(filename, pbiwContext, context);
				return;
			}

			if (context.isDebuggingEnabled())
				encodePBIW<PBIWPartial::PartialPBIWDebugPrinter>(filename, pbiwContext, context);
			else
				encodePBIW<PBIWPartial::PartialPBIWPrinter>(filename, pbiwContext, context);

			return;
		}

		/**
		* The function used to call the Full PBIW encode scheme on the
		* rVex assembly context.
		*/
		void rVexEncoder::encodeFullPBIW(const std::string& filename, VexParser::VexContext& context)
		{
			PBIWFull::FullPBIW pbiwContext;

			if (config[Config::PrintDineroData])
			{
				encodePBIW<rVex::Printers::DineroTool::PBIWPrinter>(filename, pbiwContext, context);
				return;
			}

			if (context.isDebuggingEnabled())
				encodePBIW<PBIWFull::FullPBIWDebugPrinter>(filename, pbiwContext, context);
			else
				encodePBIW<PBIWFull::FullPBIWPrinter>(filename, pbiwContext, context);

			return;
		}
	}
}
