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
 * File:   PBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef PBIWFULL_RVEX64PBIWINSTRUCTION_H
#define	PBIWFULL_RVEX64PBIWINSTRUCTION_H

#include <vector>
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IOperand.h"
#include "PBIW/Utils/OperandVector.h"
#include "rVex/Base/Syllable.h"
#include "rVex/Utils/OperandVectorBuilder.h"
#include "rVex96PBIWPattern.h"
#include "Operand.h"
#include "Label.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

    /**
     * r-VEX 64 bits length instruction 
     */
    class rVex64PBIWInstruction : public IPBIWInstruction
    {
    public:
      rVex64PBIWInstruction() : 
        address(0),
        branchDestiny(NULL), 
        pattern(NULL),
        codingOperation(NULL),
        opBRslot(-1),
        opBRFslot(-1),
        immediate(),
        zeroOperand(0),
        annulBits(4,false)
      {
        zeroOperand.setIndex(0);
        operands.push_back(zeroOperand);
      }

      rVex64PBIWInstruction(const rVex64PBIWInstruction& other) : 
        address(other.address), 
        labels(other.labels),
        destinyLabel(other.destinyLabel),
        branchDestiny(other.branchDestiny), 
        pattern(other.pattern), 
        operands(other.operands),
        opBRslot(other.opBRslot),
        opBRFslot(other.opBRFslot),
        immediate(other.immediate),
        zeroOperand(other.zeroOperand),
        syllablesPacked(other.syllablesPacked),
        annulBits(other.annulBits)
      {
        zeroOperand.setIndex(0);
      }

      virtual ~rVex64PBIWInstruction() { }

      virtual IPBIWInstruction* clone() const;
      
      virtual void setAddress(unsigned int addr);
      virtual unsigned int getAddress() const;

      virtual void setLabel(const ILabel*);
      virtual std::deque<ILabel*> getLabels() const;

      virtual void pointToPattern(IPBIWPattern& pattern);
      
      virtual void setCodingOperation(IOperation& operation);
      virtual IOperation* getCodingOperation() const;

      virtual rVex96PBIWPattern* getPattern() const;

      virtual bool containsImmediate() const;

      virtual const IOperand& containsOperand(const IOperand&) const;

      virtual void addOperand(IOperand&);
      virtual void addReadOperand(IOperand&);
      virtual void addWriteOperand(IOperand&);

      virtual void addBranchOperand(IOperand&);
      
      virtual void setBranchSourceOperand(IOperand&);
      virtual bool hasBranchSourceOperand() const;

      virtual bool hasOperandSlot(const PBIW::Utils::OperandItemDTO&);
      virtual bool hasReadOperandSlot() const;
      virtual bool hasWriteOperandSlot() const;

      virtual bool hasControlOperationWithLabelDestiny();

      virtual std::string getLabelDestiny() const;

      virtual void setLabelDestiny(std::string label);

      virtual void setImmediateValue(int value);

      virtual int readOperandQuantity() const;
      virtual int writeOperandQuantity() const;

      virtual void print(IPBIWPrinter&) const;

      virtual PBIW::Utils::OperandVector getOperands() const;

      virtual void setOperationReferences(const std::list<GenericAssembly::Interfaces::IOperation*>& list);

      virtual std::list<GenericAssembly::Interfaces::IOperation*> getOperationReferences() const;

      virtual void setBranchDestiny(const IPBIWInstruction& branchDestiny);

      virtual rVex64PBIWInstruction* getBranchDestiny() const
      { return branchDestiny; }

      void setOpBRFslot(IOperand&);

      void setOpBRslot(IOperand&);
            
      virtual const AnnulationBits& getAnnulBits() const
      {     return this->annulBits;    }
      
      virtual void setAnnulBit(int index, bool value)
      {     annulBits[index] = value;   }
      
      virtual void setAnnulBits(const AnnulationBits& vectorBits)
      {     annulBits = vectorBits;     }
      
      virtual void updateAnnulBits(int index1, int index2);
      
      /**
     * Exception thrown when the an encoding mismatch exception occurs;
     */
      class CodingMismatchException : public std::exception
      {
      public:
        CodingMismatchException( );

        explicit
        CodingMismatchException( std::string reason ) throw () : reason( reason )
        { }

        virtual
        ~CodingMismatchException( ) throw ()
        { };

        virtual const char*
        what( ) const throw ()
        { return reason.c_str(); }

      private:
        std::string reason;
      };

    private:
      unsigned int address;

      std::deque<ILabel*> labels;
      std::string destinyLabel;
      rVex64PBIWInstruction* branchDestiny;

      rVex96PBIWPattern* pattern;
      Operation* codingOperation;

      /* The readRegs organization is as follows:

        ,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,_3b__,
        ------------------------------------------------------------------------------------
        | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-7 |
        ------------------------------------------------------------------------------------
        '------------------------- Br src ----------------------'      '----9b imm---'
                                           '  BR  ' BRF  '             '-------12b imm-----'
       */
      
      std::deque<Operand> operands; // Max 12
      Operand opBRslot;
      Operand opBRFslot;
      
      virtual int giveEmptyBranchSourceSlot();
      void setBranchSlot(const Operand&, Operand&);
      void updateIndexes(int oldIndex, int newIndex);

      Operand immediate; // (9 or 12 bit immediates)
      Operand zeroOperand;

      /**
       * Keeps track of what syllables were packed in this instruction
       */
      typedef std::list<rVex::Syllable*> SyllableList;
      SyllableList syllablesPacked;
      
      AnnulationBits annulBits;

      /**
     * Functor used to find a operand that has value between 0 and 7.
     */
      class Find3BitsOperand : public std::unary_function<Operand, bool>
      {
      public:
          bool operator()(const Operand& t) const 
          { return (t.getValue() < 8) && (t.getValue() != 0) && (t.getIndex() < 11) && (t.getIndex() != 0) && !t.isBRSource() && !t.isBRDestiny(); }
      };
      
      unsigned int giveEmptySlot() const;
    };
}

#endif	/* RVEX64FULLPBIWINSTRUCTION_H */

