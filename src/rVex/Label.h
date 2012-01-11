/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef LABEL_H
#define	LABEL_H

#include <string>

namespace rVex
{
  class Syllable;
  
  /**
   * Structure used to save the label definition information.
   */
  struct Label
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

#endif	/* LABEL_H */

