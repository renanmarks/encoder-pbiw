/* 
 * File:   RFI.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef RFI_H
#define	RFI_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class RFI : public SyllableCTRL
      {
        public:
          RFI() {};
          
          unsigned int getOpcode() const { return 40; }
          Type getSyllableType() const { return CTRL; }
      };
    }
  }
}

#endif	/* RFI_H */

