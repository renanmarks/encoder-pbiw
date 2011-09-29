/* 
 * File:   ADD.h
 * Author: helix
 *
 * Created on August 21, 2011, 7:43 PM
 */

#ifndef ADD_H
#define	ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ADD : public SyllableALU
      {
        public:
          unsigned int getOpcode() const { return 65; }
          Type getSyllableType() const { return ALU; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* ADD_H */

