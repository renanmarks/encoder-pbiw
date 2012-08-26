/* 
 * File:   IPBIW.h
 * Author: helix
 *
 * Created on July 21, 2011, 2:36 PM
 */

#ifndef IPBIW_H
#define	IPBIW_H

#include <ostream>
#include <deque>
#include "src/rVex/Instruction.h"
#include "IPBIWInstruction.h"
#include "IPBIWPattern.h"
#include "IPBIWPrinter.h"
#include "IPBIWOptimizer.h"

namespace PBIW
{
  namespace Interfaces
  {   
    /**
     * PBIW codec interface
     */
    class IPBIW
    {
      public:
        virtual ~IPBIW() {}
        
        virtual void setDebug(bool) = 0;
        virtual bool isDebug() const = 0;
        
        virtual void encode(const std::deque<GenericAssembly::Interfaces::IInstruction*>&) = 0;
        virtual void decode(const std::deque<IPBIWInstruction*>&, const std::deque<IPBIWPattern*>&) = 0;
        
        virtual void registerOptimizer(IPBIWOptimizer&) = 0;
        virtual void runOptimizers() = 0;
        
        virtual void printStatistics(IPBIWPrinter&) = 0;
        virtual void printInstructions(IPBIWPrinter&) = 0;
        virtual void printPatterns(IPBIWPrinter&) = 0;

        virtual std::deque<IPBIWPattern*> getPatterns() = 0;
        virtual std::deque<IPBIWInstruction*> getInstructions() = 0;
        virtual std::deque<ILabel*> getLabels() = 0;
    };
  }
}

#endif	/* IPBIW_H */

