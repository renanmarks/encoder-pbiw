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
 * File:   IPBIW.h
 * Author: helix
 *
 * Created on July 21, 2011, 2:36 PM
 */

#ifndef IPBIW_H
#define	IPBIW_H

#include <ostream>
#include <deque>
#include "rVex/Base/Instruction.h"
#include "IPBIWInstruction.h"
#include "IPBIWPattern.h"
#include "IPBIWPrinter.h"
#include "IPBIWOptimizer.h"

namespace PBIW
{
  namespace Interfaces
  {   
    /**
     * PBIW codec interface
     */
    class IPBIW : public IPBIWSet
    {
      public:
        virtual ~IPBIW() {}
        
        virtual void setDebug(bool) = 0;
        virtual bool isDebug() const = 0;
        
        virtual void encode(const std::deque<GenericAssembly::Interfaces::IInstruction*>&) = 0;
        virtual void decode(const std::deque<IPBIWInstruction*>&, const std::deque<IPBIWPattern*>&) = 0;
        
        virtual void registerOptimizer(IPBIWOptimizer&) = 0;
        virtual void runOptimizers() = 0;
    };
  }
}

#endif	/* IPBIW_H */

