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

