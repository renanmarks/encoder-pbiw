/* 
 * File:   STOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:55
 */

#ifndef STOP_H
#define	STOP_H

#include "../../SyllableMISC.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class STOP : public Syllable
      {
        public:
          STOP() {}
          
          unsigned int getOpcode() const { return 31; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
      };
    }
  }
}

#endif	/* STOP_H */

