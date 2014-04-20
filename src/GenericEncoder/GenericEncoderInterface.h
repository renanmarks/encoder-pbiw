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

#ifndef PBIWFRAMEWORK_GENERICENCODERINTERFACE_H
#define	PBIWFRAMEWORK_GENERICENCODERINTERFACE_H

#include <list>
#include <string>

namespace PBIWFramework
{
	class GenericEncoderInterface
	{
	public:
		virtual void run() = 0;
		virtual std::list<std::string> getSupportedCPUList() const = 0;
		virtual std::string getUsage() const = 0;
		virtual std::string getTargetFlag() const = 0;
	};
}

#endif
