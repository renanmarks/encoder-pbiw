/* 
 * File:   CMPLEU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLEU_H
#define	CMPLEU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLEU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPLEU; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* CMPLEU_H */

