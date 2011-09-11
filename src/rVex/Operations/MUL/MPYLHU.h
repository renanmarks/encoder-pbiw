/* 
 * File:   MPYLHU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:25
 */

#ifndef MPYLHU_H
#define	MPYLHU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLHU : public SyllableMUL
      {
        public:
          MPYLHU() {};
          MPYLHU(LayoutType layoutType) : SyllableMUL(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 4; }
          Type getSyllableType() const { return MUL; }
      };
    }
  }
}

#endif	/* MPYLHU_H */

