/* 
 * File:   MAXU.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:22
 */

#ifndef MAXU_H
#define	MAXU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MAXU : public SyllableALU
      {
        public:
          MAXU() {};
          MAXU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 70; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* MAXU_H */

