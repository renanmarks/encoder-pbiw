/* 
 * File:   ALUSyllable.h
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
      virtual ~SyllableALU() { };
      
      virtual std::vector<int> getReadRegisters() const = 0;
  };
}

#endif	/* SYLLABLEALU_H */

