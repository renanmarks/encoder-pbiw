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
      clear();
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
        
        Collection::const_iterator otherIt;
        
        for (otherIt = other.begin(); otherIt < other.end(); otherIt++)
          operands.push_back(new OperandItem(**otherIt));
      }
      
      return *this;
    }
  }
}