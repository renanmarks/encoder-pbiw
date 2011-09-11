/* 
 * File:   ANDL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:20
 */

#ifndef ANDL_H
#define	ANDL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ANDL : public SyllableALU
      {
        public:
          ANDL() {};
          ANDL(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 104; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ANDL_H */

