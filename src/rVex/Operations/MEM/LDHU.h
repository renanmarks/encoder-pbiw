/* 
 * File:   LDHU.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:41
 */

#ifndef LDHU_H
#define	LDHU_H

#include <vector>
#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class LDHU : public SyllableMEM
      {
        public:
          unsigned int getOpcode() const { return this->opLDHU; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printOperation(*this, std::vector<unsigned int>(1, printMEMLOADTYPE(first, last)) ); }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeX(arguments); }
          
          GenericAssembly::Utils::OperandVector exportOperandVector() const;
      };
    }
  }
}

#endif	/* LDHU_H */

