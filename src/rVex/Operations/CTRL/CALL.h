/* 
 * File:   CALL.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef CALL_H
#define	CALL_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class CALL : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return 35; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXVI(arguments); }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
      };
    }
  }
}

#endif	/* CALL_H */

