/* 
 * File:   LDB.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:42
 */

#ifndef LDB_H
#define	LDB_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDB : public SyllableMEM
      {
        public:
          LDB() {}
          
          unsigned int getOpcode() const { return 20; }
          Type getSyllableType() const { return MEM; }
      };
    }
  }
}

#endif	/* LDB_H */

