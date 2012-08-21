/* 
 * File:   CMPLT.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLT_H
#define	CMPLT_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLT : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPLT; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
          
          OperandConstPtrDeque exportOperandVector() const;
      };
    }
  }
}

#endif	/* CMPLT_H */

