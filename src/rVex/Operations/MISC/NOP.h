/* 
 * File:   NOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef NOP_H
#define	NOP_H

#include <vector>
#include "../../Syllable.h"
#include "../../SyllableMISC.h"
#include "src/rVex/Printers/IPrinter.h"

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
          
          unsigned int getOpcode() const { return this->opNOP; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual bool operator==(const Syllable& other) const
          { return other.getOpcode() == this->getOpcode(); }
          
          virtual bool operator!=(const Syllable& other) const
          { return !(*this == other); }
          
          virtual LayoutType::Type getLayoutType() const { return LayoutType::RTYPE; }
      
          virtual void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { 
            unsigned int nop = (((0 | last) << 1) | first);
            output.printOperation(*this, std::vector<unsigned int>(1, nop)); 
          }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXIV(arguments); }
      };
    }
  }
}

#endif	/* NOP_H */

