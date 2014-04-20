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
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef RVEX_LABEL_H
#define	RVEX_LABEL_H

#include <string>
#include "GenericAssembly/Interfaces/ILabel.h"

namespace rVex
{
	using namespace GenericAssembly::Interfaces;

	namespace Base
	{
		class Syllable;

		/**
		 * Structure used to save the label definition information.
		 */
		class Label : public ILabel
		{
		public:
			Label();
			Label(const Label& other);

			virtual void setAbsoluteAddress(unsigned int address);
			virtual unsigned int getAbsoluteAddress() const;

			virtual void setDestiny(IOperation* operation);
			virtual IOperation* getDestiny() const;

			virtual void setScope(GenericAssembly::Utils::LabelScope::Type labelScope);
			virtual GenericAssembly::Utils::LabelScope::Type getScope() const;

			virtual void setName(const std::string& name);
			virtual std::string getName() const;

		private:
			std::string name;
			GenericAssembly::Utils::LabelScope::Type scope;
			rVex::Base::Syllable* destiny;
			unsigned int absoluteAddress;
		};
	}
}

#endif	/* RVEX_LABEL_H */

