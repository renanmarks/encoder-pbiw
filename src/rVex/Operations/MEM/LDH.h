/* 
 * File:   LDH.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:41
 */

#ifndef LDH_H
#define	LDH_H

#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDH : public SyllableMEM
      {
        public:
          unsigned int getOpcode() const { return 18; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printSyllable(this, printMEMLOADTYPE(), first, last); }
          
          virtual void fillSyllable(VexParser::SyllableArguments* arguments)
          { this->fillTypeX(arguments); }
      };
    }
  }
}

#endif	/* LDH_H */

