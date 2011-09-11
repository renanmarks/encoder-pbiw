/* 
 * File:   CMPGEU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPGEU_H
#define	CMPGEU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGEU : public SyllableALU
      {
        public:
          CMPGEU() {};
          CMPGEU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 91; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPGEU_H */

