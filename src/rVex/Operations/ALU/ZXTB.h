/* 
 * File:   ZXTB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:14
 */

#ifndef ZXTB_H
#define	ZXTB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ZXTB : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 85; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeVII(arguments); }
      };
    }
  }
}

#endif	/* ZXTB_H */

