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
 * File:   CanCopy.h
 * Author: helix
 *
 * Created on June 8, 2012, 7:22 PM
 */

#ifndef GENERICASSEMBLY_UTILS_CANCOPY_H
#define	GENERICASSEMBLY_UTILS_CANCOPY_H

namespace GenericAssembly
{
  namespace Utils
  {
    /**
     * Class used to express a template type constraint.
     * Checks if T is derived from B type.
     *
     * From the Bjarne's C++ FAQ & Style at: 
     * http://www2.research.att.com/~bs/bs_faq2.html#constraints
     */
    template<class T, class B> 
    class DerivedFrom 
    {
    private:
      B* (*p) (T*);
      
    public:
      static B* constraints(T* p) { B* pb = p; return pb; }
      DerivedFrom() : p(constraints) { }
    };
  }
}
#endif	/* GENERICASSEMBLY_UTILS_CANCOPY_H */

