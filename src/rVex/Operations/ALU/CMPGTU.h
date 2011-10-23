/* 
 * File:   CMPGTU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPGTU_H
#define	CMPGTU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGTU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 93; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* CMPGTU_H */

