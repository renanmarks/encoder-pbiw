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
 * File:   SyllableALU.cpp
 * Author: helix
 * 
 * Created on August 21, 2011, 7:43 PM
 */

#include <vector>
#include <iostream>
#include "SyllableALU.h"
#include "rVex/Printers/IPrinter.h"

namespace rVex
{
	namespace Base
	{
		void
		SyllableALU::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
		{
			switch (this->layoutType)
			{
				case LayoutType::RTYPE:
					output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE(first, last)));
					break;
				case LayoutType::ISTYPE:
					output.printOperation(*this, std::vector<unsigned int>(1, printISTYPE(first, last)));
					break;
				case LayoutType::RTYPE_BS:
					output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE_BS(first, last)));
					break;
				default:
					throw LayoutNotSupportedException("This syllable only supports R or IS layouts.");
			}
		}
	}
}
