/* 
 * File:   SyllableALU.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLEALU_H
#define	SYLLABLEALU_H

#include <vector>
#include "Syllable.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  /**
   * A r-Vex instruction ALU syllable (operation)
   */
  class SyllableALU : public Syllable
  {
    public:
      virtual ~SyllableALU() { }
      
      virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
      
      virtual void fillSyllable(VexParser::SyllableArguments*) = 0;
  };
}

#endif	/* SYLLABLEALU_H */

