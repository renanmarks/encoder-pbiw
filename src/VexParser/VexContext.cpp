/* 
 * File:   AsmContext.cpp
 * Author: helix
 * 
 * Created on September 3, 2011, 8:57 PM
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include "VexContext.h"
#include "src/rVex/SyllableALU.h"
#include "src/rVex/SyllableMISC.h"
#include "src/rVex/Syllable.h"

#include "Expressions/SyllableArguments.h"
#include "src/rVex/Operations/ALU/ADD.h"
#include "src/rVex/Operations/ALU/MOV.h"
#include "src/rVex/Printers/rVexPrinter.h"
#include "src/PBIW/Interfaces/IPBIW.h"
#include "Processors/SyllablePacker.h"
#include "Processors/PseudoSyllableProcessor.h"

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
  
  void VexContext::packSyllable(rVex::Syllable* syllable, SyllableArguments& arguments)
  {
    Processors::SyllablePacker packer(*this);
    
    switch(syllable->getSyllableType())
    {
      case rVex::Syllable::SyllableType::ALU:
        packer.process(dynamic_cast<rVex::SyllableALU*>(syllable), arguments);
        break;
        
      case rVex::Syllable::SyllableType::MEM:
        packer.process(dynamic_cast<rVex::SyllableMEM*>(syllable), arguments);
        break;
        
      case rVex::Syllable::SyllableType::MUL:
        packer.process(dynamic_cast<rVex::SyllableMUL*>(syllable), arguments);
        break;
        
      case rVex::Syllable::SyllableType::CTRL:
        packer.process(dynamic_cast<rVex::SyllableCTRL*>(syllable), arguments);
        break;
        
      default: // MISC
        packer.process(dynamic_cast<rVex::SyllableMISC*>(syllable), arguments);
        break;
    }
  }
  
  void VexContext::postProcess()
  {
    Processors::PseudoSyllableProcessor processor(*this);
    
    SyllableBuffer::iterator it;
    
    for (it = syllableBuffer.begin();
         it < syllableBuffer.end();
         it++)
    {
      rVex::Syllable* syllable = it->getSyllable();
      VexParser::SyllableArguments arguments = it->getArguments();
      
      switch(syllable->getSyllableType())
      {
        case rVex::Syllable::SyllableType::ALU:
          processor.process(dynamic_cast<rVex::SyllableALU*>(syllable), arguments);
          break;

        case rVex::Syllable::SyllableType::MEM:
          processor.process(dynamic_cast<rVex::SyllableMEM*>(syllable), arguments);
          break;

        case rVex::Syllable::SyllableType::MUL:
          processor.process(dynamic_cast<rVex::SyllableMUL*>(syllable), arguments);
          break;

        case rVex::Syllable::SyllableType::CTRL:
          processor.process(dynamic_cast<rVex::SyllableCTRL*>(syllable), arguments);
          break;

        default: // MISC
          processor.process(dynamic_cast<rVex::SyllableMISC*>(syllable), arguments);
          break;
      }
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
      
      if ( labelIt != labels.end() )
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
    
    postProcess(); // post process
    reorder(); // Reorder and put NOPs
    
    for (it = syllableBuffer.begin();
         it < syllableBuffer.end();
         it++)
    {
      it->getSyllable()->setAddress(this->syllableCounter++);
      it->getSyllable()->setBelongedInstruction(instruction);
      
      syllables.push_back( it->getSyllable() );
      instruction->addSyllable( *it->getSyllable() );
    }
    
    instruction->setAddress(this->instructionCounter++);
    
    if (hasLabel) // Define the label
    {
      rVex::Label& label = labels.back();

      label.destiny = instruction->getSyllables()[0];
      label.absoluteAddress = instruction->getAddress();
      
      instruction->setLabel(label);
      
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
  VexContext::reorder()
  {
      int counterIt = 0;
      SyllableBuffer::iterator it;
            
      // Generate NOPS if we have less than 4 syllables in the buffer
      while ( syllableBuffer.size() < 4 )
        syllableBuffer.push_back(Structs::SyllableBufferItem(new rVex::Operations::MISC::NOP()));
      
      // Go through all the syllables ordering them
      for(it = syllableBuffer.begin(); 
          it < syllableBuffer.end(); 
          it++)
      {
        rVex::Syllable* syllableIt = it->getSyllable();
        
          // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
          if( 
              syllableIt->getOpcode() && 
              (syllableIt->getSyllableType() != rVex::Syllable::SyllableType::ALU) 
            )
          {
              if(
                  (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::CTRL) && 
                  (counterIt != 0)
                )
              {
                  // exchange the indexes
                  Structs::SyllableBufferItem syllableBufferItem = syllableBuffer.at(0);
                  syllableBuffer.at(0) = syllableBuffer.at(counterIt);
                  syllableBuffer.at(counterIt) = syllableBufferItem;
                  
                  counterIt--;
                  it--;
              }
              else if(
                       (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::MEM) && 
                       (counterIt != 3)
                     )
              {
                  // exchange the indexes
                  Structs::SyllableBufferItem syllableBufferItem = syllableBuffer.at(3);
                  syllableBuffer.at(3) = syllableBuffer.at(counterIt);
                  syllableBuffer.at(counterIt) = syllableBufferItem;
                  
                  counterIt--;
                  it--;
              }   

              else if(
                       (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::MUL) && 
                       ((counterIt != 1) && (counterIt != 2))
                     )
              {
                  int index;                  
                  
                  // set up the index that will receive the MUL syllable
                  if (syllableBuffer.at(1).getSyllable()->getSyllableType() != rVex::Syllable::SyllableType::MUL)
                      index = 1;
                  else
                      index = 2;
                  
                  // exchange the indexes
                  Structs::SyllableBufferItem syllableBufferItem = syllableBuffer.at(index);
                  syllableBuffer.at(index) = syllableBuffer.at(counterIt);
                  syllableBuffer.at(counterIt) = syllableBufferItem;
                                    
                  counterIt--;
                  it--;
              }             
          }
          counterIt++;             
      }
    }      
      
  void 
  VexContext::encodePBIW(PBIW::Interfaces::IPBIW& pbiw, PBIW::Interfaces::IPBIWPrinter& pbiwPrinter) const
  {
    std::vector<rVex::Instruction*> instructionVector(instructions.begin(), instructions.end());
    
    pbiw.encode(instructionVector);
    pbiw.print(pbiwPrinter);
  }
}