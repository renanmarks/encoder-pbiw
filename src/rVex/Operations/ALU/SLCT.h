/* 
 * File:   SLCT.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 14:21
 */

#ifndef SLCT_H
#define	SLCT_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SLCT : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSLCT | this->brSource; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeIII(arguments); }
          
          virtual void exportOperandVector(Utils::OperandVectorBuilder&) const;
      };
    }
  }
}

#endif	/* SLCT_H */

