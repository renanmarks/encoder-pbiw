/* 
 * File:   AND.h
 * Author: helix
 *
 * Created on August 25, 2011, 2:50 PM
 */

#ifndef AND_H
#define	AND_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class AND : public SyllableALU
      {
        public:
          AND() {};
          AND(LayoutType layoutType) : SyllableALU(layoutType, 0, 0, 0) {};
          
          unsigned int getOpcode() const { return 67; }
          Type getSyllableType() const { return ALU; }
      };
    }
  }
}

#endif	/* AND_H */

