/* 
 * File:   NORL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:19
 */

#ifndef NORL_H
#define	NORL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class NORL : public SyllableALU
      {
        public:
          NORL() {};
          NORL(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 100; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* NORL_H */

