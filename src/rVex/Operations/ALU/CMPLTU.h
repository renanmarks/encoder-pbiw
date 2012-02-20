/* 
 * File:   CMPLTU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:18
 */

#ifndef CMPLTU_H
#define	CMPLTU_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class CMPLTU : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opCMPLTU; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeII(arguments); }
          
          virtual void exportOperandVector(Utils::OperandVectorBuilder&) const;
      };
    }
  }
}

#endif	/* CMPLTU_H */

