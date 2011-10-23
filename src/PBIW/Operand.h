/* 
 * File:   Operand.h
 * Author: helix
 *
 * Created on October 20, 2011, 2:00 PM
 */

#ifndef OPERAND_H
#define	OPERAND_H

#include "Interfaces/IOperand.h"

namespace PBIW
{
  using namespace Interfaces;
  
  /**
   * The operand used in the PBIW encoding.
   */
  class Operand : public IOperand
  {
  public:
    
    explicit Operand(unsigned char, bool);
    virtual ~Operand() { }
  
    virtual void setIndex(unsigned int index) 
    { this->index = index; }
    virtual unsigned int getIndex() const
    { return this->index; }

    virtual bool operator==(const IOperand&) const;
    virtual bool operator!=(const IOperand&) const;
    
  private:
    // Used to know in what position we are in the PBIW instruction
    unsigned char index;
    
    // This is an immediate operand?
    bool isImmediate;
    
    // The value of this operand (register number or immediate number)
    short value;
  };
}



#endif	/* OPERAND_H */

