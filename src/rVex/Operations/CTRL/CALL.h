/* 
 * File:   CALL.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef CALL_H
#define	CALL_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class CALL : public SyllableCTRL
      {
        public:
          CALL() {}
          
          unsigned int getOpcode() const { return 35; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* CALL_H */

