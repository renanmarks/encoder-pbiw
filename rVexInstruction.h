/* 
 * File:   rVexInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:19 PM
 */

#ifndef RVEXINSTRUCTION_H
#define	RVEXINSTRUCTION_H

#include "IVLIWInstruction.h"

namespace rVex
{
  namespace Concrete
  {
    using namespace Base;
    
    class rVexInstruction : public IVLIWInstruction
    {
      public:
        rVexInstruction();
        rVexInstruction(const rVexInstruction& orig);
        virtual ~rVexInstruction();
      private:

    };
  }
}

#endif	/* RVEXINSTRUCTION_H */

