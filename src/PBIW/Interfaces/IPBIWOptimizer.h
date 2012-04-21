/* 
 * File:   IPBIWOptimizer.h
 * Author: helix
 *
 * Created on December 15, 2011, 3:41 PM
 */

#ifndef IPBIWOPTIMIZER_H
#define	IPBIWOPTIMIZER_H

#include "IPBIWInstruction.h"
#include "IPBIWPattern.h"
#include "../Label.h"

namespace PBIW
{
  namespace Interfaces 
  {
    class IPBIWOptimizer 
    {
    public:
      virtual ~IPBIWOptimizer() {}
      
      virtual void useLabels(const std::vector<Label>&) = 0;
      virtual void useInstructions(const std::vector<IPBIWInstruction*>&) = 0;
      virtual void usePatterns(const std::vector<IPBIWPattern*>&) = 0;
      
      virtual void print(IPBIWPrinter& printer) = 0;

      virtual std::vector<IPBIWPattern*> getPatterns() = 0;
      virtual std::vector<IPBIWInstruction*> getInstructions() = 0;
      
      virtual void setupOptimizer() = 0;
      
      virtual void run() = 0;
    };
  }
}

#endif	/* IPBIWOPTIMIZER_H */

