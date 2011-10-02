/* 
 * File:   MULSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLEMUL_H
#define	SYLLABLEMUL_H

#include <vector>
#include "Syllable.h"

namespace rVex
{
  /**
   * A r-Vex instruction MUL syllable (operation)
   */
  class SyllableMUL : public Syllable
  {
    public:
      virtual ~SyllableMUL() { }
      
      virtual std::string print(bool, bool) const;
      
      virtual void fillSyllable(VexParser::SyllableArguments*) = 0;
  };  
}

#endif	/* SYLLABLEMUL_H */

