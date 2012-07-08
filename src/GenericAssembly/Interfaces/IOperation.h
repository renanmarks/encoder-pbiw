/* 
 * File:   IOperation.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef GENERICASSEMBLY_IOPERATION_H
#define	GENERICASSEMBLY_IOPERATION_H

#include <string>

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IInstruction;
    
    class IOperation
    {
    public:
      virtual ~IOperation() { }
      
      virtual void setBelongedInstruction(IInstruction* instruction) = 0;
      virtual IInstruction* getBelongedInstruction() const = 0;
      
      virtual unsigned int getAddress() const = 0;
      virtual void setAddress(unsigned int address) = 0;
      
      virtual void setLayoutType(int layoutType) = 0;
      
      virtual unsigned int getOpcode() const = 0;
      virtual bool isOpcode(unsigned int opcode) const = 0;
      
      virtual void setTextRepresentation(std::string textRepresentation) = 0;
      virtual std::string getTextRepresentation() const = 0;
      
      /**
       * Fills up the builder passed as argument with the operands from this
       * operation to be used at the PBIW encoding process.
       */
      //virtual void exportOperandVector(/*Utils::OperandVectorBuilder&*/) const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IOPERATION_H */

