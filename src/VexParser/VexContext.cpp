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
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableMEM* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableMUL* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableCTRL* syllable, SyllableArguments* arguments)
  {
    // Does not support XNOP yet.
    if (syllable->getOpcode() == rVex::Syllable::opXNOP)
      return;
    
    syllable->fillSyllable(arguments);
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableMISC* syllable, SyllableArguments* arguments)
  {
    syllable->fillSyllable(arguments);
    syllableBuffer.push_back(syllable);
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
        throw new std::exception();
        packSyllable(dynamic_cast<rVex::SyllableMISC*>(syllable), arguments);
        break;
    }
    
  }
  
  void VexContext::processLabels()
  {
    
  }
  
  void VexContext::setLabel(std::string name, rVex::Label::LabelScope scope) 
  { 
    rVex::Label label;
    
    hasLabel = true;
    
    label.name = name;
    label.scope = scope;
    
    labels.push_back(label);
  }
  
  void VexContext::endInstruction()
  {
    SyllableBuffer::iterator it;
    rVex::Instruction instruction;
    
    // Reorder and put NOPs - TODO
    
    for (it = syllableBuffer.begin();
         it < syllableBuffer.end();
         it++)
    {
      (*it)->setAddress(this->syllableCounter++);
      syllables.push_back(*it);
      instruction.addSyllable(**it);
    }
    
    instruction.setAddress(this->instructionCounter++);
    
    // Post process
    
    if (hasLabel)
    {
      rVex::Label& label = labels.back();

      label.destiny = instruction.getSyllables()[0];
      label.absoluteAddress = instruction.getAddress();
      
      hasLabel = false;
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
  VexContext::print(rVex::Printers::IPrinter& printer)
  {
    std::ostream& stream = printer.getOutputStream();
    
    LabelVector::const_iterator labelIt;
    
    stream << "Labels.L/G (instruction address)[syllable address]:" << std::endl;
    
    for(labelIt = labels.begin();
        labelIt != labels.end();
        labelIt++)
    {
      stream << labelIt->name; 
      
      if (labelIt->scope == rVex::Label::GLOBAL)
        stream << ".G";
      else
        stream << ".L";
          
      stream << "(" << labelIt->absoluteAddress << ")"
             << "[" << labelIt->destiny->getAddress() << "]"
             << std::endl;
    }
    
    InstructionList::const_iterator it;
    
    for(it = instructions.begin();
        it != instructions.end();
        it++)
    {
        it->print(printer);
    }
  }
  

  void
  VexContext::enableDebugging(bool enableSwitch)
  {
    debuggingEnabled = enableSwitch;
  }

    void
  VexContext::reorder(rVex::Instruction* instruction)
  {
      typedef std::vector<rVex::Syllable*> SyllablesAux;
      SyllablesAux syllAux;
      SyllablesAux::iterator it;
      
      rVex::Syllable* syllable;
      int counterIt = 0;
      
      syllAux = instruction->getSyllables();
            
      if(syllAux.capacity() < 4){
          syllAux.resize(4,new rVex::Operations::MISC::NOP());
      }
      
      for(it = syllAux.begin(); it < syllAux.end(); it++)
      {
          // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
          if((*it)->getOpcode() && ((*it)->getSyllableType() != rVex::Syllable::ALU))
          {
              if(((*it)->getSyllableType() == rVex::Syllable::CTRL) && (counterIt != 0))
              {
                  // exchange the indexes
                  syllable = syllAux.at(0);
                  syllAux.at(0) = syllAux.at(counterIt);
                  syllAux.at(counterIt) = syllable;
                  
                  counterIt--;
                  it--;
              }

              else if(((*it)->getSyllableType() == rVex::Syllable::MEM)  && (counterIt != 3))
              {
                  // exchange the indexes
                  syllable = syllAux.at(3);
                  syllAux.at(3) = syllAux.at(counterIt);
                  syllAux.at(counterIt) = syllable;
                  
                  counterIt--;
                  it--;
              }   

              else if(((*it)->getSyllableType() == rVex::Syllable::MUL) && ((counterIt != 1) & (counterIt != 2)))
              {
                  int index;                  
                  
                  // set up the index that will receive the MUL syllable
                  if(syllAux.at(1)->getSyllableType() != 2)
                      index = 1;
                  else
                      index = 2;
                  
                  // exchange the indexes
                  syllable = syllAux.at(index);
                  syllAux.at(index) = syllAux.at(counterIt);
                  syllAux.at(counterIt) = syllable;
                                    
                  counterIt--;
                  it--;
              }             
          }

          counterIt++;             
      }
      
      int i = 0;
      
      for(it = syllAux.begin(); it < syllAux.end(); it++){
          instruction->removeSyllable(*syllAux.at(i));
          instruction->addSyllable(*syllAux.at(i));
          std::cout << (*it)->getOpcode() << std::endl;
          std::cout << "I -> " << i++ << std::endl;
      }
          
    }      
      
//void
//  VexContext::reorder(rVex::Instruction* instruction)
//  {
//      rVex::Syllable* syllable;
//      int counterIt = 0;
//      std::cout << "Passou aqui -> 1" << std::endl;
//      InstructionList instructions;
//      InstructionList::const_iterator it;
//      typedef std::vector<rVex::Syllable*> instructionsVec;
////      SyllablesAux syllAux;
////      SyllablesAux::iterator it;
////      instructionsVec instructions;
////      instructionsVec::iterator it;
//      //instructions = instruction->getSyllables();
//     
////      if(instructions.size() < 4){
////          instructions.resize(4,new rVex::Operations::MISC::NOP());
////      }
//      
//      for(it = instructions.begin(); it == instructions.end(); it++)
//      {
//          std::cout << "Passou aqui -> for " << std::endl;
//          // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
//          if((*it).getSyllables()[counterIt]->getOpcode() && 
//                  ((*it).getSyllables()[counterIt]->getSyllableType() != rVex::Syllable::ALU))
//          {
//              std::cout << "Passou aqui -> if" << std::endl;
//              if(((*it).getSyllables()[counterIt]->getSyllableType() == rVex::Syllable::CTRL) && (counterIt != 0))
//              {
//                  // exchange the indexes
//                  syllable = (*it).getSyllables()[0];
//                  (*it).getSyllables()[0] = (*it).getSyllables()[counterIt];
//                  (*it).getSyllables()[counterIt] = syllable;
//                  
//                  counterIt--;
//                  it--;
//              }
//
//              else if(((*it).getSyllables()[counterIt]->getSyllableType() == rVex::Syllable::MEM)  && (counterIt != 3))
//              {
//                  // exchange the indexes
//                  syllable = (*it).getSyllables()[3];
//                  (*it).getSyllables()[3] = (*it).getSyllables()[counterIt];
//                  (*it).getSyllables()[counterIt] = syllable;
//                  
//                  counterIt--;
//                  it--;
//              }   
//
//              else if(((*it).getSyllables()[counterIt]->getSyllableType() == rVex::Syllable::MUL) && ((counterIt != 1) & (counterIt != 2)))
//              {
//                  int index;                  
//                  
//                  // set up the index that will receive the MUL syllable
//                  if((*it).getSyllables()[1]->getSyllableType() != 2)
//                      index = 1;
//                  else
//                      index = 2;
//                  std::cout << "Passou aqui -> MUL" << std::endl;
//                  // exchange the indexes
//                  syllable = (*it).getSyllables()[index];
//                  (*it).getSyllables()[index] = (*it).getSyllables()[counterIt];
//                  (*it).getSyllables()[counterIt] = syllable;
//                                    
//                  counterIt--;
//                  it--;
//              }             
//          }
//          
//          counterIt++;             
//      }
//      int count = 0;
//      for(it = instructions.begin(); it == instructions.end(); it++)
//      {
//          std::cout << "Passou aqui -> " << std::endl;
//          std::cout << "OP " << (*it).getSyllables()[count]->getSyllableType() << std::endl;
//          count++;
//          if(count < 4)
//              break;
//          
//      }
//  }


}