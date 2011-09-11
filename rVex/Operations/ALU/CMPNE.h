/* 
 * File:   CMPNE.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:19
 */

#ifndef CMPNE_H
#define	CMPNE_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPNE : public SyllableALU
      {
        public:
          CMPNE() {};
          CMPNE(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 98; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPNE_H */

