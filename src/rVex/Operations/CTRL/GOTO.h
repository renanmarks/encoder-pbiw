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
 * File:   GOTO.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef GOTO_H
#define	GOTO_H

#include "rVex/Base/SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
			class GOTO : public rVex::Base::SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opGOTO; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXIII(arguments); }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          GenericAssembly::Utils::OperandVector exportOperandVector() const;
      };
    }
  }
}

#endif	/* GOTO_H */

