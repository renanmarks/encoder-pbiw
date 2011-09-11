/* 
 * File:   XNOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef XNOP_H
#define	XNOP_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class XNOP : public SyllableCTRL
      {
        public:
          XNOP() {};
          
          unsigned int getOpcode() const { return 41; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* XNOP_H */

