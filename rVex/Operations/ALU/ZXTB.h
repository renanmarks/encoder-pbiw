/* 
 * File:   ZXTB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:14
 */

#ifndef ZXTB_H
#define	ZXTB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ZXTB : public SyllableALU
      {
        public:
          ZXTB() {};
          ZXTB(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 85; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ZXTB_H */

