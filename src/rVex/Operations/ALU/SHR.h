/* 
 * File:   SHR.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SHR_H
#define	SHR_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SHR : public SyllableALU
      {
        public:
          SHR() {};
          SHR(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 80; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SHR_H */

