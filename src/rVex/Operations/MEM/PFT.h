/* 
 * File:   PFT.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef PFT_H
#define	PFT_H

#include <vector>
#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class PFT : public SyllableMEM
      {
        public:
          PFT() {}
          
          unsigned int getOpcode() const { return this->opPFT; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { 
            unsigned int prefetch = ((last << 1) | first) | 0xDEAD0000;
            output.printOperation(*this, std::vector<unsigned int>(1, prefetch)); 
          }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXII(arguments); }
      };
    }
  }
}

#endif	/* PFT_H */

