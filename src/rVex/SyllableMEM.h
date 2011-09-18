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
      SyllableMEM();
      SyllableMEM(LayoutType, unsigned char, unsigned char, unsigned short);
      virtual ~SyllableMEM() { };
      
      virtual void setLayoutType(Syllable::LayoutType);
      virtual LayoutType getLayoutType() const { return layoutType; }

      virtual void addReadRegister(unsigned int);
      virtual std::vector<unsigned int> getReadRegisters() const;

      virtual void setShortImmediate(unsigned short);
      virtual unsigned short getShortImmediate() const;

      virtual void setBrDestiny(unsigned char);
      virtual unsigned char getBrDestiny() const;

      virtual void setGrDestiny(unsigned char);
      virtual unsigned char getGrDestiny() const;
      
      virtual bool operator==(const Syllable&) const;
      virtual bool operator!=(const Syllable&) const;
      
      virtual std::string print(bool, bool) const;
    
    private:
      Syllable::LayoutType layoutType;
      unsigned char grDestiny;
      unsigned char brDestiny;
      typedef std::vector<unsigned int> readRegVector;
      readRegVector readRegisters;
      unsigned short shortImmediate;
      
      std::string printRTYPE(bool first, bool last) const;
      std::string printISTYPE(bool first, bool last) const;
    
  };
}

#endif	/* SYLLABLEMEM_H */

