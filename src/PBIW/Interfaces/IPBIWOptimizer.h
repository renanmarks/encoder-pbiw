/* 
 * File:   IPBIWOptimizer.h
 * Author: helix
 *
 * Created on December 15, 2011, 3:41 PM
 */

#ifndef IPBIWOPTIMIZER_H
#define	IPBIWOPTIMIZER_H

namespace PBIW
{
  namespace Interfaces 
  {
    class IPBIWOptimizer 
    {
    public:
      virtual ~IPBIWOptimizer() {}
      
      virtual void useLabels() = 0;
      virtual void useInstructions(std::vector<IPBIWInstruction*>&) = 0;
      virtual void usePatterns(std::vector<IPBIWPattern*>&) = 0;
      
      virtual void run() = 0;
    };
  }
}

#endif	/* IPBIWOPTIMIZER_H */

