/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef PBIWPARTIAL_PBIWLABEL_H
#define	PBIWPARTIAL_PBIWLABEL_H

#include <string>
#include "src/PBIW/Interfaces/ILabel.h"
#include "src/rVex/Label.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;
  
  /**
   * Structure used to save the label definition information.
   */
  class Label : public ILabel
  {
  public:
    Label()
      : name(""), scope(GenericAssembly::Utils::LabelScope::GLOBAL), destiny(NULL), absoluteAddress(0)
    { }
    
    Label(const Label& other)
      : name(other.name), scope(other.getScope()), destiny(other.getDestiny()), absoluteAddress(other.getAbsoluteAddress())
    { }
    
    Label(const rVex::Label& rVexLabel)
      : name(rVexLabel.getName()), scope(rVexLabel.getScope()), destiny(NULL), absoluteAddress(0)
    { }
    
    ~Label() 
    { }

    virtual ILabel* clone() const
    { return new Label(*this); }
    
    void
    setAbsoluteAddress(unsigned int absoluteAddress)
    { this->absoluteAddress=absoluteAddress; }

    unsigned int
    getAbsoluteAddress() const
    { return absoluteAddress; }

    void
    setDestiny(IPBIWInstruction* destiny)
    { this->destiny=destiny; }

    IPBIWInstruction*
    getDestiny() const
    { return destiny; }

    void
    setScope(GenericAssembly::Utils::LabelScope::Type scope)
    { this->scope=scope; }

    GenericAssembly::Utils::LabelScope::Type
    getScope() const
    { return scope; }

    void
    setName(const std::string& name)
    { this->name=name; }

    std::string
    getName() const
    { return name; }
    
  private:
    std::string name;
    GenericAssembly::Utils::LabelScope::Type scope;
    IPBIWInstruction* destiny;
    unsigned int absoluteAddress;
  };
}

#endif	/* PBIWLABEL_H */

