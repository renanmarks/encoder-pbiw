/* 
 * File:   LDH.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:41
 */

#ifndef LDH_H
#define	LDH_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDH : public SyllableMEM
      {
        public:
          LDH() {}
          
          unsigned int getOpcode() const { return 18; }
          Type getSyllableType() const { return MEM; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeX(arguments); }
      };
    }
  }
}

#endif	/* LDH_H */

