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
//      DependencyChains();
//      DependencyChains(const DependencyChains& orig);
//      virtual ~DependencyChains();
      
      void buildDependenciesChains(const rVex::Instruction&);
      
      void print(rVex::Printers::IPrinter&) const;
      
    private:
      struct Dependency
      {
        Dependency() : possibleSplit(false) {};
        
        bool possibleSplit;
        
        
        typedef std::deque<rVex::Syllable*> SyllableList;
        SyllableList antiDepends;
        SyllableList depends;
      };
      
      Dependency getDependencies(const std::vector<Syllable*>::iterator&, 
           const std::vector<Syllable*>&);
      
      typedef std::map<rVex::Syllable*, Dependency> DependencyDictionary;
      DependencyDictionary dependencies;
    };
  }
}

#endif	/* DEPENDENCYCHAINS_H */

