/* 
 * File:   CMPNE.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:19
 */

#ifndef CMPNE_H
#define	CMPNE_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPNE : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPNE; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
      };
    }
  }
}

#endif	/* CMPNE_H */

