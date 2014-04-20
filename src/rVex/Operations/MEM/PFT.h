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
 * File:   PFT.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef PFT_H
#define	PFT_H

#include <vector>
#include "rVex/Base/SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class PFT : public SyllableMEM
      {
        public:
          PFT() {}
          
          unsigned int getOpcode() const { return this->opPFT; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { 
            unsigned int prefetch = ((last << 1) | first) | 0xDEAD0000;
            output.printOperation(*this, std::vector<unsigned int>(1, prefetch)); 
          }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXII(arguments); }
      };
    }
  }
}

#endif	/* PFT_H */

