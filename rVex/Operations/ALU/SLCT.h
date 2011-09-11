/* 
 * File:   SLCT.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:21
 */

#ifndef SLCT_H
#define	SLCT_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SLCT : public SyllableALU
      {
        public:
          SLCT() {};
          SLCT(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 56; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SLCT_H */

