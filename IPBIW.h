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
#include "IVLIWInstruction.h"
#include "IPBIWInstruction.h"
#include "IPBIWPattern.h"

namespace PBIW
{
  namespace Interfaces
  {   
    using namespace Base;
    
    /**
     * PBIW codec interface
     */
    class IPBIW
    {
      public:
        virtual ~IPBIW() {};
        virtual void encode(const std::vector<IVLIWInstruction>&) = 0;
        virtual void decode(const std::vector<IPBIWInstruction>&, const std::vector<IPBIWPattern>&) = 0;

        virtual std::ostream getPatterns() = 0;
        virtual std::ostream getInstructions() = 0;
    };
  }
}

#endif	/* IPBIW_H */

