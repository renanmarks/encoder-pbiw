/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef PBIWILABEL_H
#define	PBIWILABEL_H

#include <string>
#include "src/GenericAssembly/Utils/LabelScope.h"

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWInstruction;
    
    /**
     * Structure used to save the label definition information.
     */
    class ILabel
    {
    public:
      virtual ~ILabel() { }
      
      virtual ILabel* clone() const = 0;
      
      virtual void setAbsoluteAddress(unsigned int absoluteAddress) = 0;
      virtual unsigned int getAbsoluteAddress() const = 0;

      virtual void setDestiny(IPBIWInstruction* destiny) = 0;
      virtual IPBIWInstruction* getDestiny() const = 0;

      virtual void setScope(GenericAssembly::Utils::LabelScope::Type scope) = 0;
      virtual GenericAssembly::Utils::LabelScope::Type getScope() const = 0;

      virtual void setName(const std::string& name) = 0;
      virtual std::string getName() const = 0;
    };
  }
}

#endif	/* PBIWILABEL_H */

