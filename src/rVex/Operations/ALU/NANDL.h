/* 
 * File:   NANDL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:19
 */

#ifndef NANDL_H
#define	NANDL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class NANDL : public SyllableALU
      {
        public:
          NANDL() {};
          NANDL(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 99; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* NANDL_H */

