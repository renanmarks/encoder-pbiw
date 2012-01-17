/* 
 * File:   MIN.h
 * Author: renato
 *
 * Created on 5 de Setembro de 2011, 22:26
 */

#ifndef MIN_H
#define	MIN_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class MIN : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return this->opMIN; }
          SyllableType::Type getSyllableType() const { return SyllableType::ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MIN_H */

