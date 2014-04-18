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
 * File:   LabelScope.h
 * Author: helix
 *
 * Created on June 7, 2012, 2:31 PM
 */

#ifndef GENERICASSEMBLY_LABELSCOPE_H
#define	GENERICASSEMBLY_LABELSCOPE_H

namespace GenericAssembly
{
  namespace Utils
  {
    /**
     * Types of labels.
     */
    class LabelScope
    {
    public:
      typedef enum 
      {
        GLOBAL = 0, 
        LOCAL = 1
      } Type;
    };
  }
}

#endif	/* GENERICASSEMBLY_LABELSCOPE_H */

