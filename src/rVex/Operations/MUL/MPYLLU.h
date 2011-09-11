/* 
 * File:   MPYLLUU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:24
 */

#ifndef MPYLLUU_H
#define	MPYLLUU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLLU : public SyllableMUL
      {
        public:
          MPYLLU() {};
          MPYLLU(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 2; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYLLUU_H */

