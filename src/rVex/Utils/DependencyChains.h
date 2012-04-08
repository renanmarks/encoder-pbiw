/* 
 * File:   DependencyChains.h
 * Author: helix
 *
 * Created on April 5, 2012, 3:55 PM
 */

#ifndef DEPENDENCYCHAINS_H
#define	DEPENDENCYCHAINS_H

#include <map>
#include <deque>
#include <vector>
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  class Instruction;
  class Syllable;
  
  namespace Utils
  {
    class DependencyChains
    {
    public:
      void buildDependenciesChains(const rVex::Instruction&);
      void print(rVex::Printers::IPrinter&) const;
      
      bool canSplitSyllable(rVex::Syllable* syllable) const
      { return dependencies.find(syllable)->second.canSplit; }
      
    private:
      struct Dependency
      {
        Dependency() : canSplit(false), isRealDependency(false) {};
        
        bool canSplit;
        bool isRealDependency;
        
        typedef std::deque<rVex::Syllable*> SyllableList;
        SyllableList antiDepends;
        SyllableList depends;
      };
      
      typedef std::pair<rVex::Syllable* const, rVex::Utils::DependencyChains::Dependency> DepMapItem;
      
      class SearchSyllable : public std::unary_function<DepMapItem,bool> 
      {
        unsigned int address;

      public:
        SearchSyllable(unsigned int _address) : address(_address)
        { }

        bool operator() (DepMapItem vish);
      };
      
      void markSplits(rVex::Syllable*, rVex::Syllable*);
      
      Dependency getDependencies(const std::vector<Syllable*>::iterator&, 
           const std::vector<Syllable*>&);
      
      typedef std::map<rVex::Syllable*, Dependency> DependencyDictionary;
      DependencyDictionary dependencies;
    };
  }
}

#endif	/* DEPENDENCYCHAINS_H */

