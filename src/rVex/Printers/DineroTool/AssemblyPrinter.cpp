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
#include "AssemblyPrinter.h"

namespace rVex
{
  namespace Printers
  {
    namespace DineroTool
    {
    
      AssemblyPrinter::AssemblyPrinter( std::ostream& output )  // O(1)
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
      AssemblyPrinter::printOperation(const rVex::Syllable& syllable, const std::vector<unsigned int>& binaries) // O(1)
      {
          if(syllable.getTextRepresentation() != "")
                  output << syllable.getTextRepresentation() << std::endl;
      }

      /**
      * Print the instruction.
      */
      void 
      AssemblyPrinter::printInstruction(const rVex::Instruction& instruction)
      {
        typedef std::vector<rVex::Syllable*> SyllableVec;

        SyllableVec syllables = instruction.getOrderedSyllables();// O(1)
        SyllableVec::const_iterator it;

        try 
        {
          if (instruction.haveLabel())
            output << "\t\t-- " << instruction.getLabel()->getName() << ": " << std::endl;

          output << "[I-" << instruction.getAddress() << "]" << "\n";

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
              //output << "\t\t\t";
              (*it)->print(*this, true, false);
            }
            else // ... if is in the middle, put 00 in LF bits
            {
              //output << "\t\t\t";
              (*it)->print(*this, false, false);
            }
          }

        }
        catch (rVex::Syllable::LayoutNotSupportedException e)
        {
          output << "Error printing: " << e.what() << "Opcode: " << (*it)->getOpcode() << std::endl;
        }

        output << std::endl;
      }

      /**
      * Print the file header.
      */
      void 
      AssemblyPrinter::printHeader() // O(1)
      {
        return;
      }

      /**
      * Print the file footer.
      */
      void 
      AssemblyPrinter::printFooter() // O(1)
      {
        return;
      }
    }
  }
}
