/* 
 * File:   SXTB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:20
 */

#ifndef SXTB_H
#define	SXTB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SXTB : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 83; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeVII(arguments); }
      };
    }
  }
}

#endif	/* SXTB_H */

