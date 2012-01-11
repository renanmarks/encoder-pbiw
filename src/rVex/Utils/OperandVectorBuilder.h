/* 
 * File:   OperandVectorBuilder.h
 * Author: helix
 *
 * Created on December 18, 2011, 5:33 PM
 */

#ifndef OPERANDVECTORBUILDER_H
#define	OPERANDVECTORBUILDER_H

#include "src/PBIW/Utils/OperandItem.h"
#include "src/PBIW/Utils/OperandVector.h"

namespace rVex
{
  namespace Utils
  {
    using PBIW::Utils::OperandVector;
    using PBIW::Utils::OperandItem;
    using PBIW::Operand;
    
    class OperandVectorBuilder
    {
    public:
//      OperandVectorBuilder();
//      OperandVectorBuilder(const OperandVectorBuilder& orig);
//      virtual ~OperandVectorBuilder();
      
      void insertRegister(int value, OperandItem::Type type);
      void insertRegisters(const std::vector<unsigned int>& values, OperandItem::Type type);
      void insertImmediate(int value, Operand::Immediate::Type);
      
      const OperandVector& getOperandVector() const
      { return items; }
      
    private:
      OperandVector items;
    };
  }
}

#endif	/* OPERANDVECTORBUILDER_H */
