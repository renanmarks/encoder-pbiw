/* 
 * File:   ORC.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:24
 */

#ifndef ORC_H
#define	ORC_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ORC : public SyllableALU
      {
        public:
          ORC() {};
          ORC(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 74; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ORC_H */

