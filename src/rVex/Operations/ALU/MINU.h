/* 
 * File:   MINU.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:23
 */

#ifndef MINU_H
#define	MINU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MINU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opMINU; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MINU_H */

