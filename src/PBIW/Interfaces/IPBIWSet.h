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
 * File:   IPBIWSet.h
 * Author: helix
 *
 * Created on October 6, 2012, 7:15 PM
 */

#ifndef IPBIWSET_H
#define	IPBIWSET_H

#include "IPBIWInstruction.h"
#include "IPBIWPattern.h"
#include "ILabel.h"
#include "IPBIWFactory.h"
#include <deque>

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWSet 
    {
    public:
      virtual ~IPBIWSet () { }
      
      virtual unsigned int getOriginalInstructionCount() const = 0;
      
      virtual std::deque<IPBIWPattern*> getPatterns() const = 0;
      virtual std::deque<IPBIWInstruction*> getInstructions() const = 0;
      virtual std::deque<ILabel*> getLabels() const = 0;
      
      virtual void printStatistics(IPBIWPrinter&) = 0;
      virtual void printInstructions(IPBIWPrinter&) = 0;
      virtual void printPatterns(IPBIWPrinter&) = 0;
    };
  }
}

#endif	/* IPBIWSET_H */

