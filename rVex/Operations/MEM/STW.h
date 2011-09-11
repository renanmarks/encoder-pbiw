/* 
 * File:   STW.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:42
 */

#ifndef STW_H
#define	STW_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class STW : public SyllableMEM
      {
        public:
          STW() {}
          
          unsigned int getOpcode() const { return 22; }
          Type getSyllableType() const { return MEM; }
      };
    }
  }
}

#endif	/* STW_H */

