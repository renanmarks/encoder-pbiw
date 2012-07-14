/* 
 * File:   IPrinter.h
 * Author: helix
 *
 * Created on September 17, 2011, 8:51 PM
 */

#ifndef IPRINTER_H
#define	IPRINTER_H

#include <ostream>
#include "src/GenericAssembly/Interfaces/IPrinter.h"

namespace rVex
{
  class Instruction;
  class Syllable;
  
  namespace Printers
  {
    /**
     * Printer interface
     * Used by the printing mechanisms to output the bytecode.
     */
    class IPrinter : public GenericAssembly::Interfaces::IPrinter<Instruction, Syllable>
    {
    public:
      virtual ~IPrinter() { }
    };
  }
}

#endif	/* IPRINTER_H */

