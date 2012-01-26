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

    //    OperandVectorBuilder::OperandVectorBuilder()
    //    {
    //      
    //    }
    //
    //    OperandVectorBuilder::OperandVectorBuilder(const OperandVectorBuilder& orig)
    //    {
    //      
    //    }
//    OperandVectorBuilder::~OperandVectorBuilder()
//    {
//      OperandVector::Collection::iterator it;
//
//      for (it=items.begin(); it < items.end(); it++)
//        delete *it;
//    }

    void
    OperandVectorBuilder::insertRegister(int value, OperandItem::Type type) // O(1)
    {
      Operand* operand = new Operand(value);
      OperandItem* item = new OperandItem(operand, type);
      
      items.push_back(item);
    }

    void
    OperandVectorBuilder::insertImmediate(int value, Operand::Immediate::Type immType) // O(1)
    {
      Operand* operand = new Operand(value, immType);
      OperandItem* item = new OperandItem(operand, OperandItem::Imm);
      
      items.push_back(item);
    }

    void
    OperandVectorBuilder::insertRegisters(const std::vector<unsigned int>& values, OperandItem::Type type) // O(1)
    {
      std::vector<unsigned int>::const_iterator it;

      for (it=values.begin(); it < values.end(); it++) // O(1)
      {
        Operand* operand = new Operand(*it);
        OperandItem* item = new OperandItem(operand, type);
        items.push_back(item);
      }
    }
    
    const OperandVector& OperandVectorBuilder::getOperandVector()
    { 
      return items; 
    }
  }
}