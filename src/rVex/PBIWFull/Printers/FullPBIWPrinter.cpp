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
 * File:   PartialPBIWPrinter.cpp
 * Author: helix
 * 
 * Created on October 30, 2011, 4:28 PM
 */

#include <list>
#include "FullPBIWPrinter.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "rVex/Base/Syllable.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

  void
  FullPBIWPrinter::printPatternsHeader() // O(1)
  {
    printer << "library ieee;\n\
use ieee.std_logic_1164.all;\n\
use ieee.std_logic_unsigned.all;\n\
use ieee.std_logic_arith.all;\n\
\n\
library work;\n\
use work.rVEX_pkg.all;\n\
\n\
entity pcache1 is\n\
\tport (\n\
\t\tAddress: in std_logic_vector(index_pcache-1 downto 0);\n\
\t\tReadPattern: out std_logic_vector(pcache_linesize-1 downto 0)\n\
\t);\n\
end entity pcache1;\n\
\n\
architecture teste of pcache1 is\n\
\ttype PatternLine is array (natural range <>) of std_logic_vector ( pcache_linesize-1 downto 0);\n\
\tconstant PatternCache : PatternLine(0 to 63) := (" << std::endl;
  }
  
  void
  FullPBIWPrinter::printPattern(const IPBIWPattern& pattern, const std::vector<unsigned int>& binary) // O(|operationCount|)
  {
    printer << "\t\t" << pattern.getAddress() << " => b\"";
    
    std::vector<unsigned int>::const_iterator it;
    
    for (it = binary.begin();
         it < binary.end();
         it++)
    {
      // Padding to the left, to read only 24 bits
      unsigned int word = (*it) << 8;
      
      for (int j = 0; j < 24; j++)
      {
        if (word & 0x80000000)
          printer << "1";
        else
          printer << "0";

        word <<= 1;
      }
    }
    
    printer << "\",\n";
  }

  void
  FullPBIWPrinter::printPatternsFooter(unsigned int patternsCount) // O(1)
  {
    if (patternsCount >= 63)
      printer << "--- WARNING: More than 64 patterns generated. Check your VHDL entity to accomplish the new address range." << std::endl;
    
    printer << "\t\tothers=>(others=>'0')\n\
\t);\n\
\n\
begin\n\
\tReadPattern <= PatternCache(conv_integer(Address));\n\
end architecture teste;\n" << std::endl;
  }
  
  void
  FullPBIWPrinter::printInstructionsHeader() // O(1)
  {
    printer << "library ieee;\n\
use ieee.std_logic_1164.all;\n\
use ieee.std_logic_arith.all;\n\
use ieee.std_logic_unsigned.all;\n\
\n\
library work;\n\
use work.rVEX_pkg.all;\n\
\n\
entity i_mem is\n\
port\n\
(\n\
\tclk\t\t: in std_logic;\n\
\treset\t\t: in std_logic;\n\
\tenable\t\t: in std_logic;\n\
\tread\t\t: in std_logic;\n\
\taddress\t\t: in std_logic_vector(7 downto 0);\n\
\tinstr\t\t: out std_logic_vector(pbiw-1 downto 0)\n\
);\n\
end i_mem;\n\
\
architecture Behav of i_mem is\n\
\n\
\ttype ROM_Array_0 is array (255 downto 0) of std_logic_vector(pbiw-1 downto 0);\n\
\n\
\tconstant Content_0: ROM_Array_0 := (" << std::endl;
  }

  void
  FullPBIWPrinter::printInstruction(const IPBIWInstruction& instruction, const std::vector<unsigned int>& binary) // O(1)
  {
    std::deque<ILabel*> labels = instruction.getLabels();
    std::deque<ILabel*>::iterator labelIt;
    
    for (labelIt = labels.begin(); labelIt != labels.end(); labelIt++)
    {
      printer << "\t\t-- " << (*labelIt)->getName() << ": " << std::endl;
    }
    
    printer << "\t\t" <<instruction.getAddress() << " => b\"";
    
    std::vector<unsigned int>::const_iterator it;
    
    for (it = binary.begin();
         it < binary.end();
         it++)
    {
      unsigned int word = *it;
      
      for (int j = 0; j < 32; j++)
      {
        if ((word & 0x80000000))
          printer << "1";
        else
          printer << "0";

        word <<= 1;
      }
    }
    
    printer << "\", -- ";
    
    
    std::list<GenericAssembly::Interfaces::IOperation*> syllablesPacked = instruction.getOperationReferences();
    std::list<GenericAssembly::Interfaces::IOperation*>::const_iterator itSyllable;
    
    for (itSyllable = syllablesPacked.begin(); itSyllable != syllablesPacked.end(); itSyllable++)
    {
      if ( !(*itSyllable)->getTextRepresentation().empty() )
        printer << (*itSyllable)->getTextRepresentation() << "; ";
    }
    
    printer << "\n";
  }
  
  void
  FullPBIWPrinter::printInstructionsFooter(unsigned int instructionsCount) // O(1)
  {
    if (instructionsCount >= 63)
      printer << "--- WARNING: More than 64 instructions generated. Check your VHDL entity to accomplish the new address range." << std::endl;
    
    printer << "\t\tOTHERS => b\"0000000000000000000000000000000000000000000000000000000000000000\"\n\
\t);\n\
\n\
begin\n\
\tprocess(clk, reset, read, address)\n\
\tbegin\n\
\t\tif ( reset = '1' ) then\n\
\t\t\tinstr <= \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\";\n\
\t\telsif ( clk'event and clk = '1' ) then\n\
\t\t\tif ( enable = '1' and read = '1' ) then\n\
\t\t\t\tinstr <= Content_0(conv_integer(address));\n\
\t\t\telse\n\
\t\t\t\tinstr <= \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\";\n\
\t\t\tend if;\n\
\t\tend if;\n\
\tend process;\n\
end Behav;\n" << std::endl;
  }
  
}
