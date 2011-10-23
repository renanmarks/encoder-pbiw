/* 
 * File:   IPBIWPattern.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:23 PM
 */

#ifndef IPBIWPATTERN_H
#define	IPBIWPATTERN_H

#include "IPattern.h"

namespace PBIW
{
  namespace Interfaces
  {
    /**
     * PBIW Pattern interface
     */
    class IPBIWPattern
    {
      public:
        virtual ~IPBIWPattern() {}
        
        virtual void addPattern(IPattern&) = 0;
        virtual IPattern getPattern() const = 0;
        
    };
  }
}

#endif	/* IPBIWPATTERN_H */

