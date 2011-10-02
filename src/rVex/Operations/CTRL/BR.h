/* 
 * File:   BR.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef BR_H
#define	BR_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class BR : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return 37; }
          Type getSyllableType() const { return CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeVIII(arguments); }
          
          virtual std::string print(bool, bool) const;
      };
    }
  }
}

#endif	/* BR_H */

