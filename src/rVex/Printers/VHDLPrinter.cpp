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
 * File:   VHDLPrinter.cpp
 * Author: helix
 * 
 * Created on October 11, 2011, 3:04 PM
 */

#include <vector>
#include <iomanip>
#include <ostream>

#include <ctime>
#include "VHDLPrinter.h"

namespace rVex
{
  namespace Printers
  {
    
    VHDLPrinter::VHDLPrinter( std::ostream& output )  // O(1)
      : output(output) 
    { 
      struct tm tim;
      time_t now;
      char buffer [255];

      now = std::time(NULL);
      tim = *(std::localtime(&now));
      strftime(buffer, 30, "%b %d, %Y @ %H:%M:%S\n", &tim);
      
      this->date = buffer;
    }
    
    /**
     * Prints a unsigned integer into a binary string containing 0's and 1's.
     * @param An integer
     * @param If it is the first syllable
     * @param If it is the last syllable
     * @return A std::string containing binary digits
     */
    void 
    VHDLPrinter::printOperation(const rVex::Base::Syllable& syllable, const std::vector<unsigned int>& binaries) // O(1)
    {
      std::string resultBinary;
      std::vector<unsigned int>::const_iterator it;
      
      for (it = binaries.begin(); it < binaries.end(); it++)
      {
        unsigned int temp = *it;

        output << "b\"";

        for (unsigned char counter=0; counter < 32; temp <<= 1, counter++)
        {
          if (temp & 0x80000000)
          {
            if (counter == 31)
              resultBinary.append("1\",");
            else
              resultBinary.append("1");
          }
          else
          {
            if (counter == 31)
              resultBinary.append("0\"&");
            else
              resultBinary.append("0");
          }
        }

        output << resultBinary 
          << " -- " << syllable.getTextRepresentation()
          << std::endl;
      }
    }

    /**
     * Print the instruction.
     */
    void 
    VHDLPrinter::printInstruction(const rVex::Base::Instruction& instruction)
    {
      rVex::Base::Instruction::SyllableCollection syllables = instruction.getOrderedSyllables();// O(1)
      rVex::Base::Instruction::SyllableCollection::const_iterator it;
      
      try 
      {
        std::deque<ILabel*> labels = instruction.getLabels();
        std::deque<ILabel*>::iterator labelIt;

        for (labelIt = labels.begin(); labelIt != labels.end(); labelIt++)
        {
          output << "\t\t-- " << (*labelIt)->getName() << ":" << std::endl;
        }

        output << "\t\t" << instruction.getAddress() << " =>\t";
        
        for ( it = syllables.begin(); it < syllables.end(); it++)  // O(|syllables|) = O(4) = O(1)
        {
          // If the current is the LAST put 10 in LF...
          if (it == syllables.begin())
          {
            (*it)->print(*this, false, true);
          }
          // ... if the current is the FIRST put 01 in LF ...
          else if (it+1 == syllables.end()) 
          {
            output << "\t\t\t";
            (*it)->print(*this, true, false);
          }
          else // ... if is in the middle, put 00 in LF bits
          {
            output << "\t\t\t";
            (*it)->print(*this, false, false);
          }
        }
      
      }
      catch (rVex::Base::Syllable::LayoutNotSupportedException* e)
      {
        output << "Error printing: " << e->what() << "Opcode: " << (*it)->getOpcode() << std::endl;
      }
      
      output << std::endl;
    }

    /**
     * Print the file header.
     */
    void 
    VHDLPrinter::printHeader() // O(1)
    {
      output << "\
--------------------------------------------------------------------------------\n\
-- r-VEX | Instruction ROM\n\
--------------------------------------------------------------------------------\n\
-- \n\
-- This file was assembled by PBIWAssembler, the Pattern Based Instruction\n\
-- Word instruction ROM generator for the r-VEX processor./\n\
-- \n\
--     source file: " << this->filename << "\n\
--     r-ASM flags: " << this->flags << "\n\
--     date & time: " << this->date <<"\
-- \n\
-- r-VEX is\n\
-- Copyright (c) 2008, Thijs van As <t.vanas@gmail.com>\n\
-- \n\
-- PBIWAssembler is free software: you can redistribute it and/or modify\n\
-- it under the terms of the GNU General Public License as published by\n\
-- the Free Software Foundation, either version 3 of the License, or\n\
-- (at your option) any later version.\n\
-- \n\
-- This program is distributed in the hope that it will be useful,\n\
-- but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
-- GNU General Public License for more details.\n\
-- \n\
-- You should have received a copy of the GNU General Public License\n\
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.\n\
-- \n\
--------------------------------------------------------------------------------\n\
-- " << this->filename << " (generated by PBIWAssembler)\n\
--------------------------------------------------------------------------------\n\
\n\
library ieee;\n\
use ieee.std_logic_1164.all;\n\
use ieee.std_logic_arith.all;\n\
use ieee.std_logic_unsigned.all;\n\
\n\
entity i_mem is\n\
port(	clk   : in std_logic;\n\
\treset	: in std_logic;\n\
\tenable	: in std_logic;\n\
\tread	: in std_logic;\n\
\taddress	: in std_logic_vector(7 downto 0);\n\
\tinstr: out std_logic_vector(127 downto 0)\n\
);\n\
end i_mem;\n\
\n\
--------------------------------------------------------------\n\
\n\
architecture Behav of i_mem is\n\
\ttype ROM_Array_0 is array (63 downto 0)\n\
\tof std_logic_vector(127 downto 0);\n\
\n\
\tconstant Content_0: ROM_Array_0 := (\n"
        << std::endl;
    }

    /**
     * Print the file footer.
     */
     void 
    VHDLPrinter::printFooter() // O(1)
    {
      output << 
"\t\tOTHERS => b\"00000000000000000000000000000010\"& -- \n\
\t\t\tb\"00000000000000000000000000000000\"& -- \n\
\t\t\tb\"00000000000000000000000000000000\"& -- \n\
\t\t\tb\"00111110000000000000000000000001\" -- stop\n\
);\n\
\n\
begin\n\
\tprocess(clk, reset, read, address)\n\
\tbegin\n\
\t\tif( reset = '1' ) then\n\
\t\t\tinstr <= \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\";\n\
\t\telsif( clk'event and clk = '1' ) then\n\
\t\t\tif( read = '1' and enable = '1'  ) then\n\
\t\t\t\tinstr <= Content_0(conv_integer(address));\n\
\t\t\telse\n\
\t\t\t\tinstr <= \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\";\n\
\t\t\tend if;\n\
\t\tend if;\n\
\tend process;\n\
end Behav;" 
        << std::endl;
    }
  }
}
