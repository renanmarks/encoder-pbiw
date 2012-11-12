/* 
 * File:   RECV.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef RECV_H
#define	RECV_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class RECV : public SyllableCTRL
      {
        public:
          RECV() {}
          
          unsigned int getOpcode() const { return this->opRECV; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
      };
    }
  }
}

#endif	/* RECV_H */

