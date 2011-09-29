/* 
 * File:   NORL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:19
 */

#ifndef NORL_H
#define	NORL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class NORL : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 100; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* NORL_H */

