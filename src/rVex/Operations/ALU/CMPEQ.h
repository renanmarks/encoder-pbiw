/* 
 * File:   CMPEQ.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPEQ_H
#define	CMPEQ_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPEQ : public SyllableALU
      {
        public:
          CMPEQ() {};
          CMPEQ(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 89; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPEQ_H */

