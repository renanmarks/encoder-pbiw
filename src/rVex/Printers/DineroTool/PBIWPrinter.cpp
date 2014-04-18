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

#include <deque>
#include "PBIWPrinter.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IPBIW.h"

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
        std::deque<PBIW::Interfaces::ILabel*> labels = instruction.getLabels();
        std::deque<PBIW::Interfaces::ILabel*>::iterator labelIt;

        for (labelIt = labels.begin(); labelIt != labels.end(); labelIt++)
        {
          printer << "#" << (*labelIt)->getName() << ":" << std::endl << "\n";
        }

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
