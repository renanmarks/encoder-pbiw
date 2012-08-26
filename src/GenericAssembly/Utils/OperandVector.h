/* 
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on August 25, 2012, 2:24 PM
 */

#ifndef GENERICASSEMBLY_OPERANDVECTOR_H
#define	GENERICASSEMBLY_OPERANDVECTOR_H

#include <deque>
#include "DerivedFrom.h"
#include "src/GenericAssembly/Interfaces/IOperand.h"

namespace GenericAssembly
{
  namespace Utils
  {
    class OperandVector
    {
    public:
      typedef std::deque<const Interfaces::IOperand*> Collection;
      typedef Collection::iterator iterator;
      typedef Collection::const_iterator const_iterator;
      
      OperandVector();
      OperandVector(const OperandVector& orig);
      virtual ~OperandVector();

      OperandVector& operator=(const OperandVector&);
      
      /**
       * Fills in this operand vector with cloned operations.
       * This is used to expose only the operand interface for who will use it.
       */
      template<class TEnumerable>
      void fill(const TEnumerable& enumerable)
      {
        GenericAssembly::Utils::DerivedFrom<typename TEnumerable::value_type, Interfaces::IOperand>();
        
        typename TEnumerable::const_iterator it;

        for (it = enumerable.begin(); it != enumerable.end(); it++)
          operands.push_back((*it).clone());
      }
      
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
      
      Collection::reference
      operator[](int index)
      { return operands[index]; }
      
      Collection::const_reference
      operator[](int index) const
      { return operands[index]; }
      
      void
      push_back(const Interfaces::IOperand* operandItem)
      { operands.push_back(operandItem->clone()); }
      
      unsigned int
      size() const
      { return operands.size(); }
      
    private:
      void copy(const OperandVector&);
      
      Collection operands;
    };
  }
}

#endif	/* OPERANDVECTOR_H */

