/* 
 * File:   MPYLU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:26
 */

#ifndef MPYLU_H
#define	MPYLU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLU : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 8; }
          Type getSyllableType() const { return MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYLU_H */

