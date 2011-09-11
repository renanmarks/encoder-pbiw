/* 
 * File:   SH2ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:16
 */

#ifndef SH2ADD_H
#define	SH2ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH2ADD : public SyllableALU
      {
        public:
          SH2ADD() {};
          SH2ADD(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 76; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SH2ADD_H */

