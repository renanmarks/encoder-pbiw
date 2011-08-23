/* 
 * File:   rVexSyllabe.h
 * Author: helix
 *
 * Created on July 23, 2011, 5:08 PM
 */

#ifndef RVEXSYLLABE_H
#define	RVEXSYLLABE_H

#include <string>

namespace rVex
{
  /**
   * A r-Vex instruction syllable (operation)
   */
  class Syllable
  {
    public:
      virtual ~Syllable() { };
      
      enum Type { 
        ALU = 1, MUL, MEM, CTRL 
      };

      enum LayoutType {
        RTYPE = 1, ISTYPE, ILTYPE, BRANCH, RTYPE_BS, MEMTYPE 
      };

      enum ImmediateSwitch { 
        NO_IMM, SHORT_IMM, BRANCH_IMM, LONG_IMM 
      };
      
      /**
       * Get the syllable Opcode.
       * 
       * @return The syllable Opcode
       */
      virtual int getOpcode() const = 0;
      
      /**
       * Get the type of syllable: ALU, MUL, MEM or CTRL.
       * 
       * @return Type of syllable.
       */
      virtual Type getSyllableType() const = 0;
      
      /**
       * Get the structure/layout type of a syllable.
       * The structure type is how a syllable is built.
       * More info at: http://code.google.com/p/r-vex/source/browse/trunk/doc/syllable_layout.txt
       * 
       * @return the structure type of a syllable
       */
      virtual LayoutType getLayoutType() const = 0;
      
      /**
       * Prints the binary representation of the syllable in string format.
       * 
       * @return String containing the binary representation of the syllable.
       */
      virtual std::string print() const = 0;
 
      virtual bool operator==(const Syllable&) const = 0;
      virtual bool operator!=(const Syllable&) const = 0;
  };
}

#endif	/* RVEXSYLLABE_H */

