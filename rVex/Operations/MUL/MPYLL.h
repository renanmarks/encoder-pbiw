/* 
 * File:   MPYLL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:24
 */

#ifndef MPYLL_H
#define	MPYLL_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLL : public SyllableMUL
      {
        public:
          MPYLL() {};
          MPYLL(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 1; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYLL_H */

