/* 
 * File:   DIVS.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 15:28
 */

#ifndef DIVS_H
#define	DIVS_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class DIVS : public SyllableALU
      {
        public:
          DIVS() {};
          DIVS(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 102; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* DIVS_H */

