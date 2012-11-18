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
#include <set>
#include <vector>
#include <iostream>
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
      
      DependencyChains(const DependencyChains& other)
       : dependencies(other.dependencies)
      {
        DerivedFrom<TInstruction,GenericAssembly::Interfaces::IInstruction>();
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        DerivedFrom<TPrinter,GenericAssembly::Interfaces::IPrinter<TInstruction, TOperation> >();
      }
      
      DependencyChains& operator=(const DependencyChains& other)
      {
        this->dependencies = other.dependencies;
      }
      
      void sortOperations(TInstruction& instruction)
      {
        std::deque<GenericAssembly::Interfaces::IOperation*> sortedOperations;
        std::set<TOperation*> nodesNotDependency;
        
        typename DependencyDictionary::iterator itDependency;
        
        // Set of all nodes with no incoming edges
        for(itDependency = dependencies.begin(); 
            itDependency != dependencies.end(); 
            itDependency++)
        {
          nodesNotDependency.insert(itDependency->first);
        }
        
        // Set of all nodes with no incoming edges
        for(itDependency = dependencies.begin(); 
            itDependency != dependencies.end(); 
            itDependency++)
        {
          typename Dependency::OperationSet::iterator itOperation;

          for (itOperation = itDependency->second.depends.begin();
                itOperation != itDependency->second.depends.end(); 
                itOperation++)
          {
            nodesNotDependency.erase(*itOperation);
          }
        }
        
        //while 'nodesNotDependency' is non-empty do
        while (nodesNotDependency.size() > 0)
        {
          //remove a node 'operation' from 'nodesNotDependency'
          TOperation* operationN = *(nodesNotDependency.begin());
          nodesNotDependency.erase(operationN);
          
          //insert 'operation' into 'sortedOperations'
          sortedOperations.push_back(operationN); 
          
          typename Dependency::OperationSet::iterator itOperation = 
            dependencies[operationN].depends.begin();

          while(itOperation != dependencies[operationN].depends.end())
          {
            typename Dependency::OperationSet::iterator current = itOperation++;
            
            TOperation* operationM = *current;
            
            //remove edge e from the graph
            dependencies[operationN].depends.erase(current);

            //if 'operation' has no other incoming edges 
            //then insert 'operation' into 'nodesNotDependency'

            std::set<TOperation*> operationSet;

            typename DependencyDictionary::iterator it1;

            for(it1 = dependencies.begin(); 
                it1 != dependencies.end();
                it1++)
            {
              operationSet.insert(it1->second.depends.begin(), it1->second.depends.end());
            }

            bool hasNoMoreEdges = (operationSet.find(operationM) == operationSet.end());
            
            if ( operationM != NULL && hasNoMoreEdges )
              nodesNotDependency.insert(operationM);
          }
        }
        
        for(itDependency = dependencies.begin(); 
            itDependency != dependencies.end(); 
            itDependency++)
        {
          bool graphHasEdges = itDependency->second.depends.size() > 0;
          
          //if graph has edges then
          if (graphHasEdges)
          {
            print(std::cout);
            throw DependencyGraphException("Operations contains circular dependency.");
          }
        }
        
        if (sortedOperations.size() == 0)
          return; // No need to sort operations
        
        instruction.setOperations(sortedOperations);
        
        return; // TOPOLOGICALLY SORTED
      }
      
      class DependencyGraphException : public std::exception
      {
        public:
          DependencyGraphException() {}
          explicit DependencyGraphException(std::string reason) throw() 
            : reason(reason) { }
          virtual ~DependencyGraphException() throw() {};

          virtual const char* what() const throw() { return reason.c_str(); }

        private:
          std::string reason;
      };
      
      void buildDependenciesChains(const TInstruction& instruction)
      {
        DerivedFrom<TInstruction,GenericAssembly::Interfaces::IInstruction>();
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        
        GenericAssembly::Interfaces::IInstruction::OperationDeque ioperations = instruction.getOperations();
        GenericAssembly::Interfaces::IInstruction::OperationDeque::iterator iopIt;
        
        std::deque<TOperation*> operations;
        
        for(iopIt = ioperations.begin(); iopIt != ioperations.end(); iopIt++)
          operations.push_back( static_cast<TOperation*>(*iopIt) );
        
        typename std::deque<TOperation*>::iterator operationIt;

        // Fills all the inter-operation dependencies
        for(operationIt = operations.begin(); operationIt < operations.end(); operationIt++)
          dependencies[*operationIt] = getDependencies(*operationIt, operations);

        typename DependencyDictionary::iterator it;

        for(it = dependencies.begin(); it != dependencies.end(); it++)
        {
          bool hasTrueDependency = it->second.depends.size() > 0;

          if ( hasTrueDependency )
          {
            typename Dependency::OperationSet::const_iterator opIt;

            for (opIt = it->second.depends.begin();
                opIt != it->second.depends.end();
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
        
        print(printer.getOutputStream());
      }
      
      bool canSplitSyllable(const TOperation& operation) const
      { 
        DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        
        return dependencies.find( &const_cast<TOperation&>(operation) )->second.canSplit; 
      }
      
    protected:
      
      void print(std::ostream& stream) const
      {
        typename DependencyDictionary::const_iterator it;
      
        for(it = dependencies.begin(); it != dependencies.end(); it++)
        {
          stream << "Operation " << it->first->getAddress() << " anti-depends (";

          typename Dependency::OperationSet::const_iterator dependencyIt;

          for(dependencyIt = it->second.antiDepends.begin(); 
              dependencyIt != it->second.antiDepends.end(); 
              dependencyIt++)
          {
            stream << (*dependencyIt)->getAddress() << ", ";
          }

          stream << ") depends (";

          for(dependencyIt = it->second.depends.begin(); 
              dependencyIt != it->second.depends.end(); 
              dependencyIt++)
          {
            stream << (*dependencyIt)->getAddress() << ", ";
          }

          stream << ")";

          if (it->second.canSplit)
            stream << " Can split here!" << std::endl;
          else
            stream << " Can NOT split here!" << std::endl;
        }
      }
      
      /**
       * Class used to hold all the info of the dependencies and anti-dependencies
       * among the operations in a instruction.
       */
      class Dependency
      {
      public:
        Dependency() : canSplit(false), isRealDependency(false) 
        {
          DerivedFrom<TOperation,GenericAssembly::Interfaces::IOperation>();
        }
        
        bool canSplit;
        bool isRealDependency;
        
        typedef std::set<TOperation*> OperationSet;
        OperationSet antiDepends;
        OperationSet depends;
      };
      
      typedef std::map<TOperation*, Dependency> DependencyDictionary;
      typedef std::pair<TOperation*, Dependency> DepMapItem;
      
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
      
      /**
       * Functor to search an operation inside de list of operations
       * of the Dependency structure.
       */
      class SearchOperationByMemoryAddress : public std::unary_function<const TOperation*,bool> 
      {
      public:
        SearchOperationByMemoryAddress(const TOperation* _operation) : operation(_operation) {}

        bool operator() (const TOperation* item)
        {
          return item->getAddress() == operation->getAddress();
        }
        
      private:
        const TOperation* operation;
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
      
      virtual Dependency getDependencies(TOperation* const& operation, const std::deque<TOperation*>& operations) = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_DEPENDENCYCHAINS_H */

