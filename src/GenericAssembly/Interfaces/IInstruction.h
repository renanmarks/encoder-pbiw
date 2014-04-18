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
 * File:   IInstruction.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef GENERICASSEMBLY_IINSTRUCTION_H
#define	GENERICASSEMBLY_IINSTRUCTION_H

#include <deque>
#include <set>

#include "PBIW/Interfaces/IPBIWInstruction.h"

namespace GenericAssembly
{
  namespace Interfaces
  {
    class ILabel;
    class IOperation;
    
    class IInstruction
    {
    public:
      typedef std::deque<ILabel*> LabelDeque;
      typedef std::deque<IOperation*> OperationDeque;
      
      virtual ~IInstruction() { }

      virtual void addReferencePBIWInstruction(const PBIW::Interfaces::IPBIWInstruction&) = 0;
      virtual std::set<const PBIW::Interfaces::IPBIWInstruction*> getPBIWInstructions() const = 0;
      
      virtual unsigned int getAddress() const = 0;
      virtual void setAddress(unsigned int) = 0;
      
      /**
       * Informs if this assembly instruction is pointed by a label.
       */
      virtual bool haveLabels() const = 0;
      
      /**
       * Returns the label which points to this instruction.
       */
      virtual LabelDeque getLabels() const = 0;
      
      /**
       * Define the operations of this instruction
       */
      virtual void setOperations(OperationDeque&) = 0;
      
      /**
       * Return an deque containing the pointers of the operations of the instruction.
       */
      virtual OperationDeque getOperations() const = 0;
      
      /**
       * Informs if this instruction can be splitted in others at the specified
       * operation. Useful when this instruction is a VLIW instruction that 
       * cannot be fully encoded in one PBIW instruction.
       */
      virtual bool canSplitInstruction(const IOperation& operation) const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IINSTRUCTION_H */

