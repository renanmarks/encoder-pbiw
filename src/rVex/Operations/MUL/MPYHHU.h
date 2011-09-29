/* 
 * File:   MPYHHU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:26
 */

#ifndef MPYHHU_H
#define	MPYHHU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHHU : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 6; }
          Type getSyllableType() const { return MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYHHU_H */

