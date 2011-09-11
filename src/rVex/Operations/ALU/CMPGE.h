/* 
 * File:   CMPGE.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPGE_H
#define	CMPGE_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGE : public SyllableALU
      {
        public:
          CMPGE() {};
          CMPGE(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 90; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* CMPGE_H */

