/* 
 * File:   SUB.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 02:20
 */

#ifndef SUB_H
#define	SUB_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class SUB : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opSUB; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeVI(arguments); }
      };
    }
  }
}

#endif	/* SUB_H */

