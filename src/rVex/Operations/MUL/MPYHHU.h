/* 
 * File:   MPYHHU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:26
 */

#ifndef MPYHHU_H
#define	MPYHHU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHHU : public SyllableMUL
      {
        public:
          MPYHHU() {};
          MPYHHU(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 6; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYHHU_H */

