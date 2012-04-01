/* 
 * File:   OperandVectorBuilder.cpp
 * Author: helix
 * 
 * Created on December 18, 2011, 5:33 PM
 */

#include "OperandVectorBuilder.h"

namespace rVex
{
  namespace Utils
  {
    void
    OperandVectorBuilder::insertRegister(int value, OperandItem::Type type, const rVex::Syllable* syllable) // O(1)
    {
      Operand* operand = new Operand(value);
      operand->setBRSource(type == OperandItem::BRSource);
      operand->setBRDestiny(type == OperandItem::BRDestiny);
      
      OperandItem* item = new OperandItem(operand, type, syllable);
      
      items.push_back(item);
    }

    void
    OperandVectorBuilder::insertImmediate(int value, Operand::Immediate::Type immType, const rVex::Syllable* syllable) // O(1)
    {
      Operand* operand = new Operand(value, immType);
      OperandItem* item = new OperandItem(operand, OperandItem::Imm, syllable);
      
      items.push_back(item);
    }

    void
    OperandVectorBuilder::insertRegisters(const std::vector<unsigned int>& values, OperandItem::Type type, const rVex::Syllable* syllable) // O(1)
    {
      std::vector<unsigned int>::const_iterator it;

      for (it=values.begin(); it < values.end(); it++) // O(1)
        insertRegister(*it, type, syllable);
    }
    
    const OperandVector& OperandVectorBuilder::getOperandVector()
    { 
      return items; 
    }
  }
}