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
#include "GenericAssembly/Utils/DependencyChains.h"
#include "rVex/Printers/IPrinter.h"

namespace rVex
{
	namespace Base
	{
		class Instruction;
		class Syllable;
	}
  
  namespace Utils
  {
		class DependencyChains : public GenericAssembly::Utils::DependencyChains<rVex::Base::Instruction, rVex::Base::Syllable, rVex::Printers::IPrinter>
    {
    protected:
			virtual Dependency getDependencies(rVex::Base::Syllable* const& operation, const std::deque<rVex::Base::Syllable*>& operations);
    };
  }
}

#endif	/* RVEX_DEPENDENCYCHAINS_H */

