/* 
 * File:   MPYLL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:24
 */

#ifndef MPYLL_H
#define	MPYLL_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLL : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 1; }
          Type getSyllableType() const { return MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYLL_H */

