/* 
 * File:   CMPLEU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLEU_H
#define	CMPLEU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLEU : public SyllableALU
      {
        public:
          CMPLEU() {};
          CMPLEU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 95; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPLEU_H */

