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
      
      /**
       * The execution type of syllable*/
      enum Type { 
        ALU = 1, MUL, MEM, CTRL 
      };

      /**
       * The layout type of syllable (if it is a register type, immediate type,
       * branch type, etc). */
      enum LayoutType {
        RTYPE = 1, ISTYPE, ILTYPE, BRANCH, RTYPE_BS, MEMTYPE 
      };

      /**
       * The immediate switch of syllable */
      enum ImmediateSwitch { 
        NO_IMM, SHORT_IMM, BRANCH_IMM, LONG_IMM 
      };
      
      /**
       * Get the syllable Opcode.
       * 
       * @return The syllable Opcode
       */
      virtual unsigned int getOpcode() const = 0;
      
      /**
       * Get the type of syllable: ALU, MUL, MEM or CTRL.
       * 
       * @return Type of syllable.
       */
      virtual Type getSyllableType() const = 0;
      
      /**
       * Get the structure/layout type of a syllable.
       * The structure type is how a syllable is built.
       * More info at: 
       * http://code.google.com/p/r-vex/source/browse/trunk/doc/syllable_layout.txt
       * 
       * @return the structure type of a syllable
       */
      virtual LayoutType getLayoutType() const = 0;
      
      /**
       * Prints the binary representation of the syllable in string format.
       * 
       * @param True if the syllable is the first in the instruction.
       * @param True if the syllable is the last in the instruction.
       * @return String containing the binary representation of the syllable.
       */
      virtual std::string print(bool, bool) const = 0;
 
      virtual bool operator==(const Syllable&) const = 0;
      virtual bool operator!=(const Syllable&) const = 0;
      
    /**
     * Exception throwed when the syllable layout is not supported by the
     * syllable.
     * @param reason
     */
      class LayoutNotSupportedException : public std::exception
      {
        public:
          LayoutNotSupportedException() ;
          explicit LayoutNotSupportedException(std::string reason) throw() : reason(reason) { }
          virtual ~LayoutNotSupportedException() throw() {};

          virtual const char* what() const throw() { return reason.c_str(); }

        private:
          std::string reason;
      };
      
    protected:
      /**
       * Prints a unsigned integer into a binary string containing 0's and 1's.
       * 
       * @param An integer
       * @return A std::string containing binary digits
       */
      std::string printBinary(unsigned int, bool, bool) const;
  };
}

#endif	/* RVEXSYLLABE_H */

