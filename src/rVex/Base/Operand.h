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
 * File:   Operand.h
 * Author: helix
 *
 * Created on August 18, 2012, 10:57 PM
 */

#ifndef RVEX_OPERAND_H
#define	RVEX_OPERAND_H

#include "GenericAssembly/Interfaces/IOperand.h"

namespace rVex
{
	namespace Base
	{
		class Syllable;
		/**
		 * The rVEX operand class.
		 */
		class Operand : public GenericAssembly::Interfaces::IOperand
		{
		public:
			typedef enum {
				GRSource = 1, GRDestiny, BRSource, BRDestiny, Imm9, Imm12
			} Type;

			Operand();
			Operand(int);
			Operand(Type);
			Operand(Type, int);
			Operand(const Operand&);

			virtual ~Operand() { }

			virtual GenericAssembly::Interfaces::IOperand* clone() const;

			virtual void setType(Type);
			virtual Type getType() const;

			virtual void setTypeCode(int);
			virtual int getTypeCode() const;

			virtual bool isImmediate(Type) const;
			virtual bool isRegister(Type) const;

			virtual bool isImmediate() const;
			virtual bool isRegister() const;

			virtual void setValue(int);
			virtual int getValue() const;

			virtual void setOperationBelonged(GenericAssembly::Interfaces::IOperation*);
			virtual GenericAssembly::Interfaces::IOperation* getOperationBelonged() const;

			virtual bool operator==(const IOperand&) const;
			virtual bool operator!=(const IOperand&) const;

		private:
			Type type;
			int value;
			Syllable* syllableBelonged;
		};
	}
}

#endif	/* OPERAND_H */

