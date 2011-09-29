/* 
 * File:   PFT.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef PFT_H
#define	PFT_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class PFT : public SyllableMEM
      {
        public:
          PFT() {}
          
          unsigned int getOpcode() const { return 25; }
          Type getSyllableType() const { return MEM; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXII(arguments); }
      };
    }
  }
}

#endif	/* PFT_H */

