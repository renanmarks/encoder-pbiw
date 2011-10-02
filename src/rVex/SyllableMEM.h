/* 
 * File:   ALUSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLEMEM_H
#define	SYLLABLEMEM_H

#include <vector>
#include "Syllable.h"

namespace rVex
{
  /**
   * A r-Vex instruction MEM syllable (operation)
   */
  class SyllableMEM : public Syllable
  {
    public:
      virtual ~SyllableMEM() { }
      
      virtual std::string print(bool, bool) const;
      
      virtual void fillSyllable(VexParser::SyllableArguments*) = 0;
  };
}

#endif	/* SYLLABLEMEM_H */

