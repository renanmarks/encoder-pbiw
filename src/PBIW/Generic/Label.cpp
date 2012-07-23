/* 
 * File:   Label.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 5:22 PM
 */

#include "Label.h"

namespace PBIW
{
  namespace Generic
  {

    Label::Label()
    {
    }

    Label::Label(const Label& orig)
    {
    }

    Label::~Label()
    {
    }

    ILabel*
    Label::clone() const
    {
    }

    void
    Label::setAbsoluteAddress(unsigned int absoluteAddress)
    {
    }

    unsigned int
    Label::getAbsoluteAddress() const
    {
    }

    void
    Label::setDestiny(IPBIWInstruction* destiny)
    {
    }

    IPBIWInstruction*
    Label::getDestiny() const
    {
    }

    void
    Label::setScope(GenericAssembly::Utils::LabelScope::Type scope)
    {
    }

    GenericAssembly::Utils::LabelScope::Type
    Label::getScope() const
    {
    }

    void
    Label::setName(const std::string& name)
    {
    }

    std::string
    Label::getName() const
    {
    }

  }
}