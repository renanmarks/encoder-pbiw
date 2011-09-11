/* 
 * File:   LDHU.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:41
 */

#ifndef LDHU_H
#define	LDHU_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDHU : public SyllableMEM
      {
        public:
          LDHU() {}
          
          unsigned int getOpcode() const { return 19; }
          Type getSyllableType() const { return MEM; }
      };
    }
  }
}

#endif	/* LDHU_H */

