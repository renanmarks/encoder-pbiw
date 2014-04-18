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
 * File:   NOP.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:56
 */

#ifndef NOP_H
#define	NOP_H

#include <vector>
#include "../../Syllable.h"
#include "../../SyllableCTRL.h"
#include "rVex/Printers/IPrinter.h"

namespace rVex
{
  namespace Operations
  {
    namespace MISC
    {
      class NOP : public SyllableCTRL
      {
        public:
          NOP() {}
          
          unsigned int getOpcode() const { return this->opNOP; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual bool operator==(const Syllable& other) const
          { return other.getOpcode() == this->getOpcode(); }
          
          virtual bool operator!=(const Syllable& other) const
          { return !(*this == other); }
          
          virtual LayoutType::Type getLayoutType() const { return LayoutType::RTYPE; }
      
          virtual void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { 
            unsigned int nop = (((0 | last) << 1) | first);
            output.printOperation(*this, std::vector<unsigned int>(1, nop)); 
          }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXIV(arguments); }
      };
    }
  }
}

#endif	/* NOP_H */

