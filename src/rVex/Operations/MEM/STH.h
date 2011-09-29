/* 
 * File:   STH.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef STH_H
#define	STH_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class STH : public SyllableMEM
      {
        public:
          STH() {}
          
          unsigned int getOpcode() const { return 23; }
          Type getSyllableType() const { return MEM; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXI(arguments); }
      };
    }
  }
}

#endif	/* STH_H */

