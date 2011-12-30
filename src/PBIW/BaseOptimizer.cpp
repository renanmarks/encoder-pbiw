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
    // TODO
  }

  BaseOptimizer::BaseOptimizer(const BaseOptimizer& orig)
  {
    // TODO
  }

  BaseOptimizer::~BaseOptimizer()
  {
    // TODO
  }

  void
  BaseOptimizer::useLabels(const std::vector<Label>& labels)
  {
    std::vector<Label>::const_iterator it;
    
    for (it = labels.begin(); it < labels.end(); it++)
    {
      this->labels.push_back(*it);
      // TODO: Melhorar
    }
  }

  void
  BaseOptimizer::useInstructions(const std::vector<IPBIWInstruction*>& instructions)
  {
    std::vector<IPBIWInstruction*>::const_iterator it;
    
    for (it = instructions.begin(); it < instructions.end(); it++)
    {
      this->instructions.push_back(*it);
      // TODO: Melhorar
    }
  }

  void
  BaseOptimizer::usePatterns(const std::vector<IPBIWPattern*>& patterns)
  {
    std::vector<IPBIWPattern*>::const_iterator it;
    
    for (it = patterns.begin(); it < patterns.end(); it++)
    {
      this->patterns.push_back(*it);
      // TODO: Melhorar
    }
  }

  void
  BaseOptimizer::print(IPBIWPrinter& printer)
  {
    // TODO
  }
}
