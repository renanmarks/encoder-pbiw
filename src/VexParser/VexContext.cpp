/* 
 * File:   AsmContext.cpp
 * Author: helix
 * 
 * Created on September 3, 2011, 8:57 PM
 */

#include <ostream>
#include "VexContext.h"

namespace VexParser
{

  VexContext::~VexContext( )
  {
    if (!syllables.empty())
    {
      SyllableList::iterator it;
      
      for (it = syllables.begin();
           it != syllables.end();
           it++)
      {
        delete *it;
      }
    }
  }
  
  void VexContext::newInstruction()
  {
    syllableBuffer.clear();
  }
  
  void VexContext::packSyllable(rVex::Syllable* syllable)
  {
    syllableBuffer.push_back(&*syllable);
  }
  
  void VexContext::endInstruction()
  {
    rVex::Instruction instruction;
    SyllableBuffer::iterator it;
    
    for (it = syllableBuffer.begin();
         it < syllableBuffer.end();
         it++)
    {
      syllables.push_back(*it);
      instruction.addSyllable(**it);
    }
    
    syllableBuffer.clear();
    instructions.push_back(instruction);
  }
  
  rVex::Instruction
  VexContext::getInstruction(unsigned int index)
  {
    InstructionList::iterator it = instructions.begin();
    unsigned int i = 0;
    
    while (i++ < index)
      it++;
    
    if (it != instructions.end())
      return *it;
    
    return rVex::Instruction();
  }
  
  void
  VexContext::print(std::ostream& stream)
  {
    InstructionList::const_iterator it;
    
    for(it = instructions.begin();
        it != instructions.end();
        it++)
    {
      stream << (*it).print() << std::endl;
    }
  }

}