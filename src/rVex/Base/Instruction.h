/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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
#include <deque>

#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "GenericAssembly/Interfaces/IInstruction.h"
#include "GenericAssembly/Interfaces/IOperation.h"

#include "rVex/Printers/IPrinter.h"
#include "rVex/Parser/Expressions/SyllableArguments.h"

#include "rVex/Utils/DependencyChains.h"

#include "Label.h"
#include "Operand.h"

namespace rVex
{
  // Begin Forwarding declarations
  namespace Utils
  {
    class OperandVectorBuilder;
  }
  
	namespace Base
	{

		class Syllable;
		// End Forwarding declarations

		/**
		 * The rVEX instruction class.
		 */
		class Instruction : public GenericAssembly::Interfaces::IInstruction
		{
			public:
				typedef std::deque<Syllable*> SyllableCollection;

				Instruction();
				~Instruction();

				virtual void addReferencePBIWInstruction(const PBIW::Interfaces::IPBIWInstruction&);
				virtual std::set<const PBIW::Interfaces::IPBIWInstruction*> getPBIWInstructions() const;

				bool addSyllable(Syllable&);
				bool removeSyllable(const Syllable&);

				virtual unsigned int getAddress() const;
				virtual void setAddress(unsigned int);

				void setLabel(rVex::Base::Label& label);
				bool haveLabels() const;
				LabelDeque getLabels() const;

				void print(rVex::Printers::IPrinter&) const;
				void printSyllableDependencies(rVex::Printers::IPrinter&) const;

				void minimizeOperationDependency();
				virtual void setOperations(OperationDeque&);
				virtual OperationDeque getOperations() const;
				SyllableCollection getSyllables() const;
				SyllableCollection getOrderedSyllables() const;

				unsigned int getQuantityNotNopOperations() const;

				void setWordAddress(unsigned int wordAddress);
				unsigned int getWordAddress() const;

				void buildSyllableDependencies();

				bool canSplitInstruction(const IOperation& operation) const;

			private:
				std::deque<rVex::Base::Label*> labels;
				SyllableCollection syllables;

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

					opADDCG  = 120, // from 120 to 127
					opDIVS   = 112, // from 112 to 119
					opSLCT   = 56, // from 56 to 63
					opSLCTF  = 48, // from 48 to 55

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

				/**
				 * The type of branch operand*/
				typedef struct {
					typedef enum {
						NONE, SOURCE, DESTINY
					} Type;
				} BranchOperand;

				typedef std::vector<Operand> OperandVector;


				virtual GenericAssembly::Utils::OperandVector exportOperandVector() const;

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

				virtual OperandVector getReadOperands() const;

				virtual void setShortImmediateValue(unsigned int shortImmediate);
				virtual unsigned int getShortImmediateValue() const;
				virtual Operand getShortImmediateOperand() const;

				virtual bool hasBrDestiny() const;
				virtual void setBrDestinyValue(unsigned char brDestiny);
				virtual unsigned char getBrDestinyValue() const;
				virtual Operand getBrDestinyOperand() const;

				virtual bool hasBrSource() const;
				virtual void setBrSourceValue(unsigned char brSource);
				virtual unsigned char getBrSourceValue() const;
				virtual Operand getBrSourceOperand() const;

				virtual bool hasGrDestiny() const;
				virtual void setGrDestinyValue(unsigned char grDestiny);
				virtual unsigned char getGrDestinyValue() const;
				virtual Operand getGrDestinyOperand() const;

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
				Operand grDestiny;
				bool haveGRDestiny;
				Operand brDestiny;
				bool haveBRDestiny;

				OperandVector readRegisters;
				Operand brSource;
				bool haveBRSource;
				Operand shortImmediate;

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
  
}

#endif	/* RVEXINSTRUCTION_H */

