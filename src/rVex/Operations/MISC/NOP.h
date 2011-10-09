/* 
 * File:   NOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef NOP_H
#define	NOP_H

#include "../../Syllable.h"
#include "../../SyllableMISC.h"
#include "../../Printers/IPrinter.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class NOP : public SyllableMISC
      {
        public:
          NOP() {}
          
          unsigned int getOpcode() const { return 0; }
          Type getSyllableType() const { return CTRL; }
          
          virtual bool operator==(const Syllable& other) const
          { return other.getOpcode() == this->getOpcode(); }
          
          virtual bool operator!=(const Syllable& other) const
          { return !(*this == other); }
          
          virtual LayoutType getLayoutType() const { return RTYPE; }
      
          virtual void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printSyllable(this, 0, first, last); }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXIV(arguments); }
      };
    }
  }
}

#endif	/* NOP_H */

