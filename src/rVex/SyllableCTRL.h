/* 
 * File:   ALUSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLECTRL_H
#define	SYLLABLECTRL_H

#include "Syllable.h"

namespace rVex
{
  /**
   * A r-Vex instruction CTRL syllable (operation)
   */
  class SyllableCTRL : public Syllable
  {
    public:
      virtual bool operator==(const Syllable& other) const;
      virtual bool operator!=(const Syllable& other) const;
      virtual LayoutType getLayoutType() const { return layoutType; }
      
      virtual std::string print(bool, bool) const;
      
      virtual void fillSyllable(VexParser::SyllableArguments*) = 0;
      
    protected:
      Syllable::LayoutType layoutType;
  };
}

#endif	/* ALUSYLLABLE_H */

