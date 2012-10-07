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
#include "IPBIWSet.h"
#include <deque>

namespace PBIW
{
  namespace Interfaces 
  {
    class IPBIW;
    
    class IPBIWOptimizer : public IPBIWSet
    {
    public:
      virtual ~IPBIWOptimizer() {}
      
      virtual void useContext(const IPBIW&) = 0;
      
      virtual void useLabels(const std::deque<ILabel*>&) = 0;
      virtual void useInstructions(const std::deque<IPBIWInstruction*>&) = 0;
      virtual void usePatterns(const std::deque<IPBIWPattern*>&) = 0;
      
      virtual void setupOptimizer() = 0;
      
      virtual void run(IPBIWFactory&) = 0;
    };
  }
}

#endif	/* IPBIWOPTIMIZER_H */

