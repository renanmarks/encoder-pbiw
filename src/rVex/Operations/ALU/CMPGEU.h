/* 
 * File:   CMPGEU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:17
 */

#ifndef CMPGEU_H
#define	CMPGEU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPGEU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPGEU; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
          
          GenericAssembly::Utils::OperandVector exportOperandVector() const;
      };
    }
  }
}

#endif	/* CMPGEU_H */

