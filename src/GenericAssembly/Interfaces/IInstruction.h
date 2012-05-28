/* 
 * File:   IInstruction.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef IINSTRUCTION_H
#define	IINSTRUCTION_H

namespace GenericAssembly
{
  namespace Interfaces
  {
    class ILabel;
    class IOperation;
    
    class IInstruction
    {
    public:
      typedef std::deque<IOperation*> OperationVector;
      
      virtual ~IInstruction() { }

      /**
       * Informs if this assembly instruction is pointed by a label.
       */
      virtual bool haveLabel() const = 0;
      
      /**
       * Returns the label which points to this instruction.
       */
      ILabel* getLabel() const = 0;
      
      /**
       * Return an deque containing the pointers of the operations of the instruction.
       */
      virtual OperationVector getOperations() const = 0;
      
      /**
       * Informs if this instruction can be splitted in others at the specified
       * operation. Useful when this instruction is a VLIW instruction that 
       * cannot be fully encoded in one PBIW instruction.
       */
      virtual bool canSplitInstruction(const IOperation& operation) const = 0;
    };
  }
}

#endif	/* IINSTRUCTION_H */

