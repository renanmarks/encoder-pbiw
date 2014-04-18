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
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on December 10, 2011, 8:22 PM
 */

#ifndef OPERANDVECTORDTO_H
#define	OPERANDVECTORDTO_H

#include <vector>
#include "OperandItemDTO.h"

namespace PBIW
{
  namespace Utils
  {
    class OperandVectorDTO
    {
    public:
      OperandVectorDTO();
      OperandVectorDTO(const OperandVectorDTO& orig);
      virtual ~OperandVectorDTO();
    
      typedef std::vector<OperandItemDTO*> Collection;
      
      OperandVectorDTO& operator=(const OperandVectorDTO&);
      
      /*
       * Wrapper methods to internal vector.
       */
      
      void
      clear();
      
      Collection::iterator
      begin()
      { return operands.begin(); }

      Collection::const_iterator
      begin() const
      { return operands.begin(); }

      Collection::iterator
      end()
      { return operands.end(); }

      Collection::const_iterator
      end() const
      { return operands.end(); }

      Collection::reverse_iterator
      rbegin()
      { return operands.rbegin(); }

      Collection::const_reverse_iterator
      rbegin() const
      { return operands.rbegin(); }

      Collection::reverse_iterator
      rend()
      { return operands.rend(); }

      Collection::const_reverse_iterator
      rend() const
      { return operands.rend(); }
      
      void
      push_back(OperandItemDTO* operandItem)
      { operands.push_back(operandItem); }
      
    private:
      
      Collection operands;
    };
  }
}

#endif	/* OPERANDVECTOR_H */

