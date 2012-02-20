/* 
 * File:   ADDCG.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 15:41
 */

#ifndef ADDCG_H
#define	ADDCG_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ADDCG : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opADDCG | this->brSource; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeIV(arguments); }
          
          virtual void exportOperandVector(Utils::OperandVectorBuilder&) const;
      };
    }
  }
}

#endif	/* ADDCG_H */

