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
      virtual ~ALUSyllable() { };
      
      virtual bool operator==(const SyllableMEM& other) const = 0;
      virtual bool operator!=(const SyllableMEM& other) const = 0;
  };
}

#endif	/* SYLLABLEMEM_H */

