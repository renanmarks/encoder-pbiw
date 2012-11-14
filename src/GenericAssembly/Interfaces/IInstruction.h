/* 
 * File:   IInstruction.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef GENERICASSEMBLY_IINSTRUCTION_H
#define	GENERICASSEMBLY_IINSTRUCTION_H

#include <deque>
#include <set>

#include "src/PBIW/Interfaces/IPBIWInstruction.h"

namespace GenericAssembly
{
  namespace Interfaces
  {
    class ILabel;
    class IOperation;
    
    class IInstruction
    {
    public:
      typedef std::deque<ILabel*> LabelDeque;
      typedef std::deque<IOperation*> OperationDeque;
      
      virtual ~IInstruction() { }

      virtual void addReferencePBIWInstruction(const PBIW::Interfaces::IPBIWInstruction&) = 0;
      virtual std::set<const PBIW::Interfaces::IPBIWInstruction*> getPBIWInstructions() const = 0;
      
      virtual unsigned int getAddress() const = 0;
      virtual void setAddress(unsigned int) = 0;
      
      /**
       * Informs if this assembly instruction is pointed by a label.
       */
      virtual bool haveLabels() const = 0;
      
      /**
       * Returns the label which points to this instruction.
       */
      virtual LabelDeque getLabels() const = 0;
      
      /**
       * Return an deque containing the pointers of the operations of the instruction.
       */
      virtual OperationDeque getOperations() const = 0;
      
      /**
       * Informs if this instruction can be splitted in others at the specified
       * operation. Useful when this instruction is a VLIW instruction that 
       * cannot be fully encoded in one PBIW instruction.
       */
      virtual bool canSplitInstruction(const IOperation& operation) const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IINSTRUCTION_H */

