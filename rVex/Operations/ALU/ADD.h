/* 
 * File:   ADD.h
 * Author: helix
 *
 * Created on August 21, 2011, 7:43 PM
 */

#ifndef ADD_H
#define	ADD_H

#include "../../SyllableALU.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      class ADD : public SyllableALU
      {
        public:
//          ADD();
//          ADD(const ADD& orig);
//          virtual ~ADD();
          
          virtual std::vector<int> getReadRegisters() const { return std::vector<int>(4,4); };
          
          virtual int getOpcode() const { return 65; }

          virtual Type getSyllableType() const { return ALU; }

          virtual LayoutType getLayoutType() const { return RTYPE; }

          virtual std::string print() const { return "OPA"; }
          
          virtual bool operator==(const Syllable& other) const 
          { 
            const ADD* otherADD = static_cast<ADD*>(&const_cast<Syllable&>(other));
            
            if (this->getOpcode() == otherADD->getOpcode())
            {
              return (this->getLayoutType() == otherADD->getLayoutType()) &&
                (this->getSyllableType() == otherADD->getSyllableType()) &&
                (this->getReadRegisters() == otherADD->getReadRegisters());
            }
            
            return false;
          }
          
          virtual bool operator!=(const Syllable& other) const { return !(*this == other); }
          
        private:
      };
    }
  }
}

#endif	/* ADD_H */

