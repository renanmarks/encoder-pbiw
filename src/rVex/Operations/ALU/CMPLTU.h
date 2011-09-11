/* 
 * File:   CMPLTU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLTU_H
#define	CMPLTU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLTU : public SyllableALU
      {
        public:
          CMPLTU() {};
          CMPLTU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 97; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPLTU_H */

