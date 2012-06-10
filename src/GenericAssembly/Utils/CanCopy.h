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

