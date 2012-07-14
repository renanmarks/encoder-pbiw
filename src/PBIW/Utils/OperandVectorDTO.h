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

