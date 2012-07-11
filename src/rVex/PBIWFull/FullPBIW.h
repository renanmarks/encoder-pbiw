/* 
 * File:   FullPBIW.h
 * Author: helix
 *
 * Created on July 20, 2011, 4:13 PM
 */

#ifndef PBIWFULL_FULLPBIW_H
#define	PBIWFULL_FULLPBIW_H

#include <set>
#include <vector>
#include <list>

#include "src/PBIW/Interfaces/IPBIW.h"
#include "Label.h"
#include "src/PBIW/Utils/OperandVectorDTO.h"
#include "src/rVex/Syllable.h"
#include "rVex64PBIWInstruction.h"
#include "rVex96PBIWPattern.h"
#include "Factory.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

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
  class FullPBIW : public IPBIW
  {
  private:
    
    PBIWFull::Factory factory;
    
    bool debug;
    
    unsigned int originalInstructionsCount;
    
    /**
     * Type definitions to references rVex structures
     */
    typedef rVex::Utils::OperandVectorDTO VexSyllableOperandVector; 
    typedef rVex::Instruction::SyllableVector VexSyllableVector;
//    
//    typedef std::vector<rVex::Instruction*> VexInstructionVector;
//    const VexInstructionVector& originalInstructions;
    
    /**
     * Internal data structures
     */
    typedef std::list<PBIWFull::Label> LabelVector;
    LabelVector labels;
    
    /**
     * Buffer used to know the syllables coded at each iteration
     */
    typedef std::list<GenericAssembly::Interfaces::IOperation*> SyllableReferenceList;
    SyllableReferenceList syllablesBuffer;
    
    typedef std::list<IPBIWInstruction*> PBIWInstructionList;
    PBIWInstructionList codedInstructions;
    PBIWInstructionList branchingInstructions;
    
    typedef std::set<IPBIWPattern*> PBIWPatternSet;
//    PBIWPatternSet codedPatterns;
    
    typedef std::list<IPBIWPattern*> PBIWPatternList;
    PBIWPatternList codedPatterns;
    
    typedef std::list<IPBIWOptimizer*> PBIWOptimizerList;
    PBIWOptimizerList optimizers;
    
    const IPBIWPattern& hasPattern(const IPBIWPattern&) const;
    
    void savePBIWElements(rVex64PBIWInstruction*&, rVex96PBIWPattern*&);
    void createNewPBIWElements(rVex64PBIWInstruction*&, rVex96PBIWPattern*&);
    void saveAndCreateNewPBIWElements(rVex64PBIWInstruction*&, rVex96PBIWPattern*&);
    void resetFinalOperation(VexSyllableOperandVector::Collection::const_iterator&, Operation*&, rVex::Syllable* const&, const VexSyllableOperandVector&);

    /**
     * Process the label vector translating the labels to respective instruction
     * addresses.
     */
    void processLabels();
    
    /**
     * Functor used to find a label.
     */
    class FindLabel : public std::unary_function<ILabel, bool>
    {
    public:
        FindLabel(const std::string label) : label(label) {}

        bool operator()(const ILabel& t) const 
        { return (t.getName() == label); }
        
    private:
        const std::string label;
    };
    
  public:
    FullPBIW() : debug(false), originalInstructionsCount(0)
    {}
    
    virtual ~FullPBIW();

    virtual void encode(const std::vector<rVex::Instruction*>&);
    virtual void decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&);
    
    virtual void registerOptimizer(IPBIWOptimizer&);
    virtual void runOptimizers();
    
    virtual void printStatistics(IPBIWPrinter&);
    virtual void printInstructions(IPBIWPrinter&);
    virtual void printPatterns(IPBIWPrinter&);

    virtual std::vector<IPBIWPattern*> getPatterns();
    virtual std::vector<IPBIWInstruction*> getInstructions();
    virtual std::vector<ILabel*> getLabels();
    
    void
    setDebug(bool debug)
    { this->debug=debug; }

    bool
    isDebug() const
    { return debug; }
  };
}


#endif	/* PARTIALPBIW_H */

