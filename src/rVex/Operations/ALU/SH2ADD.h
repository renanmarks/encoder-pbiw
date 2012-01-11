/* 
 * File:   SH2ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:16
 */

#ifndef SH2ADD_H
#define	SH2ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH2ADD : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSH2ADD; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* SH2ADD_H */

