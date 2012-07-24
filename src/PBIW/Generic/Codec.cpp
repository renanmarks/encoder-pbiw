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
    Codec::encode(const std::vector<GenericAssembly::Interfaces::IInstruction*>&)
    {    
    }

    void
    Codec::decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&)
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

    std::vector<IPBIWPattern*>
    Codec::getPatterns()
    {
      return std::vector<IPBIWPattern*>();
    }

    std::vector<IPBIWInstruction*>
    Codec::getInstructions()
    {
      return std::vector<IPBIWInstruction*>();
    }

    std::vector<ILabel*>
    Codec::getLabels()
    {
      return std::vector<ILabel*>();
    }
    
  }
}