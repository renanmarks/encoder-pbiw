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
 * File:   IPBIWOptimizer.h
 * Author: helix
 *
 * Created on December 15, 2011, 3:41 PM
 */

#ifndef IPBIWOPTIMIZER_H
#define	IPBIWOPTIMIZER_H

#include "IPBIWInstruction.h"
#include "IPBIWPattern.h"
#include "ILabel.h"
#include "IPBIWFactory.h"
#include "IPBIWSet.h"
#include <deque>

namespace PBIW
{
  namespace Interfaces 
  {
    class IPBIW;
    
    class IPBIWOptimizer : public IPBIWSet
    {
    public:
      virtual ~IPBIWOptimizer() {}
      
      virtual void useContext(const IPBIW&) = 0;
      
      virtual void useLabels(const std::deque<ILabel*>&) = 0;
      virtual void useInstructions(const std::deque<IPBIWInstruction*>&) = 0;
      virtual void usePatterns(const std::deque<IPBIWPattern*>&) = 0;
      
      virtual void setupOptimizer() = 0;
      
      virtual void run(IPBIWFactory&) = 0;
    };
  }
}

#endif	/* IPBIWOPTIMIZER_H */

