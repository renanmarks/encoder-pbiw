/* 
 * File:   NOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef NOP_H
#define	NOP_H

#include "../../SyllableMISC.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class NOP : public Syllable
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
      
          virtual std::string print(bool first, bool last) const 
          { return printBinary(0, first, last); }
      };
    }
  }
}

#endif	/* NOP_H */

