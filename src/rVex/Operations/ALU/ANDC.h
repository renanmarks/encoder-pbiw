/* 
 * File:   ANDC.h
 * Author: renato
 *
 * Created on 31 de Agosto de 2011, 16:46
 */

#ifndef ANDC_H
#define	ANDC_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ANDC : public SyllableALU
      {
        public:
          ANDC() {};
          ANDC(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 68; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ANDC_H */

