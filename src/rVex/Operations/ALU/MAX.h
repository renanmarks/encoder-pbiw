/* 
 * File:   MAX.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 21:49
 */

#ifndef MAX_H
#define	MAX_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MAX : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 69; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MAX_H */

