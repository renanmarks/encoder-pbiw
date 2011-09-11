/* 
 * File:   MOV.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:16
 */

#ifndef MOV_H
#define	MOV_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MOV : public SyllableALU
      {
        public:
          MOV() {};
          MOV(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 88; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* MOV_H */

