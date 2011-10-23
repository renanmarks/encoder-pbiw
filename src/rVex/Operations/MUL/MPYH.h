/* 
 * File:   MPYH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:26
 */

#ifndef MPYH_H
#define	MPYH_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYH : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 9; }
          SyllableType::Type getSyllableType() const { return SyllableType::MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYH_H */

