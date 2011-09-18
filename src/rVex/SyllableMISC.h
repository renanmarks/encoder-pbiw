/* 
 * File:   SyllableMISC.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 01:01
 */

#ifndef SYLLABLEMISC_H
#define	SYLLABLEMISC_H

#include "Syllable.h"

namespace rVex
{
  /**
   * A r-Vex instruction MISC syllable (operation)
   */
  class SyllableMISC : public Syllable
  {
    public:
      virtual ~SyllableMISC() { }
      
      virtual bool operator==(const Syllable& other) const;
      virtual bool operator!=(const Syllable& other) const;
      virtual LayoutType getLayoutType() const { return layoutType; }
      
      virtual std::string print(bool, bool) const;
  private:
      Syllable::LayoutType layoutType;
  };
}

#endif	/* SYLLABLEMISC_H */

