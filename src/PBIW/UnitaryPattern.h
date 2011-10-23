/* 
 * File:   UnitaryPattern.h
 * Author: helix
 *
 * Created on October 20, 2011, 3:38 PM
 */

#ifndef UNITARYPATTERN_H
#define	UNITARYPATTERN_H

#include <vector>
#include "Interfaces/IOperand.h"

namespace PBIW
{
  using namespace Interfaces;

/*  Class(or struct :P) used to store the individual pattern data.
 
    ,___9b___,__4b___,__4b__,__4b__,__3b__,
    ---------------------------------------
    |        |  0-15 | 0-15 | 0-15 | 0-7  |
    ---------------------------------------
    ' Opcode ' Write ' Read ' Read '  wBr '
 */
  struct UnitaryPattern
  {
    unsigned short opcode; // 9b
    IOperand* writeGr; // 4b
    std::vector<IOperand*> readGr; // 2 x 4b
    IOperand* writeBr; // 3b
  };
}

#endif	/* UNITARYPATTERN_H */

