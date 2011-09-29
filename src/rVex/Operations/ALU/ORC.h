/* 
 * File:   ORC.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:24
 */

#ifndef ORC_H
#define	ORC_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ORC : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 74; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* ORC_H */

