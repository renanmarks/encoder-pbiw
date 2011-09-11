/* 
 * File:   SH1ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:15
 */

#ifndef SH1ADD_H
#define	SH1ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH1ADD : public SyllableALU
      {
        public:
          SH1ADD() {};
          SH1ADD(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 75; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* SH1ADD_H */

