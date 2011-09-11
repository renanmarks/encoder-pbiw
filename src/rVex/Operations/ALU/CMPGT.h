/* 
 * File:   CMPGT.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPGT_H
#define	CMPGT_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGT : public SyllableALU
      {
        public:
          CMPGT() {};
          CMPGT(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 92; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPGT_H */

