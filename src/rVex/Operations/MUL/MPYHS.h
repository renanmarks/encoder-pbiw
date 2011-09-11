/* 
 * File:   MPYHS.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:27
 */

#ifndef MPYHS_H
#define	MPYHS_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHS : public SyllableMUL
      {
        public:
          MPYHS() {};
          MPYHS(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 11; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYHS_H */

