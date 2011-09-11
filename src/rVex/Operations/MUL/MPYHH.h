/* 
 * File:   MPYHH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:25
 */

#ifndef MPYHH_H
#define	MPYHH_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHH : public SyllableMUL
      {
        public:
          MPYHH() {};
          MPYHH(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 5; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYHH_H */

