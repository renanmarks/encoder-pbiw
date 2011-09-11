/* 
 * File:   ADDCG.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 15:41
 */

#ifndef ADDCG_H
#define	ADDCG_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ADDCG : public SyllableALU
      {
        public:
          ADDCG() {};
          ADDCG(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 104; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* ADDCG_H */

