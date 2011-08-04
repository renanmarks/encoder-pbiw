/* 
 * File:   rVexSyllabe.cpp
 * Author: helix
 * 
 * Created on July 23, 2011, 5:08 PM
 */

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
  
  bool rVexSyllable::setOpcode(int opcode)
  {
    this->opcode = opcode;
  }
  
  int rVexSyllable::getOpcode()
  {
    return this->opcode;
  }

  bool rVexSyllable::setReadRegisters(const std::vector<int>&)
  {
    
  }
  
  std::vector<int> rVexSyllable::getReadRegisters()
  {
    
  }

  bool rVexSyllable::setWriteRegisters(const std::vector<int>&)
  {
    
  }
  
  std::vector<int> rVexSyllable::getWriteRegisters()
  {
    
  }
}