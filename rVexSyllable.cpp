/* 
 * File:   rVexSyllabe.cpp
 * Author: helix
 * 
 * Created on July 23, 2011, 5:08 PM
 */

#include <vector>
#include "rVexSyllable.h"

namespace rVex
{
  rVexSyllable::rVexSyllable( )
  {
  }

  rVexSyllable::rVexSyllable( const rVexSyllable& orig )
  {
  }

  rVexSyllable::~rVexSyllable( )
  {
  }
  
  void rVexSyllable::setOpcode(int opcode)
  {
    this->opcode = opcode;
  }
  
  int rVexSyllable::getOpcode()
  {
    return this->opcode;
  }

  void rVexSyllable::setReadRegisters(const std::vector<int>& registers)
  {
    this->readRegisters.assign(registers.begin(), registers.end());
  }
  
  std::vector<int> rVexSyllable::getReadRegisters()
  {
    return this->readRegisters;
  }

  void rVexSyllable::setWriteRegisters(const std::vector<int>& registers)
  {
    this->writeRegisters.assign(registers.begin(), registers.end());
  }
  
  std::vector<int> rVexSyllable::getWriteRegisters()
  {
    return this->writeRegisters;
  }
}