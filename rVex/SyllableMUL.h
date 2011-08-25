/* 
 * File:   ALUSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLEMUL_H
#define	SYLLABLEMUL_H

#include "Syllable.h"

namespace rVex
{
  /**
   * A r-Vex instruction MUL syllable (operation)
   */
  class SyllableMUL : public Syllable
  {
    public:
      virtual ~SyllableMUL() { };
      
      virtual bool operator==(const Syllable& other) const;
      virtual bool operator!=(const Syllable& other) const;
  };
}

#endif	/* SYLLABLEMUL_H */

