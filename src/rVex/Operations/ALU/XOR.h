/* 
 * File:   XOR.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:16
 */

#ifndef XOR_H
#define	XOR_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class XOR : public SyllableALU
      {
        public:
          XOR() {};
          XOR(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 87; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* XOR_H */

