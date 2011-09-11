/* 
 * File:   ORL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:20
 */

#ifndef ORL_H
#define	ORL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ORL : public SyllableALU
      {
        public:
          ORL() {};
          ORL(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 102; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ORL_H */

