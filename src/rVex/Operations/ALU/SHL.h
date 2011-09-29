/* 
 * File:   SHL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:17
 */

#ifndef SHL_H
#define	SHL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SHL : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 79; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* SHL_H */

