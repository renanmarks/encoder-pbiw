/* 
 * File:   SEND.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef SEND_H
#define	SEND_H

#include "../../SyllableMISC.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class SEND : public Syllable
      {
        public:
          SEND() {}
          
          unsigned int getOpcode() const { return 42; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* SEND_H */

