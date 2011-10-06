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
  /**
   * Structure used to save the label definition information.
   */
  struct Label
  {
    typedef enum 
    {
      GLOBAL = 0, LOCAL = 1
    } LabelScope;

    std::string label;
    LabelScope scope;
  };
}

#endif	/* LABEL_H */

