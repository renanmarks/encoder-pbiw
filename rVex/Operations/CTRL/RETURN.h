/* 
 * File:   RETURN.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef RETURN_H
#define	RETURN_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class RETURN : public SyllableCTRL
      {
        public:
          RETURN() {};
          
          unsigned int getOpcode() const { return 39; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* RETURN_H */

