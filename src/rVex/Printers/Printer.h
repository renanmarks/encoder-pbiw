/* 
 * File:   IPrinter.h
 * Author: helix
 *
 * Created on September 17, 2011, 8:51 PM
 */

#ifndef IPRINTER_H
#define	IPRINTER_H

#include <ostream>

namespace rVex
{
  namespace Printers
  {
    class Printer
    {
    public:
      Printer(std::ostream& outputStream) : outputStream(outputStream) { }
      virtual ~Printer() { }
    
    protected:
      
    private:
      std::ostream& outputStream;
    };
  }
}

#endif	/* IPRINTER_H */

