/* 
 * File:   DependencyChains.h
 * Author: helix
 *
 * Created on April 5, 2012, 3:55 PM
 */

#ifndef RVEX_DEPENDENCYCHAINS_H
#define	RVEX_DEPENDENCYCHAINS_H

#include <map>
#include <deque>
#include <vector>
#include "src/GenericAssembly/Utils/DependencyChains.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  class Instruction;
  class Syllable;
  
  namespace Utils
  {
    class DependencyChains : public GenericAssembly::Utils::DependencyChains<Instruction, Syllable, rVex::Printers::IPrinter>
    {
    protected:
      virtual Dependency getDependencies(Syllable* const& operation, const std::deque<Syllable*>& operations);
    };
  }
}

#endif	/* RVEX_DEPENDENCYCHAINS_H */

