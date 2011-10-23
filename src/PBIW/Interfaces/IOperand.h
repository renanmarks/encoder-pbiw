/* 
 * File:   IOperand.h
 * Author: helix
 *
 * Created on October 19, 2011, 2:03 PM
 */

#ifndef IOPERAND_H
#define	IOPERAND_H

namespace PBIW
{
  namespace Interfaces
  {

    /**
     * Class that represents an operand in a PBIW instruction
     */
    class IOperand
    {
    public:
      virtual ~IOperand() {}
      
      virtual void setIndex(unsigned int) = 0;
      virtual unsigned int getIndex() const = 0;

      virtual bool operator==(const IOperand&) const = 0;
      virtual bool operator!=(const IOperand&) const = 0;
    };
  }
}

#endif	/* IOPERAND_H */

