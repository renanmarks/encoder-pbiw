/* 
 * File:   SH4ADD.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SH4ADD_H
#define	SH4ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SH4ADD : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSH4ADD; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* SH4ADD_H */

