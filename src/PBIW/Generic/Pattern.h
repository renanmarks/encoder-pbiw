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
 * File:   Pattern.h
 * Author: helix
 *
 * Created on July 23, 2012, 3:22 PM
 */

#ifndef PBIW_GENERIC_PATTERN_H
#define	PBIW_GENERIC_PATTERN_H

#include "PBIW/Interfaces/IPBIWPattern.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    /**
     * Generic, flexible PBIW pattern for use in the generic PBIW encoding
     * algorithm.
     */
    class Pattern : public IPBIWPattern
    {
    public:
      Pattern();
      Pattern(const Pattern& orig);
      virtual ~Pattern();
      
      virtual IPBIWPattern* clone() const;

      virtual void setAddress(unsigned int);
      virtual unsigned int getAddress() const;

      virtual void addOperation(IOperation*);

      virtual IPBIWPattern::OperationVector getOperations() const;
      virtual IOperation* getOperation(unsigned int) const;
      virtual void setOperation(IOperation&, int);
      virtual IOperation* operator[](const unsigned int) const;

      virtual bool hasControlOperation() const;

      virtual unsigned int getOperationCount() const;

      virtual void updateIndexes(int oldIndex, int newIndex);

      virtual void referencedByInstruction(IPBIWInstruction*);

      virtual std::deque<IPBIWInstruction*> getInstructionsThatUseIt();

      virtual void reorganize();
      virtual void reorganize(bool);

      virtual int getUsageCounter() const;

      virtual void resetUsageCounter();

      virtual void print(IPBIWPrinter&) const;

      virtual bool operator<(const IPBIWPattern&) const;
      virtual bool operator>(const IPBIWPattern&) const;
      virtual bool operator<=(const IPBIWPattern&) const;
      virtual bool operator>=(const IPBIWPattern&) const;

      virtual bool operator==(const IPBIWPattern&) const;
      virtual bool operator!=(const IPBIWPattern&) const;
        
    private:

    };
  }
}

#endif	/* PATTERN_H */

