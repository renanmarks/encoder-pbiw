/* 
 * File:   ZXTH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:16
 */

#ifndef ZXTH_H
#define	ZXTH_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ZXTH : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opZXTH; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeVII(arguments); }
      };
    }
  }
}

#endif	/* ZXTH_H */

