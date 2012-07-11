/* 
 * File:   Factory.h
 * Author: helix
 *
 * Created on July 9, 2012, 9:43 PM
 */

#ifndef PBIWPARTIAL_FACTORY_H
#define	PBIWPARTIAL_FACTORY_H

#include "src/PBIW/Interfaces/IPBIWFactory.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;
  
  class Factory : public IPBIWFactory
  {
  public:
    virtual ~Factory() { }
    
    IPBIWInstruction* createInstruction() const;
    IPBIWPattern* createPattern() const;
    IOperation* createOperation() const;
    IOperand* createOperand() const;
    ILabel* createLabel() const;
  };
}

#endif	/* FACTORY_H */

