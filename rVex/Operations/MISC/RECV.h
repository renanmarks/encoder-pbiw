/* 
 * File:   RECV.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef RECV_H
#define	RECV_H

#include "../../SyllableMISC.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class RECV : public Syllable
      {
        public:
          RECV() {}
          
          unsigned int getOpcode() const { return 43; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* RECV_H */

