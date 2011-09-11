/* 
 * File:   SUB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:20
 */

#ifndef SUB_H
#define	SUB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SUB : public SyllableALU
      {
        public:
          SUB() {};
          SUB(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 82; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SUB_H */

