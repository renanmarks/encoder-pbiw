/* 
 * File:   Factory.h
 * Author: helix
 *
 * Created on July 22, 2012, 7:06 PM
 */

#ifndef PBIW_GENERIC_FACTORY_H
#define	PBIW_GENERIC_FACTORY_H

#include "src/PBIW/Interfaces/IPBIWFactory.h"
#include "Configuration.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Configuration;
    
    class Factory : public IPBIWFactory
    {
    public:
      Factory(const Configuration& config);
      Factory(const Factory& orig);
      virtual ~Factory();
      
      virtual IPBIWInstruction* createInstruction() const;
      virtual IPBIWPattern* createPattern() const;
      virtual IOperation* createOperation() const;
      virtual IOperand* createOperand() const;
      virtual ILabel* createLabel() const;
      
      IOperation* createOperation(const GenericAssembly::Interfaces::IOperation&) const;
      IOperand* createOperand(const GenericAssembly::Interfaces::IOperand&) const;
      ILabel* createLabel(const GenericAssembly::Interfaces::ILabel&) const;
    private:
      Configuration configuration;
    };
  }
}
#endif	/* FACTORY_H */

