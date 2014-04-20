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
 * File:   ALUSyllable.h
 * Author: helix
 *
 * Created on August 21, 2011, 5:06 PM
 */

#ifndef SYLLABLEMEM_H
#define	SYLLABLEMEM_H

#include <vector>
#include "Syllable.h"
#include "rVex/Printers/IPrinter.h"

namespace rVex
{
  /**
   * A r-Vex instruction MEM syllable (operation)
   */
  class SyllableMEM : public Syllable
  {
    public:
      virtual ~SyllableMEM() { }
      
      virtual void print(rVex::Printers::IPrinter&, bool, bool) const = 0;
      
      virtual void fillSyllable(VexParser::SyllableArguments&) = 0;
  };
}

#endif	/* SYLLABLEMEM_H */

