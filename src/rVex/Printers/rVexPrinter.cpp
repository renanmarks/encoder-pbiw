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
 * File:   rVexPrinter.cpp
 * Author: helix
 * 
 * Created on October 6, 2011, 3:41 PM
 */

#include <vector>
#include <ostream>
#include "rVexPrinter.h"

namespace rVex
{
  namespace Printers
  {
    /**
     * Prints a unsigned integer into a binary string containing 0's and 1's.
     * @param The syllable
     * @param An int containing binary digits of the syllable
     * @param If it is the first syllable
     * @param If it is the last syllable
     */
      
    rVexPrinter::rVexPrinter( std::ostream& output )  // O(1)
      : output(output) 
    { 

    }
    
    void 
    rVexPrinter::printOperation(const rVex::Base::Syllable& syllable, const std::vector<unsigned int>& binaries) // O(1)
    {
      std::string resultBinary;
      std::vector<unsigned int>::const_iterator it;
      
      output << "\t(S: " << syllable.getAddress() << ") ";
      
      for (it = binaries.begin(); it < binaries.end(); it++)
      {
        unsigned int temp = *it;

        for (unsigned char counter=0; counter < 32; temp <<= 1, counter++)
        {
          if (temp & 0x80000000)
            resultBinary.append("1");
          else
            resultBinary.append("0");
        }
        
        output << resultBinary;
      }
    }

    /**
     * Print the instruction.
     */
    void 
    rVexPrinter::printInstruction(const rVex::Base::Instruction& instruction) // O(1)
    {
      rVex::Base::Instruction::SyllableCollection syllables = instruction.getSyllables();
      rVex::Base::Instruction::SyllableCollection::const_iterator it;
      
      output << "[I: " << instruction.getAddress() << "] ["<< instruction.getWordAddress() << "]" << std::endl;
      
      try 
      {
      
        for ( it = syllables.begin(); it != syllables.end(); it++) // O(1)
        {
          // If the current is the first put 01 in LF...
          if (it == syllables.begin()) 
            (*it)->print(*this, true, false); // O(1)

          // ... if the current is the last put 10 in LF ...
          else if (it+1 == syllables.end()) 
            (*it)->print(*this, false, true); // O(1)

          else // ... if is in the middle, put 00 in LF bits
            (*it)->print(*this, false, false); // O(1)
          
          output << " -- " << (*it)->getTextRepresentation() << std::endl;
        }
      
        instruction.printSyllableDependencies(*this);
      }
      catch (rVex::Base::Syllable::LayoutNotSupportedException* e)
      {
        output << "Error printing: " << e->what() << "Opcode: " << (*it)->getOpcode() << std::endl; // O(1)
      }
      
      output << std::endl;
    }

    /**
     * Print the file header.
     */
    void 
    rVexPrinter::printHeader() // O(1)
    {
      output << ">>>>>> Begin of Instructions >>>>>>" << std::endl;
    }

    /**
     * Print the file footer.
     */
     void 
    rVexPrinter::printFooter() // O(1)
    {
      output << "<<<<<< End of Instructions <<<<<<" << std::endl;
    }
  }
}
