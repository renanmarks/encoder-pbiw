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
  class Syllable;
  
  /**
   * Structure used to save the label definition information.
   */
  struct Label : public GenericAssembly::Interfaces::ILabel
  {
    typedef enum 
    {
      GLOBAL = 0, LOCAL = 1
    } LabelScope;

    Label() 
      : name(""), scope(GLOBAL), destiny(NULL), absoluteAddress(0)
    { }
    
    Label(const Label& other) 
      : name(other.name), scope(other.scope), destiny(other.destiny), absoluteAddress(other.absoluteAddress)
    { }
    
    std::string name;
    LabelScope scope;
    rVex::Syllable* destiny;
    unsigned int absoluteAddress;
  };
}

#endif	/* RVEX_LABEL_H */

