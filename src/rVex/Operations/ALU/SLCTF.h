/* 
 * File:   SLCTF.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:22
 */

#ifndef SLCTF_H
#define	SLCTF_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SLCTF : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSLCTF; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeIII(arguments); }
      };
    }
  }
}

#endif	/* SLCTF_H */

