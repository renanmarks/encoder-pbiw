/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on July 23, 2012, 5:22 PM
 */

#ifndef PBIW_GENERIC_LABEL_H
#define	PBIW_GENERIC_LABEL_H

#include "src/PBIW/Interfaces/ILabel.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Label : public ILabel
    {
    public:
      Label();
      Label(const Label& orig);
      virtual ~Label();
      
      virtual ILabel* clone() const;
      
      virtual void setAbsoluteAddress(unsigned int absoluteAddress);
      virtual unsigned int getAbsoluteAddress() const;

      virtual void setDestiny(IPBIWInstruction* destiny);
      virtual IPBIWInstruction* getDestiny() const;

      virtual void setScope(GenericAssembly::Utils::LabelScope::Type scope);
      virtual GenericAssembly::Utils::LabelScope::Type getScope() const;

      virtual void setName(const std::string& name);
      virtual std::string getName() const;
    private:

    };
  }
}

#endif	/* LABEL_H */

