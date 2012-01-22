/* 
 * File:   BR.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef BR_H
#define	BR_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class BR : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opBR; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeVIII(arguments); }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          virtual void exportOperandVector(Utils::OperandVectorBuilder&) const;
      };
    }
  }
}

#endif	/* BR_H */

