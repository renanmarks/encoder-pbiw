/* 
 * File:   rVexInstruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 4:19 PM
 */

#include "rVexInstruction.h"
namespace rVex
{
  rVexInstruction::rVexInstruction( )
  {
    
  }

  rVexInstruction::rVexInstruction( const rVexInstruction& orig )
  {
    
  }

  rVexInstruction::~rVexInstruction( )
  {
    
  }
  
  bool rVexInstruction::addOperation(const rVexSyllable& syllable)
  {
    if (this->syllables.size() < this->syllables.max_size())
      this->syllables.push_back(syllable);
  }
  
  bool rVexInstruction::removeOperation(const rVexSyllable&)
  {
  }

  std::vector<rVexSyllable>* rVexInstruction::getSyllables() const
  {
    return new std::vector<rVexSyllable>(syllables);
  }
}