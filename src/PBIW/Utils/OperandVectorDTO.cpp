/* 
 * File:   OperandVector.cpp
 * Author: helix
 * 
 * Created on December 10, 2011, 8:22 PM
 */

#include "OperandVectorDTO.h"

namespace PBIW
{
  namespace Utils
  {

    OperandVectorDTO::OperandVectorDTO()
    {
      
    }

    OperandVectorDTO::OperandVectorDTO(const OperandVectorDTO& orig) // O(|orig|)
    {
      Collection::const_iterator it;

      for (it = orig.begin(); it < orig.end(); it++) // O(|orig|)
        operands.push_back(new OperandItemDTO(**it));
    }

    OperandVectorDTO::~OperandVectorDTO()
    {
      clear();
    }

    void OperandVectorDTO::clear()
    {
      Collection::iterator it;

      for (it = operands.begin(); it < operands.end(); it++)
        delete *it;
      
      operands.clear();
    }
    
    OperandVectorDTO& 
    OperandVectorDTO::operator=(const OperandVectorDTO& other) // O(|operands| + |other|) = O(1)
    {
      if (this != &other)
      {
        clear();
        
        Collection::const_iterator otherIt;
        
        for (otherIt = other.begin(); otherIt < other.end(); otherIt++)
          operands.push_back(new OperandItemDTO(**otherIt));
      }
      
      return *this;
    }
  }
}