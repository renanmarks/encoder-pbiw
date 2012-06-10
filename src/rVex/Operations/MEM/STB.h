/* 
 * File:   STB.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef STB_H
#define	STB_H

#include <vector>
#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class STB : public SyllableMEM
      {
        public:
          STB() {}
          
          unsigned int getOpcode() const { return this->opSTB; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printOperation(*this, std::vector<unsigned int>(1, printMEMSTORETYPE(first, last))); }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXI(arguments); }
          
          void exportOperandVector(Utils::OperandVectorBuilder& builder) const;
      };
    }
  }
}

#endif	/* STB_H */

