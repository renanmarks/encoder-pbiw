/* 
 * File:   SXTH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:20
 */

#ifndef SXTH_H
#define	SXTH_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SXTH : public SyllableALU
      {
        public:
          SXTH() {};
          SXTH(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 84; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SXTH_H */

