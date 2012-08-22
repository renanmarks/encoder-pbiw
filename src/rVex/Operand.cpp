/* 
 * File:   Operand.cpp
 * Author: helix
 * 
 * Created on August 18, 2012, 10:57 PM
 */

#include "Operand.h"
#include "Syllable.h"

namespace rVex
{

  Operand::Operand()
    : type(GRSource), value(0)
  {
  }

  Operand::Operand(int value)
   : type(GRSource), value(value)
  {
  }
  
  Operand::Operand(Type type)
   : type(type), value(0)
  {
  }
  
  Operand::Operand(Type type, int value)
   : type(type), value(value)
  {
  }
  
  Operand::Operand(const Operand& other)
   : type(other.type), value(other.value), syllableBelonged(other.syllableBelonged)
  {
  }

  bool 
  Operand::operator==(const IOperand& other) const
  {
    const Operand& otherConverted = dynamic_cast<const Operand&>(other);
    
    bool equals = this->value == otherConverted.getValue()
      && this->type == otherConverted.getType()
      && this->syllableBelonged == static_cast<Syllable*>(otherConverted.getOperationBelonged());
    
    return equals;
  }
  
  bool 
  Operand::operator!=(const IOperand& other) const
  {
    return !(*this == other);
  }
  
  GenericAssembly::Interfaces::IOperand*
  Operand::clone()
  {
    return new Operand(*this);
  }

  void
  Operand::setType(Type typeCode)
  {
    type = typeCode;
  }

  Operand::Type
  Operand::getType() const
  {
    return type;
  }
  
  void
  Operand::setTypeCode(int typeCode)
  {
    type = static_cast<Type>(typeCode);
  }

  int
  Operand::getTypeCode() const
  {
    return static_cast<int>(type);
  }

  bool 
  Operand::isImmediate(Type type) const
  {
    if (type == Imm9 || type == Imm12)
      return this->type == type;
    
    return false;
  }
  
  bool 
  Operand::isRegister(Type type) const
  {
    if (type != Imm9 && type != Imm12)
      return this->type == type;
    
    return false;
  }
  
  bool
  Operand::isImmediate() const
  {
    return (type == Imm9 || type == Imm12);
  }

  bool
  Operand::isRegister() const
  {
    return !isImmediate();
  }

  void
  Operand::setValue(int value)
  {
    this->value = value;
  }

  int
  Operand::getValue() const
  {
    return this->value;
  }
  
  void 
  Operand::setOperationBelonged(GenericAssembly::Interfaces::IOperation* operation)
  {
    syllableBelonged = dynamic_cast<Syllable*>(operation);
  }
  
  GenericAssembly::Interfaces::IOperation* 
  Operand::getOperationBelonged() const
  {
    return syllableBelonged;
  }
}
