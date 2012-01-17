/* 
 * File:   ALUSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLECTRL_H
#define	SYLLABLECTRL_H

#include "Syllable.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  /**
   * A r-Vex instruction CTRL syllable (operation)
   */
  class SyllableCTRL : public Syllable
  {
    public:
      virtual ~SyllableCTRL() { }
      
      virtual void print(rVex::Printers::IPrinter&, bool, bool) const = 0;
      
      virtual void fillSyllable(VexParser::SyllableArguments&) = 0;
  };
}

#endif	/* ALUSYLLABLE_H */
