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
     * @param An integer
     * @param If it is the first syllable
     * @param If it is the last syllable
     * @return A std::string containing binary digits
     */
    void 
    rVexPrinter::printSyllable(const rVex::Syllable* syllable, unsigned int binary, bool first, bool last)
    {
      std::string resultBinary;
      unsigned int temp = binary;

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
        resultBinary.append("1");
      else
        resultBinary.append("0");

      output << "\t(S: " << syllable->getAddress() << ") " << resultBinary << std::endl;
    }

    /**
     * Print the instruction.
     */
    void 
    rVexPrinter::printInstruction(const rVex::Instruction& instruction)
    {
      typedef std::vector<rVex::Syllable*> SyllableVec;
      
      SyllableVec syllables = instruction.getSyllables();
      SyllableVec::const_iterator it;
      
      output << "[I: " << instruction.getAddress() << "]";
      
      try 
      {
      
        for ( it = syllables.begin(); it < syllables.end(); it++)
        {
          // If the current is the first put 01 in LF...
          if (it == syllables.begin()) 
            (*it)->print(*this, true, false);

          // ... if the current is the last put 10 in LF ...
          else if (it+1 == syllables.end()) 
            (*it)->print(*this, false, true);

          else // ... if is in the middle, put 00 in LF bits
            (*it)->print(*this, false, false);
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
    rVexPrinter::printHeader()
    {
      output << ">>>>>> VHDL Header >>>>>>" << std::endl;
    }

    /**
     * Print the file footer.
     */
     void 
    rVexPrinter::printFooter()
    {
      output << "<<<<<< VHDL Footer <<<<<<" << std::endl;
    }
  }
}
