/* 
 * File:   CMPGE.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPGE_H
#define	CMPGE_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGE : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPGE; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* CMPGE_H */

