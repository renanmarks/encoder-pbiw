/* 
 * File:   PBIWPattern.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include <typeinfo>
#include <iostream>
#include "rVex96PBIWPattern.h"
#include "Operand.h"

namespace PBIW
{
  using namespace Interfaces;
  
  rVex96PBIWPattern::rVex96PBIWPattern()
    : usageCounter(0)
  {
  }

  rVex96PBIWPattern::rVex96PBIWPattern(const rVex96PBIWPattern& orig)
    : usageCounter(orig.getUsageCounter())
  {
  }

  rVex96PBIWPattern::~rVex96PBIWPattern()
  {
    OperationVector::iterator it;

    for(it = operations.begin(); 
        it < operations.end(); 
        it++)
    {
      delete *it;
    }
    
    operations.clear();
  }

  void
  rVex96PBIWPattern::addOperation(IOperation* operation)
  {
    Operation* temp = dynamic_cast<Operation*> (operation);

    this->operations.push_back(temp);
  }

  void
  rVex96PBIWPattern::print(IPBIWPrinter& printer) const
  {
    printer.printPattern(*this);
  }

  void 
  rVex96PBIWPattern::reorganize()
  {
    Operand zero;
    
    // Generate NOPS if we have less than 4 operations in the pattern
    while ( operations.size() < 4)
    {
      Operation* operation = new Operation();
      operation->addOperand(zero);
      
      operations.push_back(operation);
    }
    
    OperationVector::iterator it;
    
    int counterIt = 0;
    IOperation* operation;

    // Go through all the syllables ordering them by TYPE (TODO: order then by opcode)
    for(it = operations.begin(); 
        it < operations.end(); 
        it++)
    {
      // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
      if( 
          (*it)->getOpcode() && 
          ((*it)->getType() != rVex::Syllable::SyllableType::ALU) 
        )
      {
        if(
            ((*it)->getType() == rVex::Syllable::SyllableType::CTRL) && 
            (counterIt != 0)
          )
        {
            // exchange the indexes
            operation = operations.at(0);
            operations.at(0) = operations.at(counterIt);
            operations.at(counterIt) = operation;

            counterIt--;
            it--;
        }
        else if(
                 ((*it)->getType() == rVex::Syllable::SyllableType::MEM) && 
                 (counterIt != 3)
               )
        {
            // exchange the indexes
            operation = operations.at(3);
            operations.at(3) = operations.at(counterIt);
            operations.at(counterIt) = operation;

            counterIt--;
            it--;
        }   

        else if(
                 ((*it)->getType() == rVex::Syllable::SyllableType::MUL) && 
                 ((counterIt != 1) && (counterIt != 2))
               )
        {
          int index;                  

          // set up the index that will receive the MUL syllable
          if (operations.at(1)->getType() != rVex::Syllable::SyllableType::MUL)
            index = 1;
          else
            index = 2;

          // exchange the indexes
          operation = operations.at(index);
          operations.at(index) = operations.at(counterIt);
          operations.at(counterIt) = operation;

          counterIt--;
          it--;
        }             
      }
      counterIt++;             
    }
  }
  
  bool
  rVex96PBIWPattern::operator<(const IPBIWPattern& other) const
  {
    return operations.size() < other.getOperationCount();
  }

  bool
  rVex96PBIWPattern::operator>(const IPBIWPattern& other) const
  {
    return operations.size() > other.getOperationCount();
  }

  bool
  rVex96PBIWPattern::operator<=(const IPBIWPattern& other) const
  {
    return (*this < other) || (*this == other);
  }

  bool
  rVex96PBIWPattern::operator>=(const IPBIWPattern& other) const
  {
    return (*this > other) || (*this == other);
  }

  bool
  rVex96PBIWPattern::operator==(const IPBIWPattern& other) const
  {
    const rVex96PBIWPattern& otherTemp = dynamic_cast<const rVex96PBIWPattern&>(other);

    unsigned int count = otherTemp.getOperationCount();

    if (operations.size() != count)
      return false;

    for (unsigned int i = 0; i < count; i++)
    {
      const IOperation& thisOperation = *(operations[i]);
      const IOperation& otherOperation = *(otherTemp.getOperation(i));
      
      if ( thisOperation != otherOperation )
        return false;
    }

    return true;
  }

  bool
  rVex96PBIWPattern::operator!=(const IPBIWPattern& other) const
  {
    return !(*this == other);
  }

}