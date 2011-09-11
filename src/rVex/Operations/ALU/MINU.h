/* 
 * File:   MINU.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:23
 */

#ifndef MINU_H
#define	MINU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MINU : public SyllableALU
      {
        public:
          MINU() {};
          MINU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 72; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* MINU_H */

