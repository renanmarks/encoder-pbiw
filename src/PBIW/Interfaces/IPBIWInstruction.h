/* 
 * File:   IPBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:24 PM
 */

#ifndef IPBIWINSTRUCTION_H
#define	IPBIWINSTRUCTION_H

#include <set>
#include <list>
#include <deque>
#include <vector>
#include "IOperand.h"
#include "IPBIWPattern.h"
#include "IPBIWPrinter.h"
#include "src/PBIW/Utils/OperandItemDTO.h"
#include "ILabel.h"
#include "src/GenericAssembly/Interfaces/IOperation.h"
#include "src/PBIW/Utils/OperandVector.h"

namespace PBIW
{
  namespace Interfaces
  {
    /**
     * A PBIW instruction interface.
     */
    class IPBIWInstruction
    {
      public:
        virtual ~IPBIWInstruction() { }
        
        /**
         * Deep copy this instruction.
         */
        virtual IPBIWInstruction* clone() const = 0;
        
        /**
         * Set instruction's absolute memory address.
         */
        virtual void setAddress(unsigned int) = 0;
        
        /**
         * Get instruction's absolute memory address.
         */
        virtual unsigned int getAddress() const = 0;
        
        /**
         * Set the label of this instruction
         */
        virtual void setLabel(const ILabel*) = 0;
        
        /**
         * Get the label of this instruction
         */
        virtual ILabel* getLabel() const = 0;
        
        /**
         * Points this instruction to its pattern.
         * @param The pattern referenced by this instruction
         */
        virtual void pointToPattern(IPBIWPattern&) = 0;
        
        virtual void setCodingOperation(IOperation& operation) = 0;
      
        virtual IOperation* getCodingOperation() const = 0;
        
        /**
         * Return the pattern that this instruction points to.
         * @return The pattern pointed by this instruction
         */
        virtual const IPBIWPattern* getPattern() const = 0;
        
        /**
         * Check if this instruction has the informed Operand.
         * Only compares the values, not the object itself.
         * @param The Operand
         * @return If found, the operand inside this instruction; otherwise, the
         * parameter passed.
         */
        virtual const IOperand& containsOperand(const IOperand&) const = 0;
        
        /**
         * Adds a operand to this instruction.
         * @param The Operand to be added.
         */
        virtual void addOperand(IOperand&) = 0;
        
        /**
         * Adds a read operand to this instruction.
         * @param The Operand to be added.
         */
        virtual void addReadOperand(IOperand&) = 0;
        
        /**
         * Adds a write operand to this instruction.
         * @param The Operand to be added.
         */
        virtual void addWriteOperand(IOperand&) = 0;
        
        /**
         * Defines the Branch Source Operand in the instruction
         */
        virtual void addBranchOperand(IOperand&) = 0;
        
        /**
         * TODO Description
         */
        virtual void setBranchSourceOperand(IOperand&) = 0;
        
        /**
         * Returns if there is an Branch Source Operand in the instruction
         */
        virtual bool hasBranchSourceOperand() const = 0;
        
        /**
         * Check if this instruction has a free operand slot (either read or
         * write operand).
         */
        virtual bool hasOperandSlot(const PBIW::Utils::OperandItemDTO&) = 0;
        
        virtual bool hasReadOperandSlot() const = 0;
        virtual bool hasWriteOperandSlot() const = 0;
        
        /**
         * Checks if this pattern contains a Control Operation (branch, etc)
         * and sets if it does.
         */
        virtual bool hasControlOperationWithLabelDestiny() = 0;
        
        /**
         * Gets the label of the branch destiny
         */
        virtual std::string getLabelDestiny() const = 0;
        
        /**
         * Sets the label of the branch destiny
         */
        virtual void setLabelDestiny(std::string) = 0;
        
        /**
         * Sets the PBIW instruction that contains the same label destiny
         * referenced by this instruction.
         */
        virtual void setBranchDestiny(const IPBIWInstruction& branchDestiny) = 0;

        /**
         * Gets the PBIW instruction that contains the same label destiny
         * referenced by this instruction.
         */
        virtual IPBIWInstruction* getBranchDestiny() const = 0;
        
        /**
         * Defines the immediate field.
         */
        virtual void setImmediateValue(int) = 0;
        
        /**
         * Return the quantity of read operands.
         */
        virtual int readOperandQuantity() const = 0;
        
        /**
         * Return the quantity of write operands.
         */
        virtual int writeOperandQuantity() const = 0;
        
        /**
         * Print this instruction using the specified printer.
         * @param An IPBIWPrinter
         */
        virtual void print(IPBIWPrinter&) const = 0;
        
        /**
         * Comparer or ordering the Operands in the Set implementation.
         */
        struct OperandComparer {
          bool operator() (const IOperand& lhs, const IOperand& rhs) const
          { return lhs < rhs; }
        };
        
        /**
         * Return a vector of all operands in this instruction.
         * @return An operand vector
         */
        virtual PBIW::Utils::OperandVector getOperands() const = 0;
        
        /**
         * Informs if the PBIW instruction contains immediate operand
         */
        virtual bool containsImmediate() const = 0;
        
        /**
         * Set the syllables that were codified in this instruction.
         */
        virtual void setOperationReferences(const std::list<GenericAssembly::Interfaces::IOperation*>&) = 0;
        
        /**
         * Returns the syllables that were codified in this instruction.
         */
        virtual std::list<GenericAssembly::Interfaces::IOperation*> getOperationReferences() const = 0;
       
        typedef std::vector<bool> AnnulationBits;
        virtual const AnnulationBits& getAnnulBits() const = 0;
        
        virtual void setAnnulBit(int, bool) = 0;
        
        virtual void setAnnulBits(const AnnulationBits& vectorBits) = 0;
        
//        virtual void setAnnulBits(std::deque<bool>* annulatioBits) = 0;
        
        virtual void updateAnnulBits(int index1, int index2) = 0;
    };

  }
}

#endif	/* IPBIWINSTRUCTION_H */
