/* 
 * File:   STOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:55
 */

#ifndef STOP_H
#define	STOP_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class STOP : public SyllableCTRL
      {
        public:
          STOP() { setTextRepresentation("stop"); }
          
          unsigned int getOpcode() const { return this->opSTOP; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printSyllable(this, this->getOpcode() << 25, first, last); }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { return; }
      };
    }
  }
}

#endif	/* STOP_H */

