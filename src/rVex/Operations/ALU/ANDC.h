/* 
 * File:   ANDC.h
 * Author: renato
 *
 * Created on 31 de Agosto de 2011, 16:46
 */

#ifndef ANDC_H
#define	ANDC_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ANDC : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opANDC; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* ANDC_H */

