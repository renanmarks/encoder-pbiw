/* 
 * File:   MPYHS.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:27
 */

#ifndef MPYHS_H
#define	MPYHS_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHS : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 11; }
          Type getSyllableType() const { return MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYHS_H */

