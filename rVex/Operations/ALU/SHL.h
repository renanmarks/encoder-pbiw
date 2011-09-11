/* 
 * File:   SHL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SHL_H
#define	SHL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SHL : public SyllableALU
      {
        public:
          SHL() {};
          SHL(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 79; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SHL_H */

