/* 
 * File:   Instruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 4:19 PM
 */

#include "Instruction.h"
#include "Syllable.h"
#include "src/rVex/Printers/IPrinter.h"
#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "Utils/OperandVectorBuilder.h"

namespace rVex
{

  Instruction::Instruction()
  : address(0)
  {

  }
  
  Instruction::~Instruction()
  {
    
  }

  unsigned int 
  Instruction::getAddress() const
  {
    return address;
  }
  
  void 
  Instruction::setAddress(unsigned int address)
  {
    this->address = address;
  }
  
  void
  Instruction::setLabel(rVex::Label& label)
  {
    this->labels.push_back(&label);
  }

  bool
  Instruction::haveLabels() const
  {
    return this->labels.size() > 0;
  }

  Instruction::LabelDeque
  Instruction::getLabels() const
  {
    return Instruction::LabelDeque(labels.begin(), labels.end());
  }

  void
  Instruction::setWordAddress(unsigned int wordAddress)
  {
    this->wordAddress=wordAddress;
  }

  unsigned int
  Instruction::getWordAddress() const
  {
    return wordAddress;
  }

  void
  Instruction::buildSyllableDependencies()
  {
    dependencies.buildDependenciesChains(*this);
  }

  bool
  Instruction::canSplitInstruction(const IOperation& syllable) const
  {
    return dependencies.canSplitSyllable(dynamic_cast<const Syllable&>(syllable));
  }

  unsigned int
  Instruction::getQuantityNotNopOperations() const
  {
    SyllableCollection::const_iterator it;

    unsigned int quantity=0;

    for (it=syllables.begin(); it < syllables.end(); it++)
    {
      if ((*it)->getOpcode() != rVex::Syllable::opNOP)
        quantity++;
    }

    // All nops
    if (quantity == 0)
      return 1;

    return quantity;
  }

  void
  Instruction::addReferencePBIWInstruction(const PBIW::Interfaces::IPBIWInstruction& instruction)
  {
    this->pbiwInstructions.insert(&instruction);
  }

  std::set<const PBIW::Interfaces::IPBIWInstruction*>
  Instruction::getPBIWInstructions() const
  {
    return this->pbiwInstructions;
  }

  bool
  Instruction::addSyllable(Syllable& syllable) // O(1)
  {
    if (this->syllables.size() < this->syllables.max_size()) // O(1)
    {
      this->syllables.push_back(&syllable); // O(1)
      return true;
    }

    return false;
  }

  bool
  Instruction::removeSyllable(const Syllable& syllable) // O(1)
  {
    if (this->syllables.size() > 0) // O(1)
    {
      SyllableCollection::iterator it;

      it=std::find(this->syllables.begin(), this->syllables.end(), &syllable);

      if (it != this->syllables.end())
      {
        this->syllables.erase(it);
        return true;
      }
    }

    return false;
  }

  Instruction::SyllableCollection
  Instruction::getOrderedSyllables() const
  {
    Instruction::SyllableCollection orderedSyllables=this->syllables;

    int counterIt=0;
    Instruction::SyllableCollection::iterator it;

    // Go through all the syllables ordering them
    for (it=orderedSyllables.begin(); // O(|syllableBuffer|) = O(4) = O(1)
         it < orderedSyllables.end();
         it++)
    {
      rVex::Syllable* syllableIt= *it;

      // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
      if (
          syllableIt->getOpcode() &&
          (syllableIt->getSyllableType() != rVex::Syllable::SyllableType::ALU)
          )
      {
        if (
            (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::CTRL) &&
            (counterIt != 0)
            )
        {
          // exchange the indexes
          rVex::Syllable* syllable=orderedSyllables.at(0);
          orderedSyllables.at(0)=orderedSyllables.at(counterIt);
          orderedSyllables.at(counterIt)=syllable;

          counterIt--;
          it--;
        } else if (
                   (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::MEM) &&
                   (counterIt != 3)
                   )
        {
          // exchange the indexes
          rVex::Syllable* syllable=orderedSyllables.at(3);
          orderedSyllables.at(3)=orderedSyllables.at(counterIt);
          orderedSyllables.at(counterIt)=syllable;

          counterIt--;
          it--;
        }
        else if (
                 (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::MUL) &&
                 ((counterIt != 1) && (counterIt != 2))
                 )
        {
          int index;

          // set up the index that will receive the MUL syllable
          if (orderedSyllables.at(1)->getSyllableType() != rVex::Syllable::SyllableType::MUL)
            index=1;
          else
            index=2;

          // exchange the indexes
          rVex::Syllable* syllable=orderedSyllables.at(index);
          orderedSyllables.at(index)=orderedSyllables.at(counterIt);
          orderedSyllables.at(counterIt)=syllable;

          counterIt--;
          it--;
        }
      }
      counterIt++;
    }

    // Invert the ordering to MEM, ALU, ALU, CTRL to match de rVex slots
    Instruction::SyllableCollection reverseOrderedSyllables(orderedSyllables.rbegin(), orderedSyllables.rend());

    return reverseOrderedSyllables;
  }

  void 
  Instruction::minimizeOperationDependency()
  {
    dependencies.sortOperations(*this);
  }
  
  struct MinimumAddress
  {
    bool operator()(GenericAssembly::Interfaces::IOperation* first, GenericAssembly::Interfaces::IOperation* second)
    {
      return first->getAddress() < second->getAddress();
    }
  };
  
  void 
  Instruction::setOperations(Instruction::OperationDeque& operations)
  {
    syllables.clear();
    
    MinimumAddress min;
    Instruction::OperationDeque::iterator opIt = std::min_element(operations.begin(), operations.end(), min);
    int miniumAddress = (*opIt)->getAddress();
    
    Instruction::OperationDeque::iterator it;
    
    for (it = operations.begin(); it != operations.end(); it++)
    {
      (*it)->setAddress(miniumAddress++);
      syllables.push_back( dynamic_cast<Syllable*>(*it) );
    }
    
    this->buildSyllableDependencies();
  }
  
  Instruction::OperationDeque 
  Instruction::getOperations() const
  {
    return Instruction::OperationDeque(syllables.begin(), syllables.end());
  }
  
  Instruction::SyllableCollection
  Instruction::getSyllables() const // O(1)
  {
    return this->syllables;
  }

  void
  Instruction::print(rVex::Printers::IPrinter& printer) const
  {
    printer.printInstruction(*this);
  }

  void
  Instruction::printSyllableDependencies(rVex::Printers::IPrinter& printer) const
  {
    dependencies.print(printer);
  }
}
