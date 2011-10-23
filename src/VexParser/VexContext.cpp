/* 
 * File:   AsmContext.cpp
 * Author: helix
 * 
 * Created on September 3, 2011, 8:57 PM
 */

#include <iostream>
#include <string.h>
#include <algorithm>
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
    
    if (!instructions.empty())
    {
      InstructionList::iterator it;
      
      for (it = instructions.begin();
           it != instructions.end();
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
    switch(syllable->getOpcode())
    {
      case rVex::Syllable::opXNOP:
        return; // Does not support XNOP yet.
      
      case rVex::Syllable::opCALL:
      {
        Expression::ParseInfo argumentInfo = 
          arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
        
        if (argumentInfo.isLabel)
          controlSyllables.push_back(syllable);
        else
        {
          // If is a register, change CALL syllable to ICALL syllable
          rVex::Operations::CTRL::ICALL icall;
          memcpy(syllable, &icall, sizeof(icall));
        }
        
        break;
      }
      
      case rVex::Syllable::opGOTO:
      {
        Expression::ParseInfo argumentInfo = 
          arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
        
        if (argumentInfo.isLabel)
          controlSyllables.push_back(syllable);
        else
        {
          // If is a register, change GOTO syllable to IGOTO syllable
          rVex::Operations::CTRL::IGOTO igoto;
          memcpy(syllable, &igoto, sizeof(igoto));
        }
        
        break;
      }
      
      case rVex::Syllable::opRETURN:
      {
        Expression::ParseInfo argumentInfo = 
          arguments->getSourceArguments()->getArguments()[1]->getParsedValue();
        
        if (argumentInfo.isLabel)
          controlSyllables.push_back(syllable);
        
        break;
      }  
      
      case rVex::Syllable::opBR:
      case rVex::Syllable::opBRF:
          controlSyllables.push_back(syllable);
        break;
      
      default:
        break;
    }
    
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
      case rVex::Syllable::SyllableType::ALU:
        packSyllable(dynamic_cast<rVex::SyllableALU*>(syllable), arguments);
        break;
        
      case rVex::Syllable::SyllableType::MEM:
        packSyllable(dynamic_cast<rVex::SyllableMEM*>(syllable), arguments);
        break;
        
      case rVex::Syllable::SyllableType::MUL:
        packSyllable(dynamic_cast<rVex::SyllableMUL*>(syllable), arguments);
        break;
        
      case rVex::Syllable::SyllableType::CTRL:
        packSyllable(dynamic_cast<rVex::SyllableCTRL*>(syllable), arguments);
        break;
        
      default: // MISC
        packSyllable(dynamic_cast<rVex::SyllableMISC*>(syllable), arguments);
        break;
    }
  }
  
  void VexContext::processLabels()
  {
    std::ostream& stream = printer.getOutputStream();
    LabelVector::iterator labelIt;
    
    if (debugEnabled)
    {
      stream << "----- Labels.L/G [instr addr](syl addr)" << std::endl;

      for(labelIt = labels.begin();
          labelIt != labels.end();
          labelIt++)
      {
        stream << labelIt->name; 

        if (labelIt->scope == rVex::Label::GLOBAL)
          stream << ".G";
        else
          stream << ".L";

        stream << "[" << labelIt->absoluteAddress << "]"
          << "(" << labelIt->destiny->getAddress() << ")"
          << std::endl;
      }

      ControlSyllablesVector::const_iterator controlIt;

      stream << "----- Control instructions ("<< controlSyllables.size() << " Total)" << std::endl;

      for (controlIt = controlSyllables.begin();
           controlIt < controlSyllables.end();
           controlIt++)
      {
        stream << "Syllable " << "(opcode: " << (*controlIt)->getOpcode() << ") addr: " 
          << "[" << (*controlIt)->getBelongedInstruction()->getAddress() << "]"
          << "(" << (*controlIt)->getAddress() << ")"
          << std::endl;
      }
    }
    
    if (debugEnabled)
      std::cout << "----- Processing labels..." << std::endl;

    ControlSyllablesVector::const_iterator it;
    
    for (it = controlSyllables.begin();
         it < controlSyllables.end();
         it++)
    {
      std::string label = (*it)->getLabel();
      LabelVector::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if ( labelIt != (labels.end()+1) )
        (*it)->setLabelDestiny(labelIt->destiny);
    
      if (debugEnabled)
      {
        stream << "Syllable " << "(opcode: " << (*it)->getOpcode() << ") addr:"
          << "[" << (*it)->getBelongedInstruction()->getAddress() << "]"
          << "(" << (*it)->getAddress() << ")"
          << " now points to " << (*it)->getLabel()
          << "[" << (*it)->getLabelDestiny()->getBelongedInstruction()->getAddress() << "]"
          << "("  << (*it)->getLabelDestiny()->getAddress() << ")" 
          << std::endl;
      }
    }
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
    rVex::Instruction* instruction = new rVex::Instruction();
    
    reorder(syllableBuffer); // Reorder and put NOPs
    
    for (it = syllableBuffer.begin();
         it < syllableBuffer.end();
         it++)
    {
      (*it)->setAddress(this->syllableCounter++);
      (*it)->setBelongedInstruction(instruction);
      
      syllables.push_back(*it);
      instruction->addSyllable(**it);
    }
    
    instruction->setAddress(this->instructionCounter++);
    
    if (hasLabel) // Define the label
    {
      rVex::Label& label = labels.back();

      label.destiny = instruction->getSyllables()[0];
      label.absoluteAddress = instruction->getAddress();
      
      hasLabel = false;
    }
    
    syllableBuffer.clear();
    instructions.push_back(instruction);
  }
  
  rVex::Instruction*
  VexContext::getInstruction(unsigned int index)
  {
    InstructionList::iterator it = instructions.begin();
    unsigned int i = 0;
    
    while (i++ < index)
      it++;
    
    if (it != instructions.end())
      return *it;
    
    return NULL;
  }
  
  void
  VexContext::print()
  {
    InstructionList::const_iterator instructionIt;
    
    printer.printHeader();
    
    for(instructionIt = instructions.begin();
        instructionIt != instructions.end();
        instructionIt++)
    {
        (*instructionIt)->print(printer);
    }
    
    printer.printFooter();
  }
  

  void
  VexContext::enableDebugging(bool enableSwitch)
  {
    debugEnabled = enableSwitch;
  }

  void
  VexContext::reorder(SyllableBuffer& syllableBuffer)
  {
      int counterIt = 0;
      SyllableBuffer::iterator it;
      
      rVex::Syllable* syllable;
            
      // Generate NOPS if we have less than 4 syllables in the buffer
      while ( syllableBuffer.size() < 4 )
        syllableBuffer.push_back(new rVex::Operations::MISC::NOP());
      
      // Go through all the syllables ordering them
      for(it = syllableBuffer.begin(); 
          it < syllableBuffer.end(); 
          it++)
      {
          // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
          if( 
              (*it)->getOpcode() && 
              ((*it)->getSyllableType() != rVex::Syllable::SyllableType::ALU) 
            )
          {
              if(
                  ((*it)->getSyllableType() == rVex::Syllable::SyllableType::CTRL) && 
                  (counterIt != 0)
                )
              {
                  // exchange the indexes
                  syllable = syllableBuffer.at(0);
                  syllableBuffer.at(0) = syllableBuffer.at(counterIt);
                  syllableBuffer.at(counterIt) = syllable;
                  
                  counterIt--;
                  it--;
              }
              else if(
                       ((*it)->getSyllableType() == rVex::Syllable::SyllableType::MEM) && 
                       (counterIt != 3)
                     )
              {
                  // exchange the indexes
                  syllable = syllableBuffer.at(3);
                  syllableBuffer.at(3) = syllableBuffer.at(counterIt);
                  syllableBuffer.at(counterIt) = syllable;
                  
                  counterIt--;
                  it--;
              }   

              else if(
                       ((*it)->getSyllableType() == rVex::Syllable::SyllableType::MUL) && 
                       ((counterIt != 1) && (counterIt != 2))
                     )
              {
                  int index;                  
                  
                  // set up the index that will receive the MUL syllable
                  if (syllableBuffer.at(1)->getSyllableType() != rVex::Syllable::SyllableType::MUL)
                      index = 1;
                  else
                      index = 2;
                  
                  // exchange the indexes
                  syllable = syllableBuffer.at(index);
                  syllableBuffer.at(index) = syllableBuffer.at(counterIt);
                  syllableBuffer.at(counterIt) = syllable;
                                    
                  counterIt--;
                  it--;
              }             
          }
          counterIt++;             
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
////      SyllablesAux syllableBuffer;
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