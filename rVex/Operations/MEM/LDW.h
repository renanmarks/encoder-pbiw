/* 
 * File:   LDW.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:41
 */

#ifndef LDW_H
#define	LDW_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDW : public SyllableMEM
      {
        public:
          LDW() {}
          
          unsigned int getOpcode() const { return 17; }
          Type getSyllableType() const { return MEM; }
      };
    }
  }
}

#endif	/* LDW_H */

