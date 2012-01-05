/* 
 * File:   ICALL.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef ICALL_H
#define	ICALL_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class ICALL : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opICALL; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXX(arguments); }
      };
    }
  }
}

#endif	/* ICALL_H */

