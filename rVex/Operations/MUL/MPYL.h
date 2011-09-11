/* 
 * File:   MPYL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:26
 */

#ifndef MPYL_H
#define	MPYL_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYL : public SyllableMUL
      {
        public:
          MPYL() {};
          MPYL(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 7; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYL_H */

