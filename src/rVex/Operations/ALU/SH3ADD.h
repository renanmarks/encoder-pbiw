/* 
 * File:   SH3ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SH3ADD_H
#define	SH3ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH3ADD : public SyllableALU
      {
        public:
          SH3ADD() {};
          SH3ADD(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 77; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SH3ADD_H */

