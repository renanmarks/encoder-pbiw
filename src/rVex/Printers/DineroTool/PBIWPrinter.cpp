/* 
 * File:   PartialPBIWPrinter.cpp
 * Author: helix
 * 
 * Created on October 30, 2011, 4:28 PM
 */

#include <list>
#include "PBIWPrinter.h"
#include "src/PBIW/Interfaces/IPBIWPattern.h"
#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "src/PBIW/Interfaces/IPBIW.h"

namespace rVex
{
  namespace Printers
  {
    namespace DineroTool
    {
      using namespace PBIW::Interfaces;

      void
      PBIWPrinter::printPatternsHeader() // O(1)
      {
        printer << "No data to output to Dinero." << std::endl;
        
        return;
      }

      void
      PBIWPrinter::printPattern(const IPBIWPattern& pattern, const std::vector<unsigned int>& binary) // O(|operationCount|)
      {
        return;
      }

      void
      PBIWPrinter::printPatternsFooter(unsigned int patternsCount) // O(1)
      {
        return;
      }

      void
      PBIWPrinter::printInstructionsHeader() // O(1)
      {
        return;
      }

      void
      PBIWPrinter::printInstruction(const IPBIWInstruction& instruction, const std::vector<unsigned int>& binary) // O(1)
      {

        if (instruction.getLabel() != NULL)
          printer << "#" << instruction.getLabel()->getName() << ":" << std::endl << "\n";

        printer << "[I-" <<instruction.getAddress();

        const IPBIWPattern* p = instruction.getPattern();

        printer << " P-" << p->getAddress() << "]" << "\n";

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
      PBIWPrinter::printInstructionsFooter(unsigned int instructionsCount) // O(1)
      {
        return;
      }
    }
  }
}
