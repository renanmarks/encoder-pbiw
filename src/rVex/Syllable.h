/* 
 * File:   rVexSyllabe.h
 * Author: helix
 *
 * Created on July 23, 2011, 5:08 PM
 */

#ifndef RVEXSYLLABE_H
#define	RVEXSYLLABE_H

#include <string>
#include "../VexParser/Expressions/SyllableArguments.h"

namespace rVex
{
  // Forwarding declaration
  class Instruction;
  
  /**
   * A r-Vex instruction syllable (operation)
   */
  class Syllable
  {
    public:
      Syllable() : labelDestiny(NULL) { }
      virtual ~Syllable() { }
      
      /**
       * The execution type of syllable*/
      typedef enum { 
        ALU = 1, MUL, MEM, CTRL
      } Type;

      /**
       * The layout type of syllable (if it is a register type, immediate type,
       * branch type, etc). */
      typedef enum {
        RTYPE = 1, ISTYPE, ILTYPE, BRANCH, RTYPE_BS, MEMTYPE 
      } LayoutType;

      /**
       * The immediate switch of syllable */
      typedef enum { 
        NO_IMM, SHORT_IMM, BRANCH_IMM, LONG_IMM 
      } ImmediateSwitch;
      
      virtual void setLayoutType(Syllable::LayoutType layoutType) 
      { this->layoutType=layoutType; }
      
      virtual LayoutType getLayoutType() const
      { return layoutType; }

      virtual void addReadRegister(unsigned int);
      virtual std::vector<unsigned int> getReadRegisters() const 
      { return this->readRegisters; }

      virtual void setShortImmediate(unsigned short shortImmediate) 
      { this->shortImmediate=shortImmediate; }
      
      virtual unsigned short getShortImmediate() const 
      { return shortImmediate; }

      virtual void setBrDestiny(unsigned char brDestiny) 
      { this->brDestiny=brDestiny; }
      
      virtual unsigned char getBrDestiny() const 
      { return brDestiny; }
      
      virtual void setBrSource(unsigned char brSource) 
      { this->brSource=brSource; }
      
      virtual unsigned char getBrSource() const 
      { return brSource; }

      virtual void setGrDestiny(unsigned char grDestiny) 
      { this->grDestiny=grDestiny; }
      
      virtual unsigned char getGrDestiny() const 
      { return grDestiny; }
      
      virtual void setLabel(std::string label)
      { this->label = label; }
      
      virtual std::string getLabel() const
      { return this->label; }
      
      virtual void setLabelDestiny(Instruction* instructionDestiny)
      { this->labelDestiny = instructionDestiny; }
      
      virtual Instruction* getLabelDestiny() const
      { return this->labelDestiny; }
      
      virtual void setPath(std::string path)
      { this->path = path; }
      
      virtual std::string getPath() const
      { return this->path; }
      
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
//      virtual LayoutType getLayoutType() const = 0;
      
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
       * Set the arguments and the syllable data with the arguments
       */
      virtual void fillSyllable(VexParser::SyllableArguments*) = 0;
      
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
      
      Syllable::LayoutType layoutType;
      unsigned char grDestiny;
      unsigned char brDestiny;
      
      typedef std::vector<unsigned int> readRegVector;
      readRegVector readRegisters;
      unsigned char brSource;
      unsigned short shortImmediate;
      
      std::string label;
      Instruction* labelDestiny;
      
      std::string path;
      
      virtual void fillTypeI(VexParser::SyllableArguments*);
      virtual void fillTypeII(VexParser::SyllableArguments*);
      virtual void fillTypeIII(VexParser::SyllableArguments*);
      virtual void fillTypeIV(VexParser::SyllableArguments*);
      virtual void fillTypeV(VexParser::SyllableArguments*);
      virtual void fillTypeVI(VexParser::SyllableArguments*);
      virtual void fillTypeVII(VexParser::SyllableArguments*);
      virtual void fillTypeVIII(VexParser::SyllableArguments*);
      virtual void fillTypeIX(VexParser::SyllableArguments*);
      virtual void fillTypeX(VexParser::SyllableArguments*);
      virtual void fillTypeXI(VexParser::SyllableArguments*);
      virtual void fillTypeXII(VexParser::SyllableArguments*);
      virtual void fillTypeXIII(VexParser::SyllableArguments*);
      virtual void fillTypeXIV(VexParser::SyllableArguments*); // Only opcode
      virtual void fillTypeXV(VexParser::SyllableArguments*);
      virtual void fillTypeXVI(VexParser::SyllableArguments*);
      virtual void fillTypeXVII(VexParser::SyllableArguments*);
      virtual void fillTypeXVIII(VexParser::SyllableArguments*);
      virtual void fillTypeXIX(VexParser::SyllableArguments*);
      virtual void fillTypeXX(VexParser::SyllableArguments*);
  };
}

#endif	/* RVEXSYLLABE_H */

