/* 
 * File:   SyllableMISC.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 01:01
 */

#ifndef SYLLABLEMISC_H
#define	SYLLABLEMISC_H

#include "Syllable.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  /**
   * A r-Vex instruction MISC syllable (operation)
   */
  class SyllableMISC : public Syllable
  {
    public:
      virtual ~SyllableMISC() { }
      
      virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
      
      virtual void fillSyllable(VexParser::SyllableArguments&) = 0;
  };
}

#endif	/* SYLLABLEMISC_H */

