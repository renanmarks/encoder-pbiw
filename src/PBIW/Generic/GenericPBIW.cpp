/* 
 * File:   GenericPBIW.cpp
 * Author: helix
 * 
 * Created on July 19, 2012, 8:37 PM
 */

#include "GenericPBIW.h"

namespace PBIW
{
  namespace Generic
  {
    GenericPBIW::GenericPBIW()
    {
    }

    GenericPBIW::GenericPBIW(const GenericPBIW& orig)
    {
    }

    GenericPBIW::~GenericPBIW()
    {
    }

    void
    GenericPBIW::encode(const std::vector<GenericAssembly::Interfaces::IInstruction*>&)
    {
    }

    void
    GenericPBIW::decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&)
    {
    }

    void
    GenericPBIW::registerOptimizer(IPBIWOptimizer&)
    {
    }

    void
    GenericPBIW::runOptimizers()
    {
    }

    void
    GenericPBIW::printStatistics(IPBIWPrinter&)
    {
    }

    void
    GenericPBIW::printInstructions(IPBIWPrinter&)
    {
    }

    void
    GenericPBIW::printPatterns(IPBIWPrinter&)
    {
    }

    std::vector<IPBIWPattern*>
    GenericPBIW::getPatterns()
    {
      return std::vector<IPBIWPattern*>();
    }

    std::vector<IPBIWInstruction*>
    GenericPBIW::getInstructions()
    {
      return std::vector<IPBIWInstruction*>();
    }

    std::vector<ILabel*>
    GenericPBIW::getLabels()
    {
      return std::vector<ILabel*>();
    }
    
  }
}