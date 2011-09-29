/* 
 * File:   MPYL.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:26
 */

#ifndef MPYL_H
#define	MPYL_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYL : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 7; }
          Type getSyllableType() const { return MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYL_H */

