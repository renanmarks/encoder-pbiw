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
    rVex96PBIWPattern();
    rVex96PBIWPattern(const rVex96PBIWPattern& orig);
    virtual ~rVex96PBIWPattern();

    virtual void addOperation(IOperation*);
    
    virtual IOperation* getOperation(unsigned int index) const
    { return operations[index]; }
    
    virtual IOperation* operator[](const unsigned int index) const
    { return getOperation(index); }
    
    virtual unsigned int getOperationCount() const
    { return operations.size(); }
    
    virtual void incrementUsageCounter()
    { usageCounter++; }
    
    virtual int getUsageCounter() const
    { return usageCounter; }
    
    virtual void reorganize(IPBIWInstruction*& instruction);
    
    virtual void print(IPBIWPrinter&) const;
    
    virtual unsigned int getValueByIndex(IPBIWInstruction*& instruction, unsigned int index);
    
    virtual bool operator<(const IPBIWPattern&) const;
    virtual bool operator>(const IPBIWPattern&) const;
    virtual bool operator<=(const IPBIWPattern&) const;
    virtual bool operator>=(const IPBIWPattern&) const;

    virtual bool operator==(const IPBIWPattern&) const;
    virtual bool operator!=(const IPBIWPattern&) const;
    
    virtual void exchangeOperations(int index1, int index2);

  private:
    OperationVector operations; // Max 4
    int usageCounter;
    
  };
}

#endif	/* RVEX96PBIWPATTERN_H */

