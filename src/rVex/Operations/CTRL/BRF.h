/* 
 * File:   BRF.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:29
 */

#ifndef BRF_H
#define	BRF_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class BRF : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opBRF; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeVIII(arguments); }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          virtual void exportOperandVector(Utils::OperandVectorBuilder&) const;
      };
    }
  }
}

#endif	/* BRF_H */

