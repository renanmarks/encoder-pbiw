/* 
 * File:   XOR.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:16
 */

#ifndef XOR_H
#define	XOR_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class XOR : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 87; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* XOR_H */

