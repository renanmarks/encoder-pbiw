/* 
 * File:   PBIW.h
 * Author: helix
 *
 * Created on July 20, 2011, 4:13 PM
 */

#ifndef PBIW_H
#define	PBIW_H

#include "Interfaces/IPBIW.h"

namespace PBIW
{
  using namespace Interfaces;

  /**
   * Class responsible for encoding the r-Vex instructions in
   * PBIW scheme.
   * 
   * The flexibility of this class is in the fact that it operates only
   * using the interfaces to the data structures used.
   */
  class PBIW : public IPBIW
  {
  private:
    typedef rVex::Syllable::OperandVector VexSyllableOperandVector; 
    typedef rVex::Instruction::SyllableVector VexSyllableVector;
    typedef std::vector<rVex::Instruction*> VexInstructionVector;
    VexInstructionVector originalInstructions;

    typedef std::vector<IPBIWInstruction*> PBIWInstructionVector;
    PBIWInstructionVector codedInstructions;
    
    typedef std::vector<IPBIWPattern*> PBIWPatternVector;
    PBIWPatternVector codedPatterns;

  public:

    explicit
    PBIW(const std::vector<rVex::Instruction*>& original)
    : originalInstructions(original)
    { }
    
    virtual ~PBIW();

    virtual void encode();
    virtual void decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&);

    virtual std::vector<IPBIWPattern*> getPatterns();
    virtual std::vector<IPBIWInstruction*> getInstructions();
  };
}


#endif	/* PBIW_H */

