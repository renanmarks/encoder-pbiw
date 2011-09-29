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

namespace rVex
{
  /**
   * A r-Vex instruction ALU syllable (operation)
   */
  class SyllableALU : public Syllable
  {
    public:
      virtual ~SyllableALU() { }
      
      virtual bool operator==(const Syllable&) const;
      virtual bool operator!=(const Syllable&) const;
      virtual std::string print(bool, bool) const;
      
      virtual void fillSyllable(VexParser::SyllableArguments*) = 0;
      
    protected:
      std::string printRTYPE(bool first, bool last) const;
      std::string printISTYPE(bool first, bool last) const;
  };
}

#endif	/* SYLLABLEALU_H */

