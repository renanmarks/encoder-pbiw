/* 
 * File:   MIN.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:26
 */

#ifndef MIN_H
#define	MIN_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MIN : public SyllableALU
      {
        public:
          MIN() {};
          MIN(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 71; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* MIN_H */

