/* 
 * File:   MPYLLUU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:24
 */

#ifndef MPYLLUU_H
#define	MPYLLUU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLLU : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return this->opMPYLLU; }
          SyllableType::Type getSyllableType() const { return SyllableType::MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYLLUU_H */

