/* 
 * File:   MPYLH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:25
 */

#ifndef MPYLH_H
#define	MPYLH_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLH : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 3; }
          Type getSyllableType() const { return MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYLH_H */

