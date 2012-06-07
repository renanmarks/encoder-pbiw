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

