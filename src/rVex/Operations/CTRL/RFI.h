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
          Type getSyllableType() const { return CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXIV(arguments); }
          
          virtual std::string print(bool, bool) const;
      };
    }
  }
}

#endif	/* RFI_H */

