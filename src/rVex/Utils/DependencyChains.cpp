/* 
 * File:   DependencyChains.cpp
 * Author: helix
 * 
 * Created on April 5, 2012, 3:55 PM
 */

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
        
        printer.getOutputStream() << ")" << std::endl;
      }
    }
    
    void 
    DependencyChains::buildDependenciesChains(const rVex::Instruction& instruction)
    {
      rVex::Instruction::SyllableVector syllables = instruction.getSyllables();
      rVex::Instruction::SyllableVector::iterator it;
      
      // Fills all the inter-syllable dependencies
      for(it = syllables.begin(); it < syllables.end(); it++)
        dependencies[*it] = getDependencies(it, syllables);
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
        
        bool writesInMyGrReadRegister = (*otherSyllableIt)->hasGrDestiny() && (std::find(readRegs.begin(), readRegs.end(), (*otherSyllableIt)->getGrDestiny()) != readRegs.end());
        
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