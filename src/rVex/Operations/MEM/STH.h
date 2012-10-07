/* 
 * File:   STH.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef STH_H
#define	STH_H

#include <vector>
#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class STH : public SyllableMEM
      {
        public:
          STH() {}
          
          unsigned int getOpcode() const { return this->opSTH; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printOperation(*this, std::vector<unsigned int>(1, printMEMSTORETYPE(first, last)) ); }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXI(arguments); }
          
          GenericAssembly::Utils::OperandVector exportOperandVector() const;
      };
    }
  }
}

#endif	/* STH_H */

