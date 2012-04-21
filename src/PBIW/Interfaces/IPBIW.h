/* 
 * File:   IPBIW.h
 * Author: helix
 *
 * Created on July 21, 2011, 2:36 PM
 */

#ifndef IPBIW_H
#define	IPBIW_H

#include <ostream>
#include <vector>
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
        
        virtual void encode(const std::vector<rVex::Instruction*>&) = 0;
        virtual void decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&) = 0;
        
        virtual void registerOptimizer(IPBIWOptimizer&) = 0;
        virtual void runOptimizers() = 0;
        
        virtual void printStatistics(IPBIWPrinter&) = 0;
        virtual void printInstructions(IPBIWPrinter&) = 0;
        virtual void printPatterns(IPBIWPrinter&) = 0;

        virtual std::vector<IPBIWPattern*> getPatterns() = 0;
        virtual std::vector<IPBIWInstruction*> getInstructions() = 0;
        virtual std::vector<ILabel*> getLabels() = 0;
    };
  }
}

#endif	/* IPBIW_H */

