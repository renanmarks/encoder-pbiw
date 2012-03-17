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
      
      virtual bool isImmediate() const = 0;
      virtual bool isImmediate9Bits() const = 0;
      virtual bool isImmediate12Bits() const = 0;
      
      virtual void setValue(int) = 0;
      virtual int getValue() const = 0;
      
      virtual bool isBRSource() const = 0;
      virtual void setBRSource(const bool) = 0;
      
      virtual bool isBRDestiny() const = 0;
      virtual void setBRDestiny(const bool) = 0;

      virtual bool operator<(const IOperand&) const = 0;
      virtual bool operator>(const IOperand&) const = 0;
      virtual bool operator<=(const IOperand&) const = 0;
      virtual bool operator>=(const IOperand&) const = 0;
    
      virtual bool operator==(const IOperand&) const = 0;
      virtual bool operator!=(const IOperand&) const = 0;
    };
  }
}

#endif	/* IOPERAND_H */

