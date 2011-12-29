/* 
 * File:   BaseOptimizer.cpp
 * Author: helix
 * 
 * Created on December 22, 2011, 3:37 PM
 */

#include "BaseOptimizer.h"

namespace PBIW
{

  BaseOptimizer::BaseOptimizer()
  {
  }

  BaseOptimizer::BaseOptimizer(const BaseOptimizer& orig)
  {
  }

  BaseOptimizer::~BaseOptimizer()
  {
  }

  void
  BaseOptimizer::useLabels(const std::vector<Label>& labels)
  {
    std::vector<Label>::const_iterator it;
    
    for (it = labels.begin();
         it < labels.end();
         it++)
    {
      
    }
  }

  void
  BaseOptimizer::useInstructions(const std::vector<IPBIWInstruction*>& instructions)
  {
    std::vector<IPBIWInstruction*>::const_iterator it;
    
    for (it = instructions.begin();
         it < instructions.end();
         it++)
    {
      
    }
  }

  void
  BaseOptimizer::usePatterns(const std::vector<IPBIWPattern*>& patterns)
  {
    std::vector<IPBIWPattern*>::const_iterator it;
    
    for (it = patterns.begin();
         it < patterns.end();
         it++)
    {
      
    }
  }

  void
  BaseOptimizer::print(IPBIWPrinter& printer)
  {

  }

  std::vector<IPBIWPattern*>
  BaseOptimizer::getPatterns()
  {

  }

  std::vector<IPBIWInstruction*>
  BaseOptimizer::getInstructions()
  {

  }
}
