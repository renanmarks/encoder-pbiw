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
 * File:   IIGOTO.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef IIGOTO_H
#define	IIGOTO_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class IGOTO : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opIGOTO; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXIX(arguments); }
      };
    }
  }
}

#endif	/* IIGOTO_H */

