
#include "Syllable.h"
#include "Label.h"

namespace rVex
{
  Label::Label() 
    : name(""), scope(GenericAssembly::Utils::LabelScope::GLOBAL), destiny(NULL), absoluteAddress(0)
  { }
    
  Label::Label(const Label& other) 
    : name(other.name), scope(other.scope), destiny(other.destiny), absoluteAddress(other.absoluteAddress)
  { }

  void Label::setAbsoluteAddress(unsigned int address)
  { 
    absoluteAddress = address; 
  }

  unsigned int Label::getAbsoluteAddress() const
  { 
    return absoluteAddress; 
  }

  void Label::setDestiny(IOperation* operation)
  { 
    this->destiny = dynamic_cast<rVex::Syllable*>(operation); 
  }

  IOperation* Label::getDestiny() const 
  { 
    return destiny; 
  }

  void Label::setScope(GenericAssembly::Utils::LabelScope::Type labelScope)
  { 
    this->scope = labelScope; 
  }

  GenericAssembly::Utils::LabelScope::Type Label::getScope() const
  { 
    return scope; 
  }

  void Label::setName(const std::string& name)
  { 
    this->name = name; 
  }

  std::string Label::getName() const
  { 
    return name; 
  }
}
