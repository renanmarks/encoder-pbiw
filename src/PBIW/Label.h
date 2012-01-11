/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef PBIWLABEL_H
#define	PBIWLABEL_H

#include <string>
#include "Interfaces/ILabel.h"
#include "src/rVex/Label.h"

namespace PBIW
{
  using namespace Interfaces;
  
  /**
   * Structure used to save the label definition information.
   */
  class Label : public ILabel
  {
  public:
    Label()
      : name(""), scope(GLOBAL), destiny(NULL), absoluteAddress(0)
    { }
    
    Label(const Label& other)
      : name(other.name), scope(other.getScope()), destiny(other.getDestiny()), absoluteAddress(other.getAbsoluteAddress())
    { }
    
    Label(const rVex::Label& rVexLabel)
      : name(rVexLabel.name), scope(static_cast<LabelScope>(rVexLabel.scope)), destiny(NULL), absoluteAddress(0)
    { }
    
    ~Label() 
    { }

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
    setScope(LabelScope scope)
    { this->scope=scope; }

    LabelScope
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
    LabelScope scope;
    IPBIWInstruction* destiny;
    unsigned int absoluteAddress;
  };
}

#endif	/* PBIWLABEL_H */

