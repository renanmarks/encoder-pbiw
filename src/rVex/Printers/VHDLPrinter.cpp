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
    
    VHDLPrinter::VHDLPrinter( std::ostream& output ) 
      : output(output) 
    { 
      size_t i;
      struct tm tim;
      time_t now;
      char buffer [255];

      now = std::time(NULL);
      tim = *(std::localtime(&now));
      i = strftime(buffer, 30, "%b %d, %Y @ %H:%M:%S\n", &tim);
      
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
    VHDLPrinter::printSyllable(const rVex::Syllable* syllable, unsigned int binary, bool first, bool last)
    {
      std::string resultBinary;
      unsigned int temp = binary;
      
      output << "\"";
      
      for (unsigned char counter=0; counter < 30; temp <<= 1, counter++)
      {
        if (temp & 0x80000000)
          resultBinary.append("1");
        else
          resultBinary.append("0");
      }

      if (last)
        resultBinary.append("1");
      else
        resultBinary.append("0");

      if (first)
        resultBinary.append("1\";");
      else
        resultBinary.append("0\"&");
      
      output << resultBinary << std::endl;
    }

    /**
     * Print the instruction.
     */
    void 
    VHDLPrinter::printInstruction(const rVex::Instruction& instruction)
    {
      typedef std::vector<rVex::Syllable*> SyllableVec;
      
      SyllableVec syllables = instruction.getSyllables();
      SyllableVec::const_reverse_iterator it;
      
      try 
      {
        output << "\t\t\t\twhen x\"" 
          << std::setw(2) << std::setfill('0') << std::hex << std::uppercase
          << instruction.getAddress() << "\" => instr <= ";
        
        for ( it = syllables.rbegin(); it < syllables.rend(); it++)
        {
          // If the current is the LAST put 10 in LF...
          if (it == syllables.rbegin())
          {
            (*it)->print(*this, false, true);
          }
          // ... if the current is the FIRST put 01 in LF ...
          else if (it+1 == syllables.rend()) 
          {
            output << "\t\t\t\t\t\t\t";
            (*it)->print(*this, true, false);
          }
          else // ... if is in the middle, put 00 in LF bits
          {
            output << "\t\t\t\t\t\t\t";
            (*it)->print(*this, false, false);
          }
        }
      
      }
      catch (rVex::Syllable::LayoutNotSupportedException* e)
      {
        output << "Error printing: " << e->what() << "Opcode: " << (*it)->getOpcode() << std::endl;
      }
      
      output << std::endl;
    }

    /**
     * Print the file header.
     */
    void 
    VHDLPrinter::printHeader()
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
-- PBIWAssembler is free hardware: you can redistribute it and/or modify\n\
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
\n\
entity i_mem is\n\
\tport ( reset   : in std_logic;                        -- system reset\n\
\t       address : in std_logic_vector(7 downto 0);     -- address of instruction to be read\n\
\n\
\t       instr   : out std_logic_vector(127 downto 0)); -- instruction (4 syllables)\n\
end entity i_mem;\n\
\n\
\n\
architecture behavioural of i_mem is\n\
begin\n\
\tmemory : process(address, reset)\n\
\tbegin\n\
\t\tif (reset = '1') then\n\
\t\t\tinstr <= x\"00000000000000000000000000000000\";\n\
\t\telse\n\
\t\t\tcase address is\n"
        << std::endl;
    }

    /**
     * Print the file footer.
     */
     void 
    VHDLPrinter::printFooter()
    {
      output << "\
\t\t\t\twhen others => instr <= \"00000000000000000000000000000010\"& -- nop\n\
\t\t\t\t                        \"00000000000000000000000000000000\"& -- nop\n\
\t\t\t\t                        \"00000000000000000000000000000000\"& -- nop\n\
\t\t\t\t                        \"00111110000000000000000000000001\"; -- stop\n\
\t\t\tend case;\n\
\t\tend if;\n\
\tend process memory;\n\
end architecture behavioural;\n\n" 
        << std::endl;
    }
  }
}