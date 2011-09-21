/* 
 * File:   AsmContext.cpp
 * Author: helix
 * 
 * Created on September 3, 2011, 8:57 PM
 */

#include <iostream>
#include "VexContext.h"
#include "src/rVex/SyllableALU.h"
#include "src/rVex/SyllableMISC.h"
#include "Expressions/SyllableArguments.h"

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
   
  void VexContext::packSyllable(rVex::SyllableALU* syllable, SyllableArguments* arguments)
  {
    try
    {
      
      
    }
    catch (CouldNotParseValueException e)
    {
      
    }
    
//    std::cout << "Argumentos ALU origem: ";
//    arguments->getSourceArguments()->print(std::cout);
//    std::cout << std::endl;
//    
//    std::cout << "Argumentos ALU destino: ";
//    arguments->getDestinyArguments()->print(std::cout);
//    std::cout << std::endl;
//    
//    std::cout << "ALU";
  }
  
  void VexContext::packSyllable(rVex::SyllableMEM* syllable, SyllableArguments* arguments)
  {
    std::cout << "MEM";
  }
  
  void VexContext::packSyllable(rVex::SyllableMUL* syllable, SyllableArguments* arguments)
  {
    std::cout << "MUL";
  }
  
  void VexContext::packSyllable(rVex::SyllableCTRL* syllable, SyllableArguments* arguments)
  {
    std::cout << "CTRL";
  }
  
  void VexContext::packSyllable(rVex::SyllableMISC* syllable, SyllableArguments* arguments)
  {
    std::cout << "MISC";
  }
    
  void VexContext::packSyllable(rVex::Syllable* syllable, SyllableArguments* arguments)
  {
    if (rVex::SyllableALU* syllableALU = dynamic_cast<rVex::SyllableALU*>(syllable))
      packSyllable(syllableALU, arguments);
    else if (rVex::SyllableMEM* syllableMEM = dynamic_cast<rVex::SyllableMEM*>(syllable))
      packSyllable(syllableMEM, arguments);
    else if (rVex::SyllableMUL* syllableMUL = dynamic_cast<rVex::SyllableMUL*>(syllable))
      packSyllable(syllableMUL, arguments);
    else if (rVex::SyllableMISC* syllableMISC = dynamic_cast<rVex::SyllableMISC*>(syllable))
      packSyllable(syllableMISC, arguments);
    else if (rVex::SyllableCTRL* syllableCTRL = dynamic_cast<rVex::SyllableCTRL*>(syllable))
      packSyllable(syllableCTRL, arguments);
    else
      return;
    
//    syllableBuffer.push_back(&*syllable);
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