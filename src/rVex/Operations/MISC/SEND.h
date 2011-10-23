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
      class SEND : public SyllableMISC
      {
        public:
          SEND() {}
          
          unsigned int getOpcode() const { return 42; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
      };
    }
  }
}

#endif	/* SEND_H */

