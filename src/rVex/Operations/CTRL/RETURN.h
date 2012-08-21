/* 
 * File:   RETURN.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef RETURN_H
#define	RETURN_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class RETURN : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opRETURN; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXVII(arguments); }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          OperandConstPtrDeque exportOperandVector() const;
      };
    }
  }
}

#endif	/* RETURN_H */

