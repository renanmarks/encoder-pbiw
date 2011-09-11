/* 
 * File:   NOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef NOP_H
#define	NOP_H

#include "../../SyllableMISC.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class NOP : public Syllable
      {
        public:
          NOP() {}
          
          unsigned int getOpcode() const { return 0; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* NOP_H */

