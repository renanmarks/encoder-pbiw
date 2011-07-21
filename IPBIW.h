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
#include "IPBIWInstruction.h"

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIW
    {
      public:
        virtual ~IPBIW() {};
        virtual void encode(std::vector<IPBIWInstruction>) = 0;
        virtual void decode() = 0;

        virtual std::ostream getPatterns() = 0;
        virtual std::ostream getInstructions() = 0;
    };
  }
}

#endif	/* IPBIW_H */

