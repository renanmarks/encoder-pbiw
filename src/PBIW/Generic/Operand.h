/* 
 * File:   Operand.h
 * Author: helix
 *
 * Created on July 23, 2012, 5:02 PM
 */

#ifndef PBIW_GENERIC_OPERAND_H
#define	PBIW_GENERIC_OPERAND_H

#include "src/PBIW/Interfaces/IOperand.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Operand : public IOperand
    {
    public:
      Operand();
      Operand(const Operand& orig);
      virtual ~Operand();
      
      virtual IOperand* clone() const;
      
      virtual void setIndex(unsigned int);
      virtual unsigned int getIndex() const;
      
      virtual bool isImmediate() const;
      
      virtual bool isImmediate9Bits() const;
      virtual void isImmediate9Bits(bool);
      
      virtual bool isImmediate12Bits() const;
      virtual void isImmediate12Bits(bool);
      
      virtual void setValue(int);
      virtual int getValue() const;
      
      virtual bool isBRSource() const;
      virtual void setBRSource(const bool);
      
      virtual bool isBRDestiny() const;
      virtual void setBRDestiny(const bool);

      virtual bool operator<(const IOperand&) const;
      virtual bool operator>(const IOperand&) const;
      virtual bool operator<=(const IOperand&) const;
      virtual bool operator>=(const IOperand&) const;
    
      virtual bool operator==(const IOperand&) const;
      virtual bool operator!=(const IOperand&) const;
    private:

    };
  }
}

#endif	/* OPERAND_H */

