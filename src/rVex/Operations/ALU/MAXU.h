/* 
 * File:   MAXU.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:22
 */

#ifndef MAXU_H
#define	MAXU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MAXU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opMAXU; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MAXU_H */

