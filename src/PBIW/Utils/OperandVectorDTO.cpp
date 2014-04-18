/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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