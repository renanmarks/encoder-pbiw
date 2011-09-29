/* 
 * File:   OR.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:24
 */

#ifndef OR_H
#define	OR_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class OR : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 73; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* OR_H */

