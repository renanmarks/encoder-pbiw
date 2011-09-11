/* 
 * File:   CMPGTU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPGTU_H
#define	CMPGTU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGTU : public SyllableALU
      {
        public:
          CMPGTU() {};
          CMPGTU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 93; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPGTU_H */

