/* 
 * File:   SHRU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:18
 */

#ifndef SHRU_H
#define	SHRU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SHRU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 81; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* SHRU_H */

