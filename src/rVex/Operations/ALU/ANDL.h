/* 
 * File:   ANDL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:20
 */

#ifndef ANDL_H
#define	ANDL_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ANDL : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opANDL; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* ANDL_H */

