/* 
 * File:   CMPLE.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLE_H
#define	CMPLE_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLE : public SyllableALU
      {
        public:
          CMPLE() {};
          CMPLE(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 94; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPLE_H */

