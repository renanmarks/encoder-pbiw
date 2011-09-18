#include <endian.h>
#include "Syllable.h"

namespace rVex
{
  std::string Syllable::printBinary(unsigned int number, bool first, bool last) const
  {
    std::string resultBinary;
    unsigned int temp = number;
    
    for (unsigned char counter=0; counter < 30; temp <<= 1, counter++)
    {
      if (temp & 0x80000000)
        resultBinary.append("1");
      else
        resultBinary.append("0");
    }
    
    if (last)
      resultBinary.append("1");
    else
      resultBinary.append("0");
    
    if (first)
      resultBinary.append("1");
    else
      resultBinary.append("0");
    
    return resultBinary;
  }
}