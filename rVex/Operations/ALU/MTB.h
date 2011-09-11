/* 
 * File:   MTB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:20
 */

#ifndef MTB_H
#define	MTB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MTB : public SyllableALU
      {
        public:
          MTB() {};
          MTB(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 103; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* MTB_H */

