/* 
 * File:   MOV.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 03:16
 */

#ifndef MOV_H
#define	MOV_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MOV : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opMOV; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeVII(arguments); }
      };
    }
  }
}

#endif	/* MOV_H */

