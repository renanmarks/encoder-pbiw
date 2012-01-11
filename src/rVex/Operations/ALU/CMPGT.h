/* 
 * File:   CMPGT.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPGT_H
#define	CMPGT_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGT : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPGT; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* CMPGT_H */

