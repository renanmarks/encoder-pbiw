/* 
 * File:   MPYHU.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:27
 */

#ifndef MPYHU_H
#define	MPYHU_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYHU : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return this->opMPYHU; }
          SyllableType::Type getSyllableType() const { return SyllableType::MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYHU_H */

