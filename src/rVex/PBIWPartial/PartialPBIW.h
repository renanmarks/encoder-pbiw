/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   PBIW.h
 * Author: helix
 *
 * Created on July 20, 2011, 4:13 PM
 */

#ifndef PBIWPARTIAL_PARTIALPBIW_H
#define	PBIWPARTIAL_PARTIALPBIW_H

#include <set>
#include <vector>
#include <list>

#include "PBIW/Interfaces/IPBIW.h"
#include "Label.h"
#include "PBIW/Utils/OperandVectorDTO.h"
#include "GenericAssembly/Utils/OperandVector.h"
#include "rVex/Base/Syllable.h"
#include "Factory.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;

  class rVex64PBIWInstruction;
  class rVex96PBIWPattern;
  
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
    
    PBIWPartial::Factory factory;
    
    bool debug;
    
    /**
     * Type definitions to references rVex structures
     */
    typedef PBIW::Utils::OperandVectorDTO VexSyllableOperandVector; 
    typedef rVex::Base::Instruction::SyllableCollection VexSyllableVector;
//    
//    typedef std::vector<rVex::Base::Instruction*> VexInstructionVector;
//    const VexInstructionVector& originalInstructions;
    
    /**
     * Internal data structures
     */
    typedef std::list<PBIWPartial::Label> LabelVector;
    LabelVector labels;
    
    unsigned int originalInstructionsCount;
    
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
    
    const rVex96PBIWPattern& hasPattern(const rVex96PBIWPattern&) const;
    
    void savePBIWElements(rVex64PBIWInstruction*&, rVex96PBIWPattern*&);
    void saveAndCreateNewPBIWElements(rVex64PBIWInstruction*&, rVex96PBIWPattern*&);
    void createNewPBIWElements(rVex64PBIWInstruction*&, rVex96PBIWPattern*& );
    void resetFinalOperation(GenericAssembly::Utils::OperandVector::const_iterator&, IOperation*&, rVex::Base::Syllable* const&, const GenericAssembly::Utils::OperandVector&);

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
    PartialPBIW() : debug(false)
    {}
    
    virtual ~PartialPBIW();

    virtual void encode(const std::deque<GenericAssembly::Interfaces::IInstruction*>&);
    virtual void encode(const std::deque<rVex::Base::Instruction*>&);
    virtual void decode(const std::deque<IPBIWInstruction*>&, const std::deque<IPBIWPattern*>&);
    
    virtual void registerOptimizer(IPBIWOptimizer&);
    virtual void runOptimizers();
    
    virtual void printInstructions(IPBIWPrinter&);
    virtual void printPatterns(IPBIWPrinter&);
    virtual void printStatistics(IPBIWPrinter& printer);

    virtual std::deque<IPBIWPattern*> getPatterns() const;
    virtual std::deque<IPBIWInstruction*> getInstructions() const;
    virtual std::deque<ILabel*> getLabels() const;

    virtual unsigned int getOriginalInstructionCount() const
    { return originalInstructionsCount; };
    
    void
    setDebug(bool debug)
    { this->debug=debug; }

    bool
    isDebug() const
    { return debug; }
  };
}


#endif	/* PARTIALPBIW_H */

