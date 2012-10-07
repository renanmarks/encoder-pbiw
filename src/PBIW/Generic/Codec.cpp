/* 
 * File:   GenericPBIW.cpp
 * Author: helix
 * 
 * Created on July 19, 2012, 8:37 PM
 */

#include "Codec.h"

namespace PBIW
{
  namespace Generic
  {
    Codec::Codec()
    {
    }

    Codec::Codec(const Codec& orig)
    {
    }

    Codec::~Codec()
    {
    }

    void
    Codec::encode(const std::deque<GenericAssembly::Interfaces::IInstruction*>&)
    {
      
    }

    void
    Codec::decode(const std::deque<IPBIWInstruction*>&, const std::deque<IPBIWPattern*>&)
    {
    }

    void
    Codec::registerOptimizer(IPBIWOptimizer&)
    {
    }

    void
    Codec::runOptimizers()
    {
    }

    void
    Codec::printStatistics(IPBIWPrinter&)
    {
    }

    void
    Codec::printInstructions(IPBIWPrinter&)
    {
    }

    void
    Codec::printPatterns(IPBIWPrinter&)
    {
    }

    std::deque<IPBIWPattern*>
    Codec::getPatterns()
    {
      return std::deque<IPBIWPattern*>();
    }

    std::deque<IPBIWInstruction*>
    Codec::getInstructions()
    {
      return std::deque<IPBIWInstruction*>();
    }

    std::deque<ILabel*>
    Codec::getLabels()
    {
      return std::deque<ILabel*>();
    }
    
  }
}