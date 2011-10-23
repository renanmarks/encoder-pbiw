/* 
 * File:   DIVS.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 15:28
 */

#ifndef DIVS_H
#define	DIVS_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class DIVS : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 102; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeIV(arguments); }
      };
    }
  }
}

#endif	/* DIVS_H */

