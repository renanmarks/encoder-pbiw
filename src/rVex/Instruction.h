/* 
 * File:   rVexInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:19 PM
 */

#ifndef RVEXINSTRUCTION_H
#define	RVEXINSTRUCTION_H

#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <string>

#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "src/GenericAssembly/Interfaces/IInstruction.h"
//#include "src/GenericAssembly/Interfaces/IOperation.h"

#include "src/rVex/Printers/IPrinter.h"
#include "src/VexParser/Expressions/SyllableArguments.h"

#include "Utils/OperandVectorBuilder.h"
#include "Utils/DependencyChains.h"

#include "Label.h"

namespace rVex
{
  class Syllable;
  
  class Instruction : public GenericAssembly::Interfaces::IInstruction
  {
    public:
      typedef std::vector<Syllable*> SyllableVector;
      //typedef std::set<const PBIW::Interfaces::IPBIWInstruction*> PBIWInstructionSet;
      
      Instruction();
      ~Instruction();
      
      virtual void addReferencePBIWInstruction(const PBIW::Interfaces::IPBIWInstruction&);
      virtual std::set<const PBIW::Interfaces::IPBIWInstruction*> getPBIWInstructions() const;
      
      bool addSyllable(Syllable&);
      bool removeSyllable(const Syllable&);
      
      virtual unsigned int getAddress() const;
      virtual void setAddress(unsigned int);
      
      void setLabel(rVex::Label& label);
      bool haveLabel() const;
      rVex::Label* getLabel() const;
      
      void print(rVex::Printers::IPrinter&) const;
      void printSyllableDependencies(rVex::Printers::IPrinter&) const;
      
      SyllableVector getSyllables() const;
      SyllableVector getOrderedSyllables() const;

      unsigned int getQuantityNotNopOperations() const;

      void setWordAddress(unsigned int wordAddress);
      unsigned int getWordAddress() const;
      
      void buildSyllableDependencies(); 
     
      bool canSplitSyllable(const Syllable* syllable) const;
      
    private:
      rVex::Label* label;
      SyllableVector syllables;

      std::set<const PBIW::Interfaces::IPBIWInstruction*> pbiwInstructions;
      
      Utils::DependencyChains dependencies;
      
      unsigned int address; // instruction address, aligned by 16 bytes
      unsigned int wordAddress; // word address, aligned by 4 bytes
  };
  
  
  
  /**
   * A r-Vex instruction syllable (operation)
   */
  class Syllable : public GenericAssembly::Interfaces::IOperation
  {
    public:
      Syllable();
      virtual ~Syllable();
      
      /**
       * Syllables opcodes
       */
      typedef enum {
        opNOP    = 0x00000000,
        

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
//          opADDCG  = 121, 
//          opADDCG  = 122, 
//          opADDCG  = 123, 
//          opADDCG  = 124, 
//          opADDCG  = 125, 
//          opADDCG  = 126, 
//          opADDCG  = 127, 
          
        opDIVS   = 112,
//          opDIVS   = 113,
//          opDIVS   = 114,
//          opDIVS   = 115,
//          opDIVS   = 116,
//          opDIVS   = 117,
//          opDIVS   = 118,
//          opDIVS   = 119,
          
        opSLCT   = 56,
//          opSLCT   = 57,
//          opSLCT   = 58,
//          opSLCT   = 59,
//          opSLCT   = 60,
//          opSLCT   = 61,
//          opSLCT   = 62,
//          opSLCT   = 63,
          
        opSLCTF  = 48,
//          opSLCTF  = 49,
//          opSLCTF  = 50,
//          opSLCTF  = 51,
//          opSLCTF  = 52,
//          opSLCTF  = 53,
//          opSLCTF  = 54,
//          opSLCTF  = 55,

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

        /* r-Vex exclusive operation */
        opSTOP   = 31,
          
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
      
      typedef std::vector<unsigned int> ReadRegVector;
      
      virtual void exportOperandVector(Utils::OperandVectorBuilder&) const;
      
      unsigned int getAddress() const;
      void setAddress(unsigned int);
      
      virtual void setBelongedInstruction(IInstruction*);
      virtual Instruction* getBelongedInstruction() const;
      
      virtual ImmediateSwitch::Type getImmediateSwitch() const;
      
      virtual void addReadRegister(unsigned int);
      
      /**
       * Get the structure/layout type of a syllable.
       * The structure type is how a syllable is built.
       * More info at: 
       * http://code.google.com/p/r-vex/source/browse/trunk/doc/syllable_layout.txt
       * 
       * @return the structure type of a syllable
       */ 
      virtual LayoutType::Type getLayoutType() const;
      virtual void setLayoutType(Syllable::LayoutType::Type);
      virtual void setLayoutType(int);
      
      virtual ReadRegVector getReadRegisters() const;

      virtual void setShortImmediate(unsigned short shortImmediate);
      virtual unsigned short getShortImmediate() const;

      virtual bool hasBrDestiny() const;
      virtual void setBrDestiny(unsigned char brDestiny);
      virtual unsigned char getBrDestiny() const;
      
      virtual bool hasBrSource() const;
      virtual void setBrSource(unsigned char brSource);
      virtual unsigned char getBrSource() const;

      virtual bool hasGrDestiny() const;
      virtual void setGrDestiny(unsigned char grDestiny);
      virtual unsigned char getGrDestiny() const;
      
      virtual void setLabelDestiny(std::string label);
      virtual std::string getLabelDestiny() const;
      
      virtual void setBranchDestiny(Syllable* syllableDestiny);
      virtual Syllable* getBranchDestiny() const;
      
      virtual void setPath(std::string path);
      virtual std::string getPath() const;
      
      virtual void setTextRepresentation(std::string textRepresentation);
      virtual std::string getTextRepresentation() const;
      
      /**
       * Get the syllable Opcode.
       * In the ADDCG, DIVS, SCLT and SCLTF syllables, this includes the
       * BRSrc field.
       * @return The syllable Opcode
       */
      virtual unsigned int getOpcode() const = 0;
      
      /**
       * Returns true if the opcode is the same asked.
       * This method is useful when trying to know
       * if the syllable is one of ADDCG, DIVS, SCLT or SCLTF syllables.
       */
      virtual bool isOpcode(unsigned int opcode) const;
      virtual bool isOpcode(SyllableOpcode opcode) const;
      
      /**
       * Get the type of syllable: ALU, MUL, MEM or CTRL.
       * @return Type of syllable.
       */
      virtual SyllableType::Type getSyllableType() const = 0;
      
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
      virtual void fillSyllable(VexParser::SyllableArguments&) = 0;
      
      unsigned int printRTYPE(bool, bool) const;
      unsigned int printISTYPE(bool, bool) const;
      unsigned int printILTYPE(bool, bool) const;
      unsigned int printBRANCH(bool, bool) const;
      unsigned int printRTYPE_BS(bool, bool) const;
      unsigned int printMEMLOADTYPE(bool, bool) const;
      unsigned int printMEMSTORETYPE(bool, bool) const;
      
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
      bool haveGRDestiny;
      unsigned char brDestiny;
      bool haveBRDestiny;
      
      ReadRegVector readRegisters;
      unsigned char brSource;
      bool haveBRSource;
      unsigned short shortImmediate;
      
      std::string labelDestiny;
      Syllable* branchDestiny;
      
      std::string path;
      std::string textRepresentation;
      
      virtual void fillTypeI(VexParser::SyllableArguments&);
      virtual void fillTypeII(VexParser::SyllableArguments&);
      virtual void fillTypeIII(VexParser::SyllableArguments&);
      virtual void fillTypeIV(VexParser::SyllableArguments&);
      virtual void fillTypeV(VexParser::SyllableArguments&);
      virtual void fillTypeVI(VexParser::SyllableArguments&);
      virtual void fillTypeVII(VexParser::SyllableArguments&);
      virtual void fillTypeVIII(VexParser::SyllableArguments&);
      virtual void fillTypeIX(VexParser::SyllableArguments&);
      virtual void fillTypeX(VexParser::SyllableArguments&);
      virtual void fillTypeXI(VexParser::SyllableArguments&);
      virtual void fillTypeXII(VexParser::SyllableArguments&);
      virtual void fillTypeXIII(VexParser::SyllableArguments&);
      virtual void fillTypeXIV(VexParser::SyllableArguments&); // Only opcode
      virtual void fillTypeXV(VexParser::SyllableArguments&);
      virtual void fillTypeXVI(VexParser::SyllableArguments&);
      virtual void fillTypeXVII(VexParser::SyllableArguments&);
      virtual void fillTypeXVIII(VexParser::SyllableArguments&);
      virtual void fillTypeXIX(VexParser::SyllableArguments&);
      virtual void fillTypeXX(VexParser::SyllableArguments&);
  };
}

#endif	/* RVEXINSTRUCTION_H */

