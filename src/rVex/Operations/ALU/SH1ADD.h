/* 
 * File:   SH1ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:15
 */

#ifndef SH1ADD_H
#define	SH1ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH1ADD : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSH1ADD; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* SH1ADD_H */

