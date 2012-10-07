/* 
 * File:   OperandVectorBuilder.cpp
 * Author: helix
 * 
 * Created on December 18, 2011, 5:33 PM
 */

#include <deque>
#include <vector>
#include "OperandVectorBuilder.h"

namespace rVex
{
  namespace Utils
  {

//    OperandVectorBuilder::OperandVectorBuilder(IOperation::GenericAssembly::Utils::OperandVector& deque);
//    : deque(deque)
//    {
//
//    }

    void 
    OperandVectorBuilder::clearOperandVector()
    {
      operands.clear();
    }

    GenericAssembly::Utils::OperandVector
    OperandVectorBuilder::getOperandVector()
    {
      return operands;
    }
  }
}