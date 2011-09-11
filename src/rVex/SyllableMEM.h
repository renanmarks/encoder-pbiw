/* 
 * File:   ALUSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLEMEM_H
#define	SYLLABLEMEM_H

#include "Syllable.h"

namespace rVex
{
  /**
   * A r-Vex instruction MEM syllable (operation)
   */
  class SyllableMEM : public Syllable
  {
    public:
      virtual ~SyllableMEM() { };
      
      virtual bool operator==(const Syllable& other) const;
      virtual bool operator!=(const Syllable& other) const;
  };
}

#endif	/* SYLLABLEMEM_H */

