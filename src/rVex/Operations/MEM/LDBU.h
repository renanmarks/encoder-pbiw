/* 
 * File:   LDBU.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:42
 */

#ifndef LDBU_H
#define	LDBU_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDBU : public SyllableMEM
      {
        public:
          LDBU() {}
          
          unsigned int getOpcode() const { return 21; }
          Type getSyllableType() const { return MEM; }
      };
    }
  }
}

#endif	/* LDBU_H */

