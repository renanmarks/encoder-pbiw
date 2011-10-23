/* 
 * File:   STW.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:42
 */

#ifndef STW_H
#define	STW_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class STW : public SyllableMEM
      {
        public:
          STW() {}
          
          unsigned int getOpcode() const { return 22; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printSyllable(this, printMEMSTORETYPE(), first, last); }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeXI(arguments); }
      };
    }
  }
}

#endif	/* STW_H */

