/* 
 * File:   PBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef RVEX64PBIWINSTRUCTION_H
#define	RVEX64PBIWINSTRUCTION_H

#include <vector>
#include "Label.h"
#include "Interfaces/IPBIWInstruction.h"
#include "Interfaces/IOperand.h"
#include "rVex96PBIWPattern.h"
#include "src/rVex/Syllable.h"

namespace PBIW
{
  using namespace Interfaces;

    /**
     * r-VEX 64 bits length instruction 
     */
    class rVex64PBIWInstruction : public IPBIWInstruction
    {
    public:
      rVex64PBIWInstruction() : 
        address(0), 
        label(NULL), 
        branchDestiny(NULL), 
        pattern(NULL),
        codingOperation(NULL),
        opBRslot(-1),
        opBRFslot(-1),
        immediate(),
        zeroOperand(0)
      {
        zeroOperand.setIndex(15);
      }

      rVex64PBIWInstruction(const rVex64PBIWInstruction& other) : 
        address(other.address), 
        label(other.label),
        destinyLabel(other.destinyLabel),
        branchDestiny(other.branchDestiny), 
        pattern(other.pattern), 
        operands(other.operands),
        opBRslot(other.opBRslot),
        opBRFslot(other.opBRFslot),
        immediate(other.immediate),
        zeroOperand(other.zeroOperand),
        syllablesPacked(other.syllablesPacked)
      {
        zeroOperand.setIndex(15);
      }
        
      virtual ~rVex64PBIWInstruction();

      virtual IPBIWInstruction* clone() const;
      
      virtual void setAddress(unsigned int addr);

      virtual unsigned int getAddress() const;

      virtual void setLabel(const ILabel&);
      virtual ILabel* getLabel() const;

      virtual void pointToPattern(IPBIWPattern& pattern);
      
      virtual void setCodingOperation(IOperation& operation);
      
      virtual IOperation* getCodingOperation() const;

      virtual rVex96PBIWPattern* getPattern() const;

      virtual bool containsImmediate() const;

      virtual const IOperand& containsOperand(const IOperand&) const;

      virtual void addReadOperand(IOperand& operand);

      virtual void addBranchOperand(IOperand&);
      
      virtual bool hasBranchSourceOperand() const;

      virtual void addWriteOperand(IOperand& operand);

      virtual bool hasOperandSlot(const Utils::OperandItem&);
      virtual bool hasReadOperandSlot() const;
      virtual bool hasWriteOperandSlot() const;

      virtual bool hasControlOperationWithLabelDestiny();

      virtual std::string getLabelDestiny() const;

      virtual void setLabelDestiny(std::string label);

      virtual void setImmediateValue(int value);

      virtual int readOperandQuantity() const;
      virtual int writeOperandQuantity() const;

      virtual void print(IPBIWPrinter&) const;

      virtual OperandVector getOperands() const;

      virtual void setSyllableReferences(const std::list<GenericAssembly::Interfaces::IOperation*>& list);

      virtual std::list<GenericAssembly::Interfaces::IOperation*> getSyllableReferences() const;

      virtual void setBranchDestiny(const IPBIWInstruction& branchDestiny);

      virtual rVex64PBIWInstruction* getBranchDestiny() const
      { return branchDestiny; }

      void setOpBRFslot(IOperand&);

      void setOpBRslot(IOperand&);

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

      ILabel* label;
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
      OperandVector operands; // Max 12
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
      
      /**
     * Functor used to find a operand that has value between 0 and 7.
     */
      class Find3BitsOperand : public std::unary_function<Operand, bool>
      {
      public:
          bool operator()(const Operand& t) const 
          { return (t.getValue() < 8) && (t.getIndex() < 11) && !t.isBRSource() && !t.isBRDestiny(); }
      };
      
      unsigned int giveEmptySlot() const;
    };
}

#endif	/* RVEX64FULLPBIWINSTRUCTION_H */

