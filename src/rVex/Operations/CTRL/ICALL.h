/* 
 * File:   ICALL.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef ICALL_H
#define	ICALL_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class ICALL : public SyllableCTRL
      {
        public:
          ICALL() {};
          
          unsigned int getOpcode() const { return 36; }
          Type getSyllableType() const { return CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXX(arguments); }
      };
    }
  }
}

#endif	/* ICALL_H */

