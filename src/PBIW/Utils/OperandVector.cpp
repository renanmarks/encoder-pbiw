/* 
 * File:   OperandVector.cpp
 * Author: helix
 * 
 * Created on December 10, 2011, 8:22 PM
 */

#include "OperandVector.h"

namespace PBIW
{
  namespace Utils
  {

    OperandVector::OperandVector()
    {
      
    }

    OperandVector::OperandVector(const OperandVector& orig) // O(|orig|)
    {
      Collection::const_iterator it;

      for (it = orig.begin(); it < orig.end(); it++) // O(|orig|)
        operands.push_back(new OperandItem(**it));
    }

    OperandVector::~OperandVector()
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
        Collection::const_iterator it;

        for (it = operands.begin(); it < operands.end(); it++) 
          delete *it;
        
        operands.clear();
        
        for (it = other.begin(); it < other.end(); it++)
          operands.push_back(new OperandItem(**it));
      }
      
      return *this;
    }
  }
}