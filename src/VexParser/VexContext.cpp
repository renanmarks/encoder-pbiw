/* 
 * File:   AsmContext.cpp
 * Author: helix
 * 
 * Created on September 3, 2011, 8:57 PM
 */

#include <ostream>
#include <string.h>
#include "VexContext.h"
#include "src/rVex/SyllableALU.h"
#include "src/rVex/SyllableMISC.h"
#include "src/rVex/Syllable.h"

#include "Expressions/SyllableArguments.h"
#include "src/rVex/Operations/ALU/ADD.h"
#include "src/rVex/Operations/ALU/MOV.h"
#include "src/rVex/Printers/rVexPrinter.h"

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
    // If is a MOV with immediate operand then is a pseudo-instruction...
    if (
        (syllable->getOpcode() == rVex::Syllable::opMOV) &&
        (arguments->getSourceArguments()->getArguments()[0]->getParsedValue().isImmediate)
       )
    {
      // Change MOV syllable to ADD syllable
      rVex::Operations::ALU::ADD add;
      memcpy(syllable, &add, sizeof(add));
      
      // Change from: mov $r0.x = 12345
      // to: add $r0.x = $r0.0, 12345
      int value = arguments->getSourceArguments()->getArguments()[0]->getValue();
      arguments->getSourceArguments()->clearArguments();
      arguments->getSourceArguments()->addArgument(new Expression("$r0.0"));
      arguments->getSourceArguments()->addArgument(new Expression(value));
    }

    syllable->fillSyllable(arguments);
  }
  
  void VexContext::packSyllable(rVex::SyllableMEM* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
  }
  
  void VexContext::packSyllable(rVex::SyllableMUL* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
  }
  
  void VexContext::packSyllable(rVex::SyllableCTRL* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
  }
  
  void VexContext::packSyllable(rVex::SyllableMISC* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
  }
    
  void VexContext::packSyllable(rVex::Syllable* syllable, SyllableArguments* arguments)
  {
    switch(syllable->getSyllableType())
    {
      case rVex::Syllable::ALU:
        packSyllable(dynamic_cast<rVex::SyllableALU*>(syllable), arguments);
        break;
        
      case rVex::Syllable::MEM:
        packSyllable(dynamic_cast<rVex::SyllableMEM*>(syllable), arguments);
        break;
        
      case rVex::Syllable::MUL:
        packSyllable(dynamic_cast<rVex::SyllableMUL*>(syllable), arguments);
        break;
        
      case rVex::Syllable::CTRL:
        packSyllable(dynamic_cast<rVex::SyllableCTRL*>(syllable), arguments);
        break;
        
      default: // MISC
        packSyllable(dynamic_cast<rVex::SyllableMISC*>(syllable), arguments);
        break;
    }
    
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::endInstruction()
  {
    SyllableBuffer::iterator it;
    rVex::Instruction instruction;
    
    for (it = syllableBuffer.begin();
         it < syllableBuffer.end();
         it++)
    {
      (*it)->setAddress(this->syllableCounter++);
      syllables.push_back(*it);
      instruction.addSyllable(**it);
    }
    
    instruction.setAddress(this->instructionCounter++);
    
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
    rVex::Printers::rVexPrinter printer(stream);
    
    for(it = instructions.begin();
        it != instructions.end();
        it++)
    {
      try
      {
        it->print(printer);
//        stream << "Address: " << it->getAddress() << " - " << it->print(printer) << std::endl;
      }
      catch (rVex::Syllable::LayoutNotSupportedException* e)
      {
//        stream << "Erro imprimindo: " << e->what() << "Opcode: " << it->getSyllables()[0]->getOpcode() << std::endl;
      }
    }
  }
  
  void
  VexContext::enableDebugging(bool enableSwitch)
  {
    debuggingEnabled = enableSwitch;
  }
}