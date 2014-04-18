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
 * File:   MPYLH.h
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 22:25
 */

#ifndef MPYLH_H
#define	MPYLH_H

#include "../../SyllableMUL.h"

namespace rVex
{
  namespace Operations
  {
    namespace MUL
    {
      class MPYLH : public SyllableMUL
      {
        public:
          unsigned int getOpcode() const { return this->opMPYLH; }
          SyllableType::Type getSyllableType() const { return SyllableType::MUL; }
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeI(arguments); }
      };
    }
  }
}

#endif	/* MPYLH_H */

