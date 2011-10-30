/* 
 * File:   rVexSyllabe.h
 * Author: helix
 *
 * Created on July 23, 2011, 5:08 PM
 */

#ifndef RVEXSYLLABE_H
#define	RVEXSYLLABE_H

#include <utility>
#include <string>
#include "Label.h"

#include "src/PBIW/Operand.h"
#include "../VexParser/Expressions/SyllableArguments.h"
#include "src/Interfaces/IPrinter.h"

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
      Syllable() : 
      address(-1),
      layoutType(),
      grDestiny(),
      brDestiny(),
      brSource(),
      shortImmediate(),
      labelDestiny(NULL)
      {}
      
      virtual ~Syllable() { }
      
      /**
       * Syllables opcodes
       */
      typedef enum {
        opNOP    = 0x00000000,
        opSTOP   = 53,

        /* ALU opcodes */
        opADD    = 65,
        opAND    = 67,
        opANDC   = 68,
        opMAX    = 69,
        opMAXU   = 70,
        opMIN    = 71,
        opMINU   = 72,
        opOR     = 73,
        opORC    = 74,
        opSH1ADD = 75,
        opSH2ADD = 76,
        opSH3ADD = 77,
        opSH4ADD = 78,
        opSHL    = 79,
        opSHR    = 80,
        opSHRU   = 81,
        opSUB    = 82,
        opSXTB   = 83,
        opSXTH   = 84,
        opZXTB   = 85,
        opZXTH   = 86,
        opXOR    = 87,
        opMOV    = 88,

        opCMPEQ  = 89,
        opCMPGE  = 90,
        opCMPGEU = 91,
        opCMPGT  = 92,
        opCMPGTU = 93,
        opCMPLE  = 94,
        opCMPLEU = 95,
        opCMPLT  = 96,
        opCMPLTU = 97,
        opCMPNE  = 98,
        opNANDL  = 99,
        opNORL   = 100,
        opORL    = 102,
        opMTB    = 103,
        opANDL   = 104,

        opADDCG  = 120,
        opDIVS   = 112,
        opSLCT   = 56,
        opSLCTF  = 48,

        /* MUL opcodes */
        opMPYLL  =  1,
        opMPYLLU =  2,
        opMPYLH  =  3,
        opMPYLHU =  4,
        opMPYHH  =  5,
        opMPYHHU =  6,
        opMPYL   =  7,
        opMPYLU  =  8,
        opMPYH   =  9,
        opMPYHU  = 10,
        opMPYHS  = 11,

        /* Control opcodes */
        opGOTO   = 33,
        opIGOTO  = 34,
        opCALL   = 35,
        opICALL  = 36,
        opBR     = 37,
        opBRF    = 38,
        opRETURN = 39,
        opRFI    = 40,
        opXNOP   = 41,

        opSEND   = 42,
        opRECV   = 43,

        /* Memory opcodes */
        opLDW    = 17,
        opLDH    = 18,
        opLDHU   = 19,
        opLDB    = 20,
        opLDBU   = 21,
        opSTW    = 22,
        opSTH    = 23,
        opSTB    = 24,
        opPFT    = 25,
      } SyllableOpcode;
      
      /**
       * The execution type of syllable*/
      typedef struct {
        typedef enum {
          ALU = 1, MUL, MEM, CTRL
        } Type;
      } SyllableType;

      /**
       * The layout type of syllable (if it is a register type, immediate type,
       * branch type, etc). */
      typedef struct {
        typedef enum {
          RTYPE = 1, ISTYPE, ILTYPE, BRANCH, RTYPE_BS, MEMTYPE 
        } Type;
      } LayoutType;

      
      
      /**
       * The immediate switch of syllable */
      typedef struct {
        typedef enum { 
          NO_IMM, SHORT_IMM, BRANCH_IMM, LONG_IMM 
        } Type;
      } ImmediateSwitch;
      
      // ---
      
      /**
       * Used by the PBIW Algorithm. Provides an vector
       * with all the operands (destiny, source and immediate) inside.
       */
      typedef struct {
        typedef enum {
          GRSource, GRDestiny, BRSource, BRDestiny, Imm
        } Type;
      } OperandType;
      
      typedef std::pair<PBIW::Interfaces::IOperand*, OperandType::Type> OperandItem;
      typedef std::vector<OperandItem> OperandVector;
      
      OperandVector getOperandVector() const;
      
      // ---
      
      typedef std::vector<unsigned int> ReadRegVector;
      
      // ---
      
      void setBelongedInstruction(rVex::Instruction* instruction)
      { this->belongedInstruction = instruction; }
      
      rVex::Instruction* getBelongedInstruction() const
      { return this->belongedInstruction; }
      
      unsigned int getAddress() const
      { return this->address; }
      
      void setAddress(unsigned int address)
      { this->address = address; }
      
      virtual void setLayoutType(Syllable::LayoutType::Type layoutType) 
      { this->layoutType=layoutType; }
      
      virtual LayoutType::Type getLayoutType() const
      { return layoutType; }

      virtual void addReadRegister(unsigned int);
      virtual ReadRegVector getReadRegisters() const 
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
      { this->labelStringDestiny = label; }
      
      virtual std::string getLabel() const
      { return this->labelStringDestiny; }
      
      virtual void setLabelDestiny(Syllable* syllableDestiny)
      { this->labelDestiny = syllableDestiny; }
      
      virtual Syllable* getLabelDestiny() const
      { return this->labelDestiny; }
      
      virtual void setPath(std::string path)
      { this->path = path; }
      
      virtual std::string getPath() const
      { return this->path; }
      
      /**
       * Get the syllable Opcode.
       * @return The syllable Opcode
       */
      virtual unsigned int getOpcode() const = 0;
      
      /**
       * Get the type of syllable: ALU, MUL, MEM or CTRL.
       * @return Type of syllable.
       */
      virtual SyllableType::Type getSyllableType() const = 0;
      
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
       * @param True if the syllable is the first in the instruction.
       * @param True if the syllable is the last in the instruction.
       * @return String containing the binary representation of the syllable.
       */
      virtual void print(rVex::Printers::IPrinter&, bool, bool) const = 0;
 
      virtual bool operator==(const Syllable&) const;
      virtual bool operator!=(const Syllable&) const;
      
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
      Instruction* belongedInstruction;
      unsigned int address;
      
      Syllable::LayoutType::Type layoutType;
      unsigned char grDestiny;
      unsigned char brDestiny;
      
      ReadRegVector readRegisters;
      unsigned char brSource;
      unsigned short shortImmediate;
      
      std::string labelStringDestiny;
      Syllable* labelDestiny;
      
      std::string path;
      
      unsigned int printRTYPE() const;
      unsigned int printISTYPE() const;
      unsigned int printILTYPE() const;
      unsigned int printBRANCH() const;
      unsigned int printRTYPE_BS() const;
      unsigned int printMEMLOADTYPE() const;
      unsigned int printMEMSTORETYPE() const;
      
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

