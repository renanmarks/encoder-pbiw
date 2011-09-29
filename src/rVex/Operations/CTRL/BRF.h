/* 
 * File:   BRF.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef BRF_H
#define	BRF_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class BRF : public SyllableCTRL
      {
        public:
          BRF() {}
          
          unsigned int getOpcode() const { return 38; }
          Type getSyllableType() const { return CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeVIII(arguments); }
      };
    }
  }
}

#endif	/* BRF_H */

