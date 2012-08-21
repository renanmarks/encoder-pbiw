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

//    OperandVectorBuilder::OperandVectorBuilder(IOperation::OperandConstPtrDeque& deque);
//    : deque(deque)
//    {
//
//    }

    void 
    OperandVectorBuilder::clearOperandVector()
    {
      deque.clear();
    }

    GenericAssembly::Interfaces::IOperation::OperandConstPtrDeque
    OperandVectorBuilder::getOperandVector()
    {
      return deque;
    }
  }
}