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
  
  void VexContext::packSyllable(rVex::SyllableALU* syllable, SyllableArguments* arguments) // O(1)
  {
    switch(syllable->getOpcode())
    {
      // If is a MOV with immediate operand then is a pseudo-instruction...
      case rVex::Syllable::opMOV:
      {
        // Change MOV syllable to ADD syllable
        rVex::Operations::ALU::ADD add;
        memcpy(syllable, &add, sizeof(add)); // O(1)

        int value = arguments->getSourceArguments()->getArguments()[0]->getValue(); // O(1)
          
        if (arguments->getSourceArguments()->getArguments()[0]->getParsedValue().isImmediate) // O(1)
        {
          // Change from: mov $r0.x = 12345
          // to: add $r0.x = $r0.0, 12345
          arguments->getSourceArguments()->clearArguments(); // O(1)
          arguments->getSourceArguments()->addArgument(new Expression("$r0.0")); // O(1)
          arguments->getSourceArguments()->addArgument(new Expression(value)); // O(1)
        }
        else
        {
          // Change from: mov $r0.x = $r0.y
          // to: add $r0.x = $r0.y, $r0.0
          int value = arguments->getSourceArguments()->getArguments()[0]->getValue(); // O(1)
          
          std::stringstream strBuilder;
          strBuilder << "$r0." << value << std::endl;
          
          arguments->getSourceArguments()->addArgument(new Expression("$r0.0")); // O(1)
          arguments->getSourceArguments()->addArgument(new Expression(strBuilder.str())); // O(1)
        }
      } 
      break;
      
      case rVex::Syllable::opCMPEQ:
      case rVex::Syllable::opCMPGE:
      case rVex::Syllable::opCMPGEU:
      case rVex::Syllable::opCMPGT:
      case rVex::Syllable::opCMPGTU:
      case rVex::Syllable::opCMPLE:
      case rVex::Syllable::opCMPLEU:
      case rVex::Syllable::opCMPLT:
      case rVex::Syllable::opCMPLTU:
      case rVex::Syllable::opCMPNE:
      case rVex::Syllable::opNANDL:
      case rVex::Syllable::opNORL:
      case rVex::Syllable::opORL:
        // Change from: cmpXX $r0.x = $r0.y, 12345
        // to: 
        // add $r0.32 = $r0.0, 12345
        // cmpXX $r0.x = $r0.y, $r0.32
        
        // WARNING: this is only suitable if the PBIW encoding supports indexing
        // the $r0.32 register
        if (arguments->getSourceArguments()->getArguments()[1]->getParsedValue().isImmediate)
        {
          // If not enought space to fit the add, get a new instruction
          if (syllableBuffer.size() > 3)
            endInstruction(); // O(1)
          
          // Save cmpXX original values for posterior use
          bool isBR = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue().isBranchRegister;
          int destinyReg = arguments->getDestinyArguments()->getArguments()[0]->getValue();
          int sourceReg = arguments->getSourceArguments()->getArguments()[0]->getValue();
          int value = arguments->getSourceArguments()->getArguments()[1]->getValue();
          
          rVex::SyllableALU* add = new rVex::Operations::ALU::ADD();

          arguments->getDestinyArguments()->clearArguments();
          arguments->getSourceArguments()->addArgument(new Expression("$r0.32"));
          
          arguments->getSourceArguments()->clearArguments();
          arguments->getSourceArguments()->addArgument(new Expression("$r0.0"));
          arguments->getSourceArguments()->addArgument(new Expression(value));
          
          add->fillSyllable(arguments); // O(1)
          syllableBuffer.push_back(add); // O(1)
          
          // Get a new instruction because of the use of the previous 
          // assigned register $r0.32
          endInstruction(); // O(1)
          
          // Used to construct the register strings
          std::stringstream strBuilder; 
          
          strBuilder << "$r0." << destinyReg << std::endl;
          std::string destinyRegStr = strBuilder.str();
          
          if (isBR)
          {
            strBuilder.clear();
            strBuilder << "$b0." << destinyReg << std::endl;
            destinyRegStr = strBuilder.str();
          }
          
          arguments->getDestinyArguments()->clearArguments();
          arguments->getDestinyArguments()->addArgument(new Expression(destinyRegStr));
          
          strBuilder.clear();
          strBuilder << "$r0." << sourceReg << std::endl;
          arguments->getSourceArguments()->clearArguments();
          arguments->getSourceArguments()->addArgument(new Expression(strBuilder.str()));
          arguments->getSourceArguments()->addArgument(new Expression("$r0.32"));
          
          syllable->fillSyllable(arguments);
          syllableBuffer.push_back(syllable);
          endInstruction();
          
          return;
        }
      break;
    }

    syllable->fillSyllable(arguments);
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableMEM* syllable, SyllableArguments* arguments) // O(1)
  {
    syllable->fillSyllable(arguments); // O(1)
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableMUL* syllable, SyllableArguments* arguments) // O(1)
  {
    syllable->fillSyllable(arguments);
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableCTRL* syllable, SyllableArguments* arguments) // O(1)
  {
    switch(syllable->getOpcode())
    {
      case rVex::Syllable::opXNOP:
        delete syllable;
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
          memcpy(syllable, &icall, sizeof(icall)); // O(1)
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
    
    syllable->fillSyllable(arguments); // O(1)
    syllableBuffer.push_back(syllable);
  }
  
  void VexContext::packSyllable(rVex::SyllableMISC* syllable, SyllableArguments* arguments) // O(1)
  {
    syllable->fillSyllable(arguments); // O(1)
    syllableBuffer.push_back(syllable);
  }
    
  void VexContext::packSyllable(rVex::Syllable* syllable, SyllableArguments* arguments) // O(1)
  {
    switch(syllable->getSyllableType()) // O(1)
    {
      case rVex::Syllable::SyllableType::ALU: // O(1)
        packSyllable(dynamic_cast<rVex::SyllableALU*>(syllable), arguments); // O(1)
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
  
  void VexContext::processLabels()  // O(|labels| + |controlSyllables| + |controlSyllables|) = O(1)
  {
    std::ostream& stream = printer.getOutputStream(); // O(1)
    LabelVector::iterator labelIt;
    
    if (debugEnabled)
    {
      stream << "----- Labels.L/G [instr addr](syl addr)" << std::endl;

      for(labelIt = labels.begin(); // O(|labels|) = O(1)
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

      for (controlIt = controlSyllables.begin(); // O(|controlSyllables|) = O(1)
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
    
    for (it = controlSyllables.begin(); // O(|controlSyllables|) = O(1)
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
  
  void VexContext::setLabel(std::string name, rVex::Label::LabelScope scope)  // O(1)
  { 
    rVex::Label label;
    
    hasLabel = true;
    
    label.name = name;
    label.scope = scope;
    
    labels.push_back(label);
  }
  
  void VexContext::endInstruction() // O(1)
  {
    SyllableBuffer::iterator it;
    rVex::Instruction* instruction = new rVex::Instruction();
    
    reorder(syllableBuffer); // Reorder and put NOPs
    
    for (it = syllableBuffer.begin(); // O(|syllableBuffer|) = O(4) = O(1)
         it < syllableBuffer.end();
         it++)
    {
      (*it)->setAddress(this->syllableCounter++); // O(1)
      (*it)->setBelongedInstruction(instruction); // O(1)
      
      syllables.push_back(*it);
      instruction->addSyllable(**it); // O(1)
    }
    
    instruction->setAddress(this->instructionCounter++); // O(1)
    
    if (hasLabel) // Define the label
    {
      rVex::Label& label = labels.back(); // O(1)

      label.destiny = instruction->getSyllables()[0]; // O(1)
      label.absoluteAddress = instruction->getAddress(); // O(1)
      
      instruction->setLabel(label);  // O(1)
      
      hasLabel = false;
    }
    
    syllableBuffer.clear();
    instructions.push_back(instruction);
  }
  
  rVex::Instruction*
  VexContext::getInstruction(unsigned int index) // O(|isntructions|)
  {
    InstructionList::iterator it = instructions.begin();
    unsigned int i = 0;
    
    while (i++ < index) // O(|instructions|)
      it++;
    
    if (it != instructions.end())
      return *it;
    
    return NULL;
  }
  
  void
  VexContext::print()  // O(|instructions|)
  {
    InstructionList::const_iterator instructionIt;
    
    printer.printHeader(); // O(1)
    
    for(instructionIt = instructions.begin();  // O(|instructions|)
        instructionIt != instructions.end();
        instructionIt++)
    {
        (*instructionIt)->print(printer); // O(1)
    }
    
    printer.printFooter(); // O(1)
  }
  

  void
  VexContext::enableDebugging(bool enableSwitch) // O(1)
  {
    debugEnabled = enableSwitch;
  }

  void
  VexContext::reorder(SyllableBuffer& syllableBuffer) // O(1)
  {
      int counterIt = 0;
      SyllableBuffer::iterator it;
      
      rVex::Syllable* syllable;
            
      // Generate NOPS if we have less than 4 syllables in the buffer
      while ( syllableBuffer.size() < 4 ) // O(1)
        syllableBuffer.push_back(new rVex::Operations::MISC::NOP());
      
      // Go through all the syllables ordering them
      for(it = syllableBuffer.begin(); // O(|syllableBuffer|) = O(4) = O(1)
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
      
  void 
  VexContext::encodePBIW(PBIW::Interfaces::IPBIW& pbiw, PBIW::Interfaces::IPBIWPrinter& pbiwPrinter) const // O(|codedPatterns|^2 + |instructions|) =
  {                                                                                                        // O(|codedPatterns|^2)
    std::vector<rVex::Instruction*> instructionVector(instructions.begin(), instructions.end());
    
    pbiw.encode(instructionVector); // O(|codedPatterns|^2)
    pbiw.print(pbiwPrinter); // O(|instructions|)
  }
}