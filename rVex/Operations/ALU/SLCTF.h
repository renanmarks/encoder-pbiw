/* 
 * File:   SLCTF.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:22
 */

#ifndef SLCTF_H
#define	SLCTF_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SLCTF : public SyllableALU
      {
        public:
          SLCTF() {};
          SLCTF(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 48; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SLCTF_H */

