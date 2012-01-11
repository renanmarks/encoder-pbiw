/* 
 * File:   SHR.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SHR_H
#define	SHR_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SHR : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSHR; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* SHR_H */

