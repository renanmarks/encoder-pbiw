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

#include "Syllable.h"
#include "Label.h"

namespace rVex
{
	namespace Base
	{
		Label::Label()
			: name(""), scope(GenericAssembly::Utils::LabelScope::GLOBAL), destiny(NULL), absoluteAddress(0)
		{ }

		Label::Label(const Label& other)
			: name(other.name), scope(other.scope), destiny(other.destiny), absoluteAddress(other.absoluteAddress)
		{ }

		void Label::setAbsoluteAddress(unsigned int address)
		{
			absoluteAddress = address;
		}

		unsigned int Label::getAbsoluteAddress() const
		{
			return absoluteAddress;
		}

		void Label::setDestiny(IOperation* operation)
		{
			this->destiny = dynamic_cast<rVex::Base::Syllable*>(operation);
		}

		IOperation* Label::getDestiny() const
		{
			return destiny;
		}

		void Label::setScope(GenericAssembly::Utils::LabelScope::Type labelScope)
		{
			this->scope = labelScope;
		}

		GenericAssembly::Utils::LabelScope::Type Label::getScope() const
		{
			return scope;
		}

		void Label::setName(const std::string& name)
		{
			this->name = name;
		}

		std::string Label::getName() const
		{
			return name;
		}
	}
}
