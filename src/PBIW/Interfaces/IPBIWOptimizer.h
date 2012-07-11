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
#include "ILabel.h"
#include "IPBIWFactory.h"

namespace PBIW
{
  namespace Interfaces 
  {
    class IPBIWOptimizer 
    {
    public:
      virtual ~IPBIWOptimizer() {}
      
      virtual void useLabels(const std::vector<ILabel*>&) = 0;
      virtual void useInstructions(const std::vector<IPBIWInstruction*>&) = 0;
      virtual void usePatterns(const std::vector<IPBIWPattern*>&) = 0;
      
      virtual void printStatistics(IPBIWPrinter&, int , int, int) = 0;
      virtual void printInstructions(IPBIWPrinter&) = 0;
      virtual void printPatterns(IPBIWPrinter&) = 0;

      virtual std::vector<IPBIWPattern*> getPatterns() const = 0;
      virtual std::vector<IPBIWInstruction*> getInstructions() const = 0;
      virtual std::vector<ILabel*> getLabels() const = 0;
      
      virtual void setupOptimizer() = 0;
      
      virtual void run(IPBIWFactory&) = 0;
    };
  }
}

#endif	/* IPBIWOPTIMIZER_H */

