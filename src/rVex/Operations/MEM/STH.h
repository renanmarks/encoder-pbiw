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
 * File:   STH.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:43
 */

#ifndef STH_H
#define	STH_H

#include <vector>
#include "../../SyllableMEM.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      class STH : public SyllableMEM
      {
        public:
          STH() {}
          
          unsigned int getOpcode() const { return this->opSTH; }
          SyllableType::Type getSyllableType() const { return SyllableType::MEM; }
          
          void print(rVex::Printers::IPrinter& output, bool first, bool last) const
          { output.printOperation(*this, std::vector<unsigned int>(1, printMEMSTORETYPE(first, last)) ); }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXI(arguments); }
          
          GenericAssembly::Utils::OperandVector exportOperandVector() const;
      };
    }
  }
}

#endif	/* STH_H */

