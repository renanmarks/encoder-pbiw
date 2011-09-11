/* 
 * File:   MAX.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 21:49
 */

#ifndef MAX_H
#define	MAX_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MAX : public SyllableALU
      {
        public:
          MAX() {};
          MAX(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 69; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* MAX_H */

