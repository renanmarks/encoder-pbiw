/* 
 * File:   RFI.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef RFI_H
#define	RFI_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class RFI : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return 40; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXIV(arguments); }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
      };
    }
  }
}

#endif	/* RFI_H */

