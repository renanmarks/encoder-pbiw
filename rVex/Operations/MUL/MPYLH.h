/* 
 * File:   MPYLH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:25
 */

#ifndef MPYLH_H
#define	MPYLH_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLH : public SyllableMUL
      {
        public:
          MPYLH() {};
          MPYLH(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 3; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYLH_H */

