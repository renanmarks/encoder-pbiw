/* 
 * File:   DependencyChains.cpp
 * Author: helix
 * 
 * Created on April 5, 2012, 3:55 PM
 */

#include <iostream>
#include <functional>
#include "DependencyChains.h"
#include "src/rVex/rVex.h"

namespace rVex
{
  namespace Utils
  {

//    DependencyChains::DependencyChains()
//    {
//    }
//
//    DependencyChains::DependencyChains(const DependencyChains& orig)
//    {
//    }
//
//    DependencyChains::~DependencyChains()
//    {
//    }
    
    void 
    DependencyChains::print(rVex::Printers::IPrinter& printer) const
    {
      DependencyDictionary::const_iterator it;
      
      for(it = dependencies.begin(); it != dependencies.end(); it++)
      {
        printer.getOutputStream() << "Syllable " << it->first->getAddress()
          << " anti-depends (";
        
        Dependency::SyllableList::const_iterator dependencyIt;
        
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
    
    
    
    void 
    DependencyChains::buildDependenciesChains(const rVex::Instruction& instruction)
    {
      rVex::Instruction::SyllableVector syllables = instruction.getSyllables();
      rVex::Instruction::SyllableVector::iterator syllableIt;
      
      // Fills all the inter-syllable dependencies
      for(syllableIt = syllables.begin(); syllableIt < syllables.end(); syllableIt++)
        dependencies[*syllableIt] = getDependencies(syllableIt, syllables);
      
      DependencyDictionary::iterator it;
      
      for(it = dependencies.begin(); it != dependencies.end(); it++)
      {
        bool hasTrueDependency = it->second.depends.size() > 0;
        
        if ( hasTrueDependency )
        {
          Dependency::SyllableList::iterator syllableIt;
          
          for (syllableIt = it->second.depends.begin();
               syllableIt < it->second.depends.end();
               syllableIt++)
          {
            markSplits(*syllableIt, it->first);
          }
        }
        else if (it->second.isRealDependency == false)
          it->second.canSplit = true;
      }
    }
    
    bool 
    DependencyChains::SearchSyllable::operator ()(DepMapItem item)
    {
      return item.first->getAddress() == address;
    }
    
    void 
    DependencyChains::markSplits(rVex::Syllable* first, 
                                 rVex::Syllable* last)
    {
      // Starting with the next element
      DependencyDictionary::iterator it = std::find_if(dependencies.begin(), dependencies.end(), SearchSyllable(first->getAddress()+1));
      DependencyDictionary::iterator endIt = std::find_if(dependencies.begin(), dependencies.end(), SearchSyllable(last->getAddress()));
      
      while(it != endIt)
      {
        it->second.canSplit = false;
        it->second.isRealDependency = true;
        
        it = std::find_if(dependencies.begin(), dependencies.end(), SearchSyllable(it->first->getAddress()+1));
      }
    }
    
    DependencyChains::Dependency 
    DependencyChains::getDependencies(const rVex::Instruction::SyllableVector::iterator& it, 
      const rVex::Instruction::SyllableVector& syllables)
    {
      Dependency dependency;
      
      rVex::Syllable::ReadRegVector readRegs = (*it)->getReadRegisters();
      rVex::Instruction::SyllableVector::const_iterator otherSyllableIt;
      
      for(otherSyllableIt = syllables.begin(); otherSyllableIt < syllables.end(); otherSyllableIt++)
      {
        if ( ((*otherSyllableIt)->getAddress() == (*it)->getAddress()) || ((*otherSyllableIt)->getGrDestiny() == 0 && !(*it)->hasBrSource()) )
          continue;
        
        bool writesInMyGrReadRegister = 
          (*otherSyllableIt)->hasGrDestiny() 
          && (std::find(readRegs.begin(), readRegs.end(), (*otherSyllableIt)->getGrDestiny()) != readRegs.end());
        
        bool writesInMyBrReadRegister = 
          (*otherSyllableIt)->hasBrDestiny() 
          && (*it)->hasBrSource() 
          && ((*otherSyllableIt)->getBrDestiny() == (*it)->getBrSource());
        
        bool isAfterMe = (*otherSyllableIt)->getAddress() > (*it)->getAddress();
        
        if (writesInMyGrReadRegister || writesInMyBrReadRegister)
        {
          if (isAfterMe)
            dependency.antiDepends.push_back(*otherSyllableIt);
          else
            dependency.depends.push_back(*otherSyllableIt);
        }
      }
      
      return dependency;
    }
    
  }
}