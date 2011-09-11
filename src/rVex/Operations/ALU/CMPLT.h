/* 
 * File:   CMPLT.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLT_H
#define	CMPLT_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLT : public SyllableALU
      {
        public:
          CMPLT() {};
          CMPLT(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 96; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPLT_H */

