/* 
 * File:   ILabel.h
 * Author: helix
 *
 * Created on May 27, 2012, 4:00 PM
 */

#ifndef GENERICASSEMBLY_ILABEL_H
#define	GENERICASSEMBLY_ILABEL_H

#include "IOperation.h"
#include "IOperand.h"
#include "src/GenericAssembly/Utils/LabelScope.h"

namespace GenericAssembly
{
  namespace Interfaces
  {
    /**
     * A label in the assembly 
     */
    class ILabel : public IOperand
    {
    public:
      virtual ~ILabel() { }

      virtual void setAbsoluteAddress(unsigned int) = 0;
      virtual unsigned int getAbsoluteAddress() const = 0;
      
      virtual void setDestiny(IOperation* destiny) = 0;
      virtual IOperation* getDestiny() const = 0;
      
      virtual void setScope(Utils::LabelScope::Type scope) = 0;
      virtual Utils::LabelScope::Type getScope() const = 0;
      
      virtual void setName(const std::string& name) = 0;
      virtual std::string getName() const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_ILABEL_H */

