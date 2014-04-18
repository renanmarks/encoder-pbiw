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
 * File:   GenericPBIW.h
 * Author: helix
 *
 * Created on July 19, 2012, 8:37 PM
 */

#ifndef PBIW_GENERIC_CODEC_H
#define	PBIW_GENERIC_CODEC_H

#include "PBIW/Interfaces/IPBIW.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Codec : public IPBIW
    {
    public:
      Codec();
      Codec(const Codec& orig);
      virtual ~Codec();

      virtual void encode(const std::deque<GenericAssembly::Interfaces::IInstruction*>&);
      virtual void decode(const std::deque<IPBIWInstruction*>&, const std::deque<IPBIWPattern*>&);

      virtual void registerOptimizer(IPBIWOptimizer&);
      virtual void runOptimizers();

      virtual void printStatistics(IPBIWPrinter&);
      virtual void printInstructions(IPBIWPrinter&);
      virtual void printPatterns(IPBIWPrinter&);

      virtual std::deque<IPBIWPattern*> getPatterns();
      virtual std::deque<IPBIWInstruction*> getInstructions();
      virtual std::deque<ILabel*> getLabels();

    private:

    };
  }
}

#endif	/* GENERICPBIW_H */

