/* 
 * File:   MPYHH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:25
 */

#ifndef MPYHH_H
#define	MPYHH_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHH : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return 5; }
          SyllableType::Type getSyllableType() const { return SyllableType::MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYHH_H */

