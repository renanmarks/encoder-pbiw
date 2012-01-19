/* 
 * File:   PBIWPattern.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include <typeinfo>
#include <iostream>
#include <stdexcept>
#include "rVex96PBIWPattern.h"
#include "Operand.h"
#include "PartialPBIWPrinter.h"
#include "Interfaces/IPBIWInstruction.h"
//#include "Operation.h"

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
  rVex96PBIWPattern::addOperation(IOperation* operation) // O(1)
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
  rVex96PBIWPattern::reorganize(const IPBIWInstruction* instruction) // O(1)
  {
    Operand zero;
    
    // Generate NOPS if we have less than 4 operations in the pattern
    while ( operations.size() < 4) // O( |operations| ) = O(4) = O(1)
    {
      Operation* operation = new Operation();
      operation->addOperand(zero);
      
      operations.push_back(operation);
    }
    
    OperationVector::iterator it;
    IOperation::OperandIndexVector operandsOp1;
    IOperation::OperandIndexVector operandsOp2;
     
    int counterIt = 0;

    // Go through all the syllables ordering them by TYPE (TODO: order then by opcode)
    for(it = operations.begin();        // O( |operations| ) = O(4) = O(1)
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
            this->exchangeOperations(0, counterIt);

            counterIt--;
            it--; 
        }
        else if(
                 ((*it)->getType() == rVex::Syllable::SyllableType::MEM) && 
                 (counterIt != 3)
               )
        {            
            this->exchangeOperations(3, counterIt);
            
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
          {
              index = 1;
          }            
          else {
              
              index = 2;
              
              if(operations.at(1)->getOpcode() > operations.at(counterIt)->getOpcode())
              {
                  this->exchangeOperations(1, counterIt);
              }                  
          }                    
                    
          this->exchangeOperations(index, counterIt);
          
          counterIt--;
          it--;
        }        
        
        if((operations.at(1)->getType() == rVex::Syllable::SyllableType::MUL) &&
                (operations.at(2)->getType() == rVex::Syllable::SyllableType::MUL))
        {
            if(operations.at(1)->getOpcode() > operations.at(2)->getOpcode())
            {
                this->exchangeOperations(1, 2);
            }
            else if(operations.at(1)->getOpcode() == operations.at(2)->getOpcode())
            {
                  operandsOp1 = operations.at(1)->getOperandsIndexes();
                  operandsOp2 = operations.at(2)->getOperandsIndexes();
                  
                  if(this->getValueByIndex(instruction, operandsOp1.at(0)) >
                     this->getValueByIndex(instruction, operandsOp2.at(0))
                    )
                  { 
                      this->exchangeOperations(1, 2);
                  }                  
            }
        }
          
      }
      counterIt++;             
    }
    
    unsigned int index1;
    unsigned int index2;
    
    // Ordering of the ALU operations by opcode, when this operations have differents
    // opcodes. Otherwise (equals opcode) the ALU operations are ordering by 
    // write operand, or first read operand or second read operand/immediate.
    for(index2 = 0;
        index2 < operations.size();// O(|operations| * |operations|) = O(16) = O(1)
        index2 ++)
    {    
        for(index1 = 0;
            index1 < operations.size(); // O(|operations|) = O(4) = O(1)
            index1 ++)
        {   
            if((operations.at(index1)->getType() == rVex::Syllable::SyllableType::ALU) &&
                (operations.at(index2)->getType() == rVex::Syllable::SyllableType::ALU)
            )
            {
                if(operations.at(index1)->getOpcode() > operations.at(index2)->getOpcode())
                {
                    this->exchangeOperations(index1, index2);
                }
                else if(
                  (operations.at(index1)->getOpcode() == operations.at(index2)->getOpcode())
                )
                {
                    operandsOp1 = operations.at(index1)->getOperandsIndexes();
                    operandsOp2 = operations.at(index2)->getOperandsIndexes();

                    if(
                      (this->getValueByIndex(instruction, operandsOp1.at(0)) > 
                      this->getValueByIndex(instruction, operandsOp2.at(0)))
                    )
                    {
                        this->exchangeOperations(index1, index2);
                    }
                    else if(
                      (this->getValueByIndex(instruction, operandsOp1.at(0)) ==
                      this->getValueByIndex(instruction, operandsOp2.at(0)))
                    )
                    {
                        if(this->getValueByIndex(instruction, operandsOp1.at(1)) >
                           this->getValueByIndex(instruction, operandsOp2.at(1)))
                        {                            
                            this->exchangeOperations(index1, index2);
                        }
                        else if(this->getValueByIndex(instruction, operandsOp1.at(1)) >
                                this->getValueByIndex(instruction, operandsOp2.at(1)))
                        {
                            this->exchangeOperations(index1, index2);
                        }
                    }
                }
            }     
            else if(((operations.at(index1)->getOpcode() == 0) && 
                    (operations.at(index2)->getType() == rVex::Syllable::SyllableType::ALU))
                   ) 
            {
                this->exchangeOperations(index1, index2);
            }
        }
    }    
  
  }
    
  void
  rVex96PBIWPattern::exchangeOperations(int index1, int index2) // O(1)
  {
      IOperation* operation;
      
      // Exchange the indexes
      operation = operations.at(index1);
      operations.at(index1) = operations.at(index2);
      operations.at(index2) = operation;    
  }
  
  unsigned int
  rVex96PBIWPattern::getValueByIndex(const IPBIWInstruction*& instruction, int index) const // O(1)
  {
    IPBIWInstruction::OperandVector operands = instruction->getOperands();

    if (index != -1)
      return operands[index].getValue(); // O(1)
      
    return index;
  }
    
  bool
  rVex96PBIWPattern::operator<(const IPBIWPattern& other) const // O(1)
  {
    return operations.size() < other.getOperationCount();
  }

  bool
  rVex96PBIWPattern::operator>(const IPBIWPattern& other) const // O(1)
  {
    return operations.size() > other.getOperationCount();
  }

  bool
  rVex96PBIWPattern::operator<=(const IPBIWPattern& other) const // O(1)
  {
    return (*this < other) || (*this == other);
  }

  bool
  rVex96PBIWPattern::operator>=(const IPBIWPattern& other) const // O(1)
  {
    return (*this > other) || (*this == other);
  }

  bool
  rVex96PBIWPattern::operator==(const IPBIWPattern& other) const // O(1)
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
  rVex96PBIWPattern::operator!=(const IPBIWPattern& other) const // O(1)
  {
    return !(*this == other);
  }

}