/* 
 * File:   IPBIWFactory.h
 * Author: helix
 *
 * Created on July 9, 2012, 5:53 PM
 */

#ifndef IPBIWFACTORY_H
#define	IPBIWFACTORY_H

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IInstruction;
    class IOperation;
    class IOperand;
    class ILabel;
  }
}

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWInstruction;
    class IPBIWPattern;
    class IOperation;
    class IOperand;
    class ILabel;
    
    /**
     * PBIW Factory to build the minimum parts used in the algorithm.
     */
    class IPBIWFactory
    {
    public:
      virtual ~IPBIWFactory() { }
      
      virtual IPBIWInstruction* createInstruction() const = 0;
      virtual IPBIWPattern* createPattern() const = 0;
      virtual IOperation* createOperation() const = 0;
      virtual IOperand* createOperand() const = 0;
      virtual ILabel* createLabel() const = 0;
      
      virtual IOperation* createOperation(const GenericAssembly::Interfaces::IOperation&) const = 0;
      virtual IOperand* createOperand(const GenericAssembly::Interfaces::IOperand&) const = 0;
      virtual ILabel* createLabel(const GenericAssembly::Interfaces::ILabel&) const = 0;
    };
  }
}

#endif	/* IPBIWFACTORY_H */

