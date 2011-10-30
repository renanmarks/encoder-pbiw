/* 
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef PBIWLABEL_H
#define	PBIWLABEL_H

#include <string>
#include "Interfaces/IPBIWInstruction.h"

namespace PBIW
{
  using namespace Interfaces;
  
  /**
   * Structure used to save the label definition information.
   */
  struct Label
  {
    typedef enum
    {
      GLOBAL = 0, LOCAL = 1
    } LabelScope;

    std::string name;
    LabelScope scope;
    IPBIWInstruction* destiny;
    unsigned int absoluteAddress;
  };
}

#endif	/* PBIWLABEL_H */

