/* 
 * File:   AsmContext.h
 * Author: helix
 *
 * Created on September 3, 2011, 8:57 PM
 */

#ifndef ASMCONTEXT_H
#define	ASMCONTEXT_H

#include <string>
#include <vector>
#include <list>
#include "../rVex/Instruction.h"
#include "../rVex/SyllableMUL.h"
#include "../rVex/SyllableMISC.h"
#include "../rVex/SyllableMEM.h"
#include "../rVex/SyllableCTRL.h"
#include "../rVex/SyllableALU.h"

namespace VexParser
{
  /* Forwarding declaration. */
  class SyllableArguments;
  
  /**
   * VexContext parser class
   */
  class VexContext
  {
  public:
    /**
     * All the memory allocated by the syllables are freed.
     */
    virtual ~VexContext( );
    
    void newInstruction();
    void packSyllable(rVex::Syllable*, SyllableArguments*);
    
    void packSyllable(rVex::SyllableALU*, SyllableArguments*);
    void packSyllable(rVex::SyllableMEM*, SyllableArguments*);
    void packSyllable(rVex::SyllableMUL*, SyllableArguments*);
    void packSyllable(rVex::SyllableCTRL*, SyllableArguments*);
    void packSyllable(rVex::SyllableMISC*, SyllableArguments*);
    
    void endInstruction();
    rVex::Instruction getInstruction(unsigned int);
    
    void print(std::ostream&);
    
  private:
    typedef std::vector<rVex::Syllable*> SyllableBuffer;
    SyllableBuffer syllableBuffer;
    
    typedef std::list<rVex::Syllable*> SyllableList;
    SyllableList syllables;
    SyllableList::iterator startSyllable;
    
    typedef std::list<rVex::Instruction> InstructionList;
    InstructionList instructions;
  };

}
#endif	/* ASMCONTEXT_H */

