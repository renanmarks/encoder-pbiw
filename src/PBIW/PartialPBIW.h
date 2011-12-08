/* 
 * File:   PBIW.h
 * Author: helix
 *
 * Created on July 20, 2011, 4:13 PM
 */

#ifndef PARTIALPBIW_H
#define	PARTIALPBIW_H

#include <set>
#include <vector>
#include <list>

#include "Interfaces/IPBIW.h"
#include "Label.h"

namespace PBIW
{
  using namespace Interfaces;

  /**
   * Class responsible for encoding the r-Vex instructions in
   * "Partial" PBIW scheme.
   *
   * The "Partial" PBIW scheme is different from the "Full" PBIW scheme in the
   * following details: it is not implemented the optimization that reuses an
   * operand present in the write/immediate section to the read/write of the
   * same instruction. This is done by moving this operand in the write/immediate
   * section to the read section and updating the pointers.
   * 
   * The flexibility of this class is in the fact that it operates only
   * using the interfaces to the data structures used.
   */
  class PartialPBIW : public IPBIW
  {
  private:
    
    /**
     * Type definitions to references rVex structures
     */
    typedef rVex::Syllable::OperandVector VexSyllableOperandVector; 
    typedef rVex::Instruction::SyllableVector VexSyllableVector;
//    
//    typedef std::vector<rVex::Instruction*> VexInstructionVector;
//    const VexInstructionVector& originalInstructions;
    
    /**
     * Internal data structures
     */
    typedef std::list<Label> LabelVector;
    LabelVector labels;
    
    typedef std::list<IPBIWInstruction*> PBIWInstructionList;
    PBIWInstructionList codedInstructions;
    
    typedef std::set<IPBIWPattern*> PBIWPatternSet;
//    PBIWPatternSet codedPatterns;
    
    typedef std::list<IPBIWPattern*> PBIWPatternList;
    PBIWPatternList codedPatterns;
    
    const IPBIWPattern& hasPattern(const IPBIWPattern&) const;
    
    void createNewPBIWElements(IPBIWInstruction*& finalInstruction, IPBIWPattern*& newPattern);
    void printValues(const IOperand& operandIt, const IOperand& foundOperand);

    /**
     * Functor used to find a label.
     */
    class FindLabel : public std::unary_function<Label, bool>
    {
    public:
        FindLabel(const std::string label) : label(label) {}

        bool operator()(const Label& t) const 
        { return (t.name == label); }
        
    private:
        const std::string label;
    };
    
  public:
    virtual ~PartialPBIW() { }

    virtual void encode(const std::vector<rVex::Instruction*>&);
    virtual void decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&);
    
    virtual void print(IPBIWPrinter& printer);

    virtual std::vector<IPBIWPattern*> getPatterns();
    virtual std::vector<IPBIWInstruction*> getInstructions();
  };
}


#endif	/* PARTIALPBIW_H */

