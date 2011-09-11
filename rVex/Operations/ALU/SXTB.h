/* 
 * File:   SXTB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:20
 */

#ifndef SXTB_H
#define	SXTB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SXTB : public SyllableALU
      {
        public:
          SXTB() {};
          SXTB(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 83; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SXTB_H */

