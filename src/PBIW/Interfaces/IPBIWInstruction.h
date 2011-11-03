/* 
 * File:   IPBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:24 PM
 */

#ifndef IPBIWINSTRUCTION_H
#define	IPBIWINSTRUCTION_H

#include "IOperand.h"
#include "IPBIWPattern.h"
#include "IPBIWPrinter.h"

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
        virtual ~IPBIWInstruction() {}
        
        /**
         * Points this instruction to its pattern.
         * @param The pattern referenced by this instruction
         */
        virtual void pointToPattern(IPBIWPattern*) = 0;
        
        /**
         * Return the pattern that this instruction points to.
         * @return The pattern pointed by this instruction
         */
        virtual IPBIWPattern* getPattern() const = 0;
        
        /**
         * Check if this instruction has the informed Operand.
         * Only compares the values, not the object itself.
         * @param The Operand
         */
        virtual bool containsOperand(const IOperand&) const = 0;
        
        /**
         * Adds a read operand to this instruction.
         * @param The Operand to be added.
         */
        virtual void addReadOperand(IOperand*) = 0;
        
        /**
         * Adds a write operand to this instruction.
         * @param The Operand to be added.
         */
        virtual void addWriteOperand(IOperand*) = 0;
        
        /**
         * Check if this instruction has a free operand slot (either read or
         * write operand).
         */
        virtual bool hasOperandSlot() const = 0;
        
        /**
         * Print this instruction using the specified printer.
         * @param An IPBIWPrinter
         */
        virtual void print(IPBIWPrinter&) const = 0;
        
        
        typedef std::vector<IOperand*> OperandVector;
        
        /**
         * Return a vector of all operands in this instruction.
         * @return An operand vector
         */
        virtual OperandVector getOperands() const = 0;
    };

  }
}

#endif	/* IPBIWINSTRUCTION_H */

