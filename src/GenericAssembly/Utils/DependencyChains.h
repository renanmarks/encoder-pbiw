/* 
 * File:   DependencyChains.h
 * Author: helix
 *
 * Created on April 5, 2012, 3:55 PM
 */

#ifndef GENERICASSEMBLY_DEPENDENCYCHAINS_H
#define	GENERICASSEMBLY_DEPENDENCYCHAINS_H

#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include "src/GenericAssembly/Interfaces/IInstruction.h"
#include "src/GenericAssembly/Interfaces/IOperation.h"
#include "src/GenericAssembly/Interfaces/IPrinter.h"
#include "src/GenericAssembly/Utils/DerivedFrom.h"

namespace GenericAssembly
{
  namespace Utils
  {
    template <class TInstruction, class TOperation, class TPrinter>
    class DependencyChains
    {
    public:
      DependencyChains()
      {
        DerivedFrom<TInstruction,GenericAssembly::Interfaces::IInstruction>();
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        DerivedFrom<TPrinter,GenericAssembly::Interfaces::IPrinter<TInstruction, TOperation> >();
      }
      
      void buildDependenciesChains(const TInstruction& instruction)
      {
        DerivedFrom<TInstruction,GenericAssembly::Interfaces::IInstruction>();
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        
        std::vector<TOperation*> operations = instruction.getSyllables();
        typename std::vector<TOperation*>::iterator operationIt;

        // Fills all the inter-operation dependencies
        for(operationIt = operations.begin(); operationIt < operations.end(); operationIt++)
          dependencies[*operationIt] = getDependencies(*operationIt, operations);

        typename DependencyDictionary::iterator it;

        for(it = dependencies.begin(); it != dependencies.end(); it++)
        {
          bool hasTrueDependency = it->second.depends.size() > 0;

          if ( hasTrueDependency )
          {
            typename Dependency::OperationList::const_iterator opIt;

            for (opIt = it->second.depends.begin();
                opIt < it->second.depends.end();
                opIt++)
            {
              markSplits(*opIt, it->first);
            }
          }
          else if (it->second.isRealDependency == false)
            it->second.canSplit = true;
        }
      }
      
      
      void print(TPrinter& printer) const
      {
        DerivedFrom<TPrinter,GenericAssembly::Interfaces::IPrinter<TInstruction, TOperation> >();
        
        typename DependencyDictionary::const_iterator it;
      
        for(it = dependencies.begin(); it != dependencies.end(); it++)
        {
          printer.getOutputStream() << "Syllable " << it->first->getAddress()
            << " anti-depends (";

          typename Dependency::OperationList::const_iterator dependencyIt;

          for(dependencyIt = it->second.antiDepends.begin(); 
              dependencyIt < it->second.antiDepends.end(); 
              dependencyIt++)
          {
            printer.getOutputStream() << (*dependencyIt)->getAddress() << ", ";
          }

          printer.getOutputStream() << ") depends (";

          for(dependencyIt = it->second.depends.begin(); 
              dependencyIt < it->second.depends.end(); 
              dependencyIt++)
          {
            printer.getOutputStream() << (*dependencyIt)->getAddress() << ", ";
          }

          printer.getOutputStream() << ")";

          if (it->second.canSplit)
            printer.getOutputStream() << " Can split here!" << std::endl;
          else
            printer.getOutputStream() << " Can NOT split here!" << std::endl;
        }
      }
      
      bool canSplitSyllable(const TOperation* operation) const
      { 
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        
        return dependencies.find(operation)->second.canSplit; 
      }
      
    protected:
      /**
       * Class used to hold all the info of the dependencies and anti-dependencies
       * among the operations in a instruction.
       */
      struct Dependency
      {
        Dependency() : canSplit(false), isRealDependency(false) 
        {
          DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        }
        
        bool canSplit;
        bool isRealDependency;
        
        typedef std::deque<const TOperation*> OperationList;
        OperationList antiDepends;
        OperationList depends;
      };
      
      typedef std::map<const TOperation*, Dependency> DependencyDictionary;
      typedef std::pair<const TOperation*, Dependency> DepMapItem;
      
      /**
       * Functor to search an operation inside de list of operations
       * of the Dependency structure.
       */
      class SearchOperation : public std::unary_function<DepMapItem,bool> 
      {
      public:
        SearchOperation(unsigned int _address) : address(_address) {}

        bool operator() (DepMapItem item)
        {
          return item.first->getAddress() == address;
        }
        
      private:
        unsigned int address;
      };
      
      DependencyDictionary dependencies;
      
      void 
      markSplits(const TOperation* first, const TOperation* last)
      {
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        
        // Starting with the next element
        typename DependencyDictionary::iterator it = std::find_if(dependencies.begin(), dependencies.end(), SearchOperation(first->getAddress()+1));
        typename DependencyDictionary::iterator endIt = std::find_if(dependencies.begin(), dependencies.end(), SearchOperation(last->getAddress()));

        while(it != endIt)
        {
          it->second.canSplit = false;
          it->second.isRealDependency = true;

          it = std::find_if(dependencies.begin(), dependencies.end(), SearchOperation(it->first->getAddress()+1));
        }
      }
      
      virtual Dependency getDependencies(TOperation* const& operation, const std::vector<TOperation*>& operations) = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_DEPENDENCYCHAINS_H */

