/* 
 * File:   PBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef RVEX64PBIWINSTRUCTION_H
#define	RVEX64PBIWINSTRUCTION_H

#include "Interfaces/IPBIWInstruction.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Concrete
  {
    /**
     * r-VEX 64 bits length instruction 
     */
    class rVex64PBIWInstruction : public IPBIWInstruction
    {
      public:
        rVex64PBIWInstruction();
        rVex64PBIWInstruction(const rVex64PBIWInstruction& orig);
        virtual ~rVex64PBIWInstruction();
      private:

    };
  }
}

#endif	/* RVEX64PBIWINSTRUCTION_H */

