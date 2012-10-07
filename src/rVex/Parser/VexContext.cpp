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
#include "src/rVex/Printers/rVexPrinter.h"
#include "src/PBIW/Interfaces/IPBIW.h"
#include "Processors/SyllablePacker.h"
#include "Processors/PseudoSyllableProcessor.h"

namespace VexParser
{
  void
  VexContext::setInstructions(const rVexInstructionList& instructions)
  {
    this->instructions=instructions;
  }
  
  IContext::InstructionDeque
  VexContext::getInstructions() const
  { 
    return IContext::InstructionDeque(instructions.begin(), instructions.end()); 
  }

  void
  VexContext::setOperations(const rVexSyllableList& syllables)
  { 
    this->syllables = syllables; 
  }

  IContext::OperationDeque
  VexContext::getOperations() const
  { 
    return IContext::OperationDeque(syllables.begin(), syllables.end()); 
  }

  void
  VexContext::setSyllableBuffer(const SyllableBuffer& syllableBuffer)
  { 
    this->syllableBuffer = syllableBuffer; 
  }

  VexContext::SyllableBuffer&
  VexContext::getSyllableBuffer()
  { 
    return syllableBuffer; 
  }

  void
  VexContext::setControlSyllables(const ControlSyllablesVector& controlSyllables)
  { 
    this->controlSyllables = controlSyllables; 
  }

  VexContext::ControlSyllablesVector&
  VexContext::getControlSyllables()
  { 
    return controlSyllables; 
  }

  void
  VexContext::setLabels(const rVexLabelVector& labels)
  { 
    this->labels = labels; 
  }

  IContext::LabelDeque
  VexContext::getLabels() const
  { 
    rVexLabelVector::const_iterator it;
    IContext::LabelDeque returnDeque;
    
    for (it = labels.begin();
         it != labels.end();
         it++)
    {
      returnDeque.push_back( const_cast<rVex::Label*>(&(*it)) );
    }
    
    return returnDeque; 
  }
  
  VexContext::~VexContext( )
  {
    if (!syllables.empty())
    {
      rVexSyllableList::iterator it;
      
      for (it = syllables.begin();
           it != syllables.end();
           it++)
      {
        delete *it;
      }
    }
    
    if (!instructions.empty())
    {
      rVexInstructionList::iterator it;
      
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
  
  void VexContext::packSyllable(rVex::Syllable* syllable, SyllableArguments& arguments)  // O(1)
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
  
  void VexContext::postProcess() // O(|labels| + |controlSyllables| + |controlSyllables|) = O(1)
  {
    Processors::PseudoSyllableProcessor processor(*this);
    
    SyllableBuffer::iterator it;
    SyllableBuffer newBuffer = syllableBuffer;
    
    syllableBuffer.clear();
    
    for (it = newBuffer.begin();
         it < newBuffer.end();
         it++)
    {
      rVex::Syllable* syllable = it->getSyllable();
      VexParser::SyllableArguments arguments = it->getArguments();
      
      syllableBuffer.push_back(*it);
      
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
    rVexLabelVector::iterator labelIt;
    
    if (debugEnabled)
    {
      std::cout << "----- Labels.L/G [instr addr](syl addr)" << std::endl;

      for(labelIt = labels.begin(); // O(|labels|) = O(1)
          labelIt != labels.end();
          labelIt++)
      {
        std::cout << labelIt->getName(); 

        if (labelIt->getScope() == GenericAssembly::Utils::LabelScope::GLOBAL)
          std::cout << ".G";
        else
          std::cout << ".L";

        std::cout << "[" << labelIt->getAbsoluteAddress() << "]"
          << "(" << labelIt->getDestiny()->getAddress() << ")"
          << std::endl;
      }

      ControlSyllablesVector::const_iterator controlIt;

      std::cout << "----- Control instructions ("<< controlSyllables.size() << " Total)" << std::endl;

      for (controlIt = controlSyllables.begin(); // O(|controlSyllables|) = O(1)
           controlIt < controlSyllables.end();
           controlIt++)
      {
        std::cout << "Syllable " << "(opcode: " << (*controlIt)->getOpcode() << ") addr: " 
          << "[" << (*controlIt)->getBelongedInstruction()->getAddress() << "]"
          << "(" << (*controlIt)->getAddress() << ")"
          << std::endl;
      }
    }
    
    if (debugEnabled)
      std::cout << "----- Processing labels..." << std::endl;

    ControlSyllablesVector::const_iterator it;
    
    for (it = controlSyllables.begin(); // O(|controlSyllables|) = O(1)
         it < controlSyllables.end();
         it++)
    {
      std::string label = (*it)->getLabelDestiny();
      rVexLabelVector::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if ( labelIt != labels.end() )
        (*it)->setBranchDestiny(dynamic_cast<rVex::Syllable*>(labelIt->getDestiny()));
    
      if (debugEnabled)
      {
        std::cout << "Syllable " << "(opcode: " << (*it)->getOpcode() << ") addr:"
          << "[" << (*it)->getBelongedInstruction()->getAddress() << "]"
          << "(" << (*it)->getAddress() << ")"
          << " now points to " << (*it)->getLabelDestiny()
          << "[" << (*it)->getBranchDestiny()->getBelongedInstruction()->getAddress() << "]"
          << "("  << (*it)->getBranchDestiny()->getAddress() << ")" 
          << std::endl;
      }
    }
  }
  
  void VexContext::setLabel(std::string name, GenericAssembly::Utils::LabelScope::Type scope)  // O(1)
  { 
    rVex::Label label;
    
    hasLabel = true;
    
    label.setName(name);
    label.setScope(scope);
    
    labels.push_back(label);
  }

  void VexContext::endInstruction() // O(1)
  {
    SyllableBuffer::iterator it;
    rVex::Instruction* instruction = new rVex::Instruction();
    
    postProcess(); // post process
    
    // Generate NOPS if we have less than 4 syllables in the buffer
    while ( syllableBuffer.size() < 4 ) // O(1)
      syllableBuffer.push_back(Structs::SyllableBufferItem(new rVex::Operations::MISC::NOP()));
    
    for (it = syllableBuffer.begin(); // O(|syllableBuffer|) = O(4) = O(1)
         it < syllableBuffer.end();
         it++)
    {
      it->getSyllable()->setAddress(this->syllableCounter++); // O(1)
      it->getSyllable()->setBelongedInstruction(instruction); // O(1)
      
      syllables.push_back( it->getSyllable() );
      instruction->addSyllable( *it->getSyllable() ); // O(1)
    }
    
    instruction->setAddress(this->instructionCounter++); // O(1)
    instruction->setWordAddress(this->lastWordAddress);
    this->lastWordAddress += instruction->getQuantityNotNopOperations();
    
    if (hasLabel) // Define the label
    {
      rVex::Label& label = labels.back(); // O(1)

      label.setDestiny(instruction->getSyllables()[0]); // O(1)
      label.setAbsoluteAddress(instruction->getAddress()); // O(1)
      
      instruction->setLabel(label);  // O(1)
      
      hasLabel = false;
    }
    
    instruction->buildSyllableDependencies();
    
    syllableBuffer.clear();
    instructions.push_back(instruction);
  }
  
  rVex::Instruction*
  VexContext::getInstruction(unsigned int index) // O(|isntructions|)
  {
    rVexInstructionList::iterator it = instructions.begin();
    unsigned int i = 0;
    
    while (i++ < index) // O(|instructions|)
      it++;
    
    if (it != instructions.end())
      return *it;
    
    return NULL;
  }
  
  void
  VexContext::print(rVex::Printers::IPrinter& printer)  // O(|instructions|)
  {
    rVexInstructionList::const_iterator instructionIt;
    
    //printer.printHeader(); // O(1)
    
    for(instructionIt = instructions.begin();  // O(|instructions|)
        instructionIt != instructions.end();
        instructionIt++)
    {
      rVexInstructionList::const_iterator next = instructionIt;
      next++;
      
      // Do not print to "nop/nop/nop/stop" instructions
      if (next == instructions.end())
        break;
      
      (*instructionIt)->print(printer); // O(1)
    }
    
    //printer.printFooter(); // O(1)
  }
  

  void
  VexContext::enableDebugging(bool enableSwitch) // O(1)
  {
    debugEnabled = enableSwitch;
  }

  
  
  void 
  VexContext::endParsing()
  {
    SyllableArguments dummyArguments;
    
//    this->packSyllable(new rVex::Operations::MISC::NOP(), dummyArguments);
//    this->packSyllable(new rVex::Operations::MISC::NOP(), dummyArguments);
//    this->packSyllable(new rVex::Operations::MISC::NOP(), dummyArguments);
    this->newInstruction();
    this->packSyllable(new rVex::Operations::MISC::STOP(), dummyArguments);
    this->endInstruction();
  }
  
  void 
  VexContext::encodePBIW(PBIW::Interfaces::IPBIW& pbiw) const // O(|codedPatterns|^2 + |instructions|) =
  {                                                                                                        // O(|codedPatterns|^2)
    std::deque<GenericAssembly::Interfaces::IInstruction*> instructionVector(instructions.begin(), instructions.end());
    
    pbiw.encode(instructionVector); // O(|codedPatterns|^2)
  }
}