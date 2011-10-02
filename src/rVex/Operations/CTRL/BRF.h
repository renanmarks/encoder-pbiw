/* 
 * File:   BRF.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef BRF_H
#define	BRF_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class BRF : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return 38; }
          Type getSyllableType() const { return CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeVIII(arguments); }
          
          virtual std::string print(bool, bool) const;
      };
    }
  }
}

#endif	/* BRF_H */

