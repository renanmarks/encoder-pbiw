/* 
 * File:   ZXTH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:16
 */

#ifndef ZXTH_H
#define	ZXTH_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ZXTH : public SyllableALU
      {
        public:
          ZXTH() {};
          ZXTH(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 86; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ZXTH_H */

