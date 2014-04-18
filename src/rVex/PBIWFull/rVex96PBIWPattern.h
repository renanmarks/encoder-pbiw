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
 * File:   PBIWPattern.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef PBIWFULL_RVEX96PBIWPATTERN_H
#define	PBIWFULL_RVEX96PBIWPATTERN_H

#include <deque>
#include <vector>
#include <set>
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "Operation.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

  /**
   * r-VEX 96 bits length pattern
   */
  class rVex96PBIWPattern : public IPBIWPattern
  {
  public:
    rVex96PBIWPattern() {}
    
    rVex96PBIWPattern(const rVex96PBIWPattern&);
    
    virtual ~rVex96PBIWPattern();

    virtual IPBIWPattern* clone() const;
    
    virtual void setAddress(unsigned int addr)
    { address = addr; }
        
    virtual unsigned int getAddress() const
    { return address; }
    
    virtual void addOperation(IOperation*);
    
    virtual void removeLastAddedOperation()
    { operations.pop_back(); }
    
    virtual OperationVector getOperations() const
    { return operations; }
    
    virtual IOperation* getOperation(unsigned int index) const
    { return operations[index]; }
    
    virtual void setOperation(IOperation& operation, int index)
    {  
      delete this->operations[index];
      this->operations[index] = operation.clone();
    }
    
    virtual IOperation* operator[](const unsigned int index) const
    { return getOperation(index); }
    
    virtual bool hasControlOperation() const;
    
    virtual unsigned int getOperationCount() const
    { return operations.size(); }
    
    virtual void referencedByInstruction(IPBIWInstruction* instructionPointed);
    
    virtual std::deque<IPBIWInstruction*> getInstructionsThatUseIt()
    {   return std::deque<IPBIWInstruction*>(instructionsThatUseIt.begin(), instructionsThatUseIt.end());   }
    
    virtual int getUsageCounter() const
    { return instructionsThatUseIt.size(); }
    
    virtual void resetUsageCounter()
    { instructionsThatUseIt.clear(); }
    
    virtual void reorganize();
    virtual void reorganize(bool updateInstructionAnnulationBits);

    virtual void print(IPBIWPrinter&) const;
    
    virtual void updateIndexes(int oldIndex, int newIndex);
    
    virtual bool operator<(const IPBIWPattern&) const;
    virtual bool operator>(const IPBIWPattern&) const;
    virtual bool operator<=(const IPBIWPattern&) const;
    virtual bool operator>=(const IPBIWPattern&) const;

    virtual bool operator==(const IPBIWPattern&) const;
    virtual bool operator!=(const IPBIWPattern&) const;

  private:
    unsigned int address;
    
    OperationVector operations; // Max 4
    
    typedef std::set<IPBIWInstruction*> InstructionsThatUseIt;
    InstructionsThatUseIt instructionsThatUseIt;
    
    /**
     * Used to exchange operations of patterns referents to the instructions without annulation bits
     * @param index1
     * @param index2
     */
    virtual void exchangeOperations(int index1, int index2, bool updateInstructionAnnulationBits);
        
  };
}

#endif	/* RVEX96PBIWPATTERN_H */

