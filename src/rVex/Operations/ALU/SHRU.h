/* 
 * File:   SHRU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:18
 */

#ifndef SHRU_H
#define	SHRU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SHRU : public SyllableALU
      {
        public:
          SHRU() {};
          SHRU(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 81; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SHRU_H */

