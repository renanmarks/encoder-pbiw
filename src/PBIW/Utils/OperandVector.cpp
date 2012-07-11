/* 
 * File:   OperationVector.cpp
 * Author: helix
 * 
 * Created on July 10, 2012, 2:44 PM
 */

#include "OperandVector.h"
#include "src/GenericAssembly/Utils/DerivedFrom.h"

namespace PBIW
{
  namespace Utils
  {

    OperandVector::OperandVector()
    {
      
    }

    OperandVector::OperandVector(const OperandVector& orig)
    {
      copy(orig);
    }

    OperandVector::~OperandVector()
    {
      clear();
    }
    
    template <class TOperand>
    void OperandVector::fill(const std::list<TOperand>& temp)
    {
//      fill(temp);
      
      GenericAssembly::Utils::DerivedFrom<TOperand, PBIW::Interfaces::IOperand>();
      typename std::list<TOperand>::const_iterator it;
      
      for (it = temp.begin(); it != temp.end(); it++)
        operands.push_back((*it)->clone());
    }

    template <class TOperand>
    void OperandVector::fill(const std::vector<TOperand>& temp)
    {
//      fill(temp);
      
      GenericAssembly::Utils::DerivedFrom<TOperand, PBIW::Interfaces::IOperand>();
      typename std::vector<TOperand>::const_iterator it;
      
      for (it = temp.begin(); it != temp.end(); it++)
        operands.push_back((*it)->clone());
    }

    template <class TOperand>
    void OperandVector::fill(const std::set<TOperand>& temp)
    {
//      fill(temp);
      
      GenericAssembly::Utils::DerivedFrom<TOperand, PBIW::Interfaces::IOperand>();
      typename std::set<TOperand>::const_iterator it;
      
      for (it = temp.begin(); it != temp.end(); it++)
        operands.push_back((*it)->clone());
    }

    template <class TOperand>
    void OperandVector::fill(const std::deque<TOperand>& temp)
    {
      //fill(temp);
      
      GenericAssembly::Utils::DerivedFrom<TOperand, PBIW::Interfaces::IOperand>();
      typename std::deque<TOperand>::const_iterator it;
      
      for (it = temp.begin(); it != temp.end(); it++)
        operands.push_back((*it)->clone());
    }
    
//    template<class TEnumerable>
//    void OperandVector::fill(TEnumerable& enumerable)
//    {
//      GenericAssembly::Utils::DerivedFrom<typename TEnumerable::value_type, PBIW::Interfaces::IOperand>();
//      typename TEnumerable::const_iterator it;
//      
//      for (it = enumerable.begin(); it != enumerable.end(); it++)
//        operands.push_back((*it)->clone());
//    }
    
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