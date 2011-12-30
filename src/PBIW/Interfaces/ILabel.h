/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef PBIWILABEL_H
#define	PBIWILABEL_H

#include <string>

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

      typedef enum
      {
        GLOBAL=0, LOCAL=1
      } LabelScope;

      ~ILabel() { };
      
      virtual void setAbsoluteAddress(unsigned int absoluteAddress) = 0;
      virtual unsigned int getAbsoluteAddress() const = 0;

      virtual void setDestiny(IPBIWInstruction* destiny) = 0;
      virtual IPBIWInstruction* getDestiny() const = 0;

      virtual void setScope(LabelScope scope) = 0;
      virtual LabelScope getScope() const = 0;

      virtual void setName(const std::string& name) = 0;
      virtual std::string getName() const = 0;
    };
  }
}

#endif	/* PBIWILABEL_H */

