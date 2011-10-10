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
  typedef struct
  {
    typedef enum 
    {
      GLOBAL = 0, LOCAL = 1
    } LabelScope;

    std::string name;
    LabelScope scope;
    rVex::Syllable* destiny;
    unsigned int absoluteAddress;
  } Label;
}

#endif	/* LABEL_H */

