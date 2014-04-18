/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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