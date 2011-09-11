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
#include "../rVex/rVex.h"

namespace VexParser
{

  class VexContext
  {
  public:
//    VexContext( );
//    VexContext( const VexContext& orig );
    virtual ~VexContext( );
    
    void newInstruction();
    void packSyllable(rVex::Syllable*);
    void endInstruction();
    
    rVex::Instruction getInstruction(unsigned int);
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

