/* 
 * File:   IOperation.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef GENERICASSEMBLY_IOPERATION_H
#define	GENERICASSEMBLY_IOPERATION_H

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IOperation
    {
    public:
      virtual ~IOperation() { }
      
      /**
       * Fills up the builder passed as argument with the operands from this
       * operation to be used at the PBIW encoding process.
       */
      virtual void exportOperandVector(/*Utils::OperandVectorBuilder&*/) const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IOPERATION_H */

