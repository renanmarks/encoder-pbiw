/* 
 * File:   SH4ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SH4ADD_H
#define	SH4ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH4ADD : public SyllableALU
      {
        public:
          SH4ADD() {};
          SH4ADD(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 78; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SH4ADD_H */

