/* 
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on July 10, 2012, 2:44 PM
 */

#ifndef OPERANDVECTOR_H
#define	OPERANDVECTOR_H

#include <deque>
#include <list>
#include <set>
#include <vector>
#include "src/PBIW/Interfaces/IOperand.h"

namespace PBIW
{
  namespace Utils
  {
    class OperandVector
    {
    public:
      typedef std::deque<Interfaces::IOperand*> Collection;
      
      OperandVector();
      OperandVector(const OperandVector& orig);
      virtual ~OperandVector();

      OperandVector& operator=(const OperandVector&);
      
//      template<class Enumerable>
//      void fill(Enumerable& enumerable);
      
      template <class TOperand>
      void fill(const std::list<TOperand>&);
      
      template <class TOperand>
      void fill(const std::vector<TOperand>&);
      
      template <class TOperand>
      void fill(const std::set<TOperand>&);
      
      template <class TOperand>
      void fill(const std::deque<TOperand>&);
      
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
      push_back(Interfaces::IOperand* operandItem)
      { operands.push_back(operandItem); }
      
    private:
      void copy(const OperandVector&);
      
      Collection operands;
    };
  }
}

#endif	/* OPERATIONVECTOR_H */

