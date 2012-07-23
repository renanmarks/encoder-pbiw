/* 
 * File:   Instruction.h
 * Author: helix
 *
 * Created on July 23, 2012, 3:22 PM
 */

#ifndef PBIW_GENERIC_INSTRUCTION_H
#define	PBIW_GENERIC_INSTRUCTION_H

#include "src/PBIW/Interfaces/IPBIWInstruction.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    /**
     * Generic, flexible PBIW instruction for use in the generic PBIW encoding
     * algorithm.
     */
    class Instruction : public IPBIWInstruction
    {
    public:
      Instruction();
      Instruction(const Instruction& orig);
      virtual ~Instruction();
      
      virtual IPBIWInstruction* clone() const;

      virtual void setAddress(unsigned int);
      virtual unsigned int getAddress() const;

      virtual void setLabel(const ILabel*);
      virtual ILabel* getLabel() const;

      virtual void pointToPattern(IPBIWPattern&);

      virtual void setCodingOperation(IOperation& operation);
      virtual IOperation* getCodingOperation() const;

      virtual const IPBIWPattern* getPattern() const;

      virtual const IOperand& containsOperand(const IOperand&) const;

      virtual void addReadOperand(IOperand&);

      virtual void addBranchOperand(IOperand&);

      virtual void setBranchSourceOperand(IOperand&);

      virtual bool hasBranchSourceOperand() const;

      virtual void addWriteOperand(IOperand&);

      virtual bool hasOperandSlot(const PBIW::Utils::OperandItemDTO&);

      virtual bool hasReadOperandSlot() const;
      virtual bool hasWriteOperandSlot() const;

      virtual bool hasControlOperationWithLabelDestiny();

      virtual std::string getLabelDestiny() const;

      virtual void setLabelDestiny(std::string);

      virtual void setBranchDestiny(const IPBIWInstruction& branchDestiny);

      virtual IPBIWInstruction* getBranchDestiny() const;

      virtual void setImmediateValue(int);

      virtual int readOperandQuantity() const;

      virtual int writeOperandQuantity() const;

      virtual void print(IPBIWPrinter&) const;

      virtual PBIW::Utils::OperandVector getOperands() const;

      virtual bool containsImmediate() const;

      virtual void setOperationReferences(const std::list<GenericAssembly::Interfaces::IOperation*>&);

      virtual std::list<GenericAssembly::Interfaces::IOperation*> getOperationReferences() const;

      virtual const AnnulationBits& getAnnulBits() const;

      virtual void setAnnulBit(int, bool);
      virtual void setAnnulBits(const AnnulationBits& vectorBits);

      virtual void updateAnnulBits(int index1, int index2);
      
    private:

    };
  }
}

#endif	/* INSTRUCTION_H */

