/* 
 * File:   CMPLE.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLE_H
#define	CMPLE_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLE : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPLE; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
          
          OperandConstPtrDeque exportOperandVector() const;
      };
    }
  }
}

#endif	/* CMPLE_H */

