/* 
 * File:   GOTO.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef GOTO_H
#define	GOTO_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class GOTO : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return 33; }
          Type getSyllableType() const { return CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXIII(arguments); }
          
          virtual std::string print(bool, bool) const;
      };
    }
  }
}

#endif	/* GOTO_H */

