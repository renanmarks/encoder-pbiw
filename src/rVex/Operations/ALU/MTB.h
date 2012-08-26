/* 
 * File:   MTB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:20
 */

#ifndef MTB_H
#define	MTB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MTB : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opMTB; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeV(arguments); }
          
          GenericAssembly::Utils::OperandVector exportOperandVector() const;
      };
    }
  }
}

#endif	/* MTB_H */

