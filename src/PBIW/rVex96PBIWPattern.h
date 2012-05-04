/* 
 * File:   PBIWPattern.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef RVEX96PBIWPATTERN_H
#define	RVEX96PBIWPATTERN_H

#include <vector>
#include "Interfaces/IPBIWPattern.h"
#include "Operation.h"

namespace PBIW
{
  using namespace Interfaces;

  /**
   * r-VEX 96 bits length pattern
   */
  class rVex96PBIWPattern : public IPBIWPattern
  {
  public:
    rVex96PBIWPattern() : usageCounter(0)
    {}
    
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
    
    virtual IOperation* operator[](const unsigned int index) const
    { return getOperation(index); }
    
    virtual bool hasControlOperation() const;
    
    virtual unsigned int getOperationCount() const
    { return operations.size(); }
    
    virtual void incrementUsageCounter()
    { usageCounter++; }
    
    virtual int getUsageCounter() const
    { return usageCounter; }
    
    virtual void resetUsageCounter()
    { usageCounter = 0; }
    
    virtual void reorganize();
    
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
    int usageCounter;
    
    virtual void exchangeOperations(int index1, int index2);
    
  };
}

#endif	/* RVEX96PBIWPATTERN_H */

