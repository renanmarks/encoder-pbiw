/* 
 * File:   OperandVectorBuilder.h
 * Author: helix
 *
 * Created on December 18, 2011, 5:33 PM
 */

#ifndef OPERANDVECTORBUILDER_H
#define	OPERANDVECTORBUILDER_H

#include "src/PBIW/Utils/OperandItemDTO.h"
#include "src/PBIW/Utils/OperandVectorDTO.h"
#include "src/PBIW/Interfaces/IPBIWFactory.h"
#include "src/PBIW/Interfaces/IOperand.h"
#include "src/rVex/Syllable.h"

namespace rVex
{
  namespace Utils
  {
    using PBIW::Utils::OperandVectorDTO;
    using PBIW::Utils::OperandItemDTO;
    using PBIW::Interfaces::IPBIWFactory;
    using PBIW::Interfaces::IOperand;
    
    class OperandVectorBuilder
    {
    public:
      OperandVectorBuilder(const PBIW::Interfaces::IPBIWFactory& factory);
      
      void insertRegister(int value, OperandItemDTO::Type type, const GenericAssembly::Interfaces::IOperation*);
      void insertRegisters(const std::vector<unsigned int>& values, OperandItemDTO::Type type, const GenericAssembly::Interfaces::IOperation*);
      void insertImmediate(int value, rVex::Syllable::ImmediateSwitch::Type, const GenericAssembly::Interfaces::IOperation*);
      
      void clearOperandVector()
      { items.clear(); }
      
      const OperandVectorDTO& getOperandVector();
      
    private:
      OperandVectorDTO items;
      const IPBIWFactory& factory;
    };
  }
}

#endif	/* OPERANDVECTORBUILDER_H */

