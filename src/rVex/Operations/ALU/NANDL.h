/* 
 * File:   NANDL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:19
 */

#ifndef NANDL_H
#define	NANDL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class NANDL : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 99; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* NANDL_H */

