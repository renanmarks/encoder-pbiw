/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef RVEX_LABEL_H
#define	RVEX_LABEL_H

#include <string>
#include "src/GenericAssembly/Interfaces/ILabel.h"

namespace rVex
{
  using namespace GenericAssembly::Interfaces;
  class Syllable;
  
  /**
   * Structure used to save the label definition information.
   */
  class Label : public ILabel
  {
  public:
    Label();
    Label(const Label& other);
    
    virtual void setAbsoluteAddress(unsigned int address);
    virtual unsigned int getAbsoluteAddress() const;

    virtual void setDestiny(IOperation* operation);
    virtual IOperation* getDestiny() const;

    virtual void setScope(GenericAssembly::Utils::LabelScope::Type labelScope);
    virtual GenericAssembly::Utils::LabelScope::Type getScope() const;

    virtual void setName(const std::string& name);
    virtual std::string getName() const;
    
  private:
    std::string name;
    GenericAssembly::Utils::LabelScope::Type scope;
    rVex::Syllable* destiny;
    unsigned int absoluteAddress;
  };
}

#endif	/* RVEX_LABEL_H */

