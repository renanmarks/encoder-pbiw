/* 
 * File:   OperandVector.cpp
 * Author: helix
 *
 * Created on August 25, 2012, 2:24 PM
 */

#include "OperandVector.h"

namespace GenericAssembly
{
  namespace Utils
  {
    OperandVector::OperandVector()
    {
      
    }
    
    OperandVector::OperandVector(const OperandVector& other)
    {
      copy(other);
    }
    
    OperandVector::~OperandVector()
    {
      clear();
    }
    
    void OperandVector::copy(const OperandVector& orig)
    {
      Collection::const_iterator it;

      for (it = orig.begin(); it < orig.end(); it++) // O(|orig|)
        operands.push_back((*it)->clone());
    }
    
    void OperandVector::clear()
    {
      Collection::iterator it;

      for (it = operands.begin(); it < operands.end(); it++)
        delete *it;
      
      operands.clear();
    }
    
    OperandVector& 
    OperandVector::operator=(const OperandVector& other) // O(|operands| + |other|) = O(1)
    {
      if (this != &other)
      {
        clear();
        copy(other);
      }
      
      return *this;
    }
  }
}