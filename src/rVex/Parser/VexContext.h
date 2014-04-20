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
#include <functional>
#include "rVex/Base/Instruction.h"
#include "rVex/Base/Label.h"
#include "rVex/Base/SyllableMUL.h"
#include "rVex/Base/SyllableMISC.h"
#include "rVex/Base/SyllableMEM.h"
#include "rVex/Base/SyllableCTRL.h"
#include "rVex/Base/SyllableALU.h"
#include "PBIW/Interfaces/IPBIW.h"
#include "PBIW/Interfaces/IPBIWPrinter.h"
#include "Structs/SyllableBufferItem.h"
#include "GenericAssembly/Interfaces/IContext.h"

namespace VexParser
{
  /* Forwarding declaration. */
  class SyllableArguments;

  using GenericAssembly::Interfaces::IContext;

  /**
   * VexContext parser class
   */
  class VexContext : public IContext
  {
  public:
    /**
     * Buffer to hold the syllables processed until an end of instruction
     * is issued.
     */
    typedef std::vector<rVex::Base::SyllableCTRL*> ControlSyllablesVector;

    /**
     * Buffer to hold the syllables processed until an end of instruction
     * is issued.
     */
    typedef std::deque<Structs::SyllableBufferItem> SyllableBuffer;

    /**
     * The two main lists which holds the instructions and its respective
     * syllables parsed.
     */
    typedef std::list<rVex::Base::Syllable*> rVexSyllableList;
		typedef std::list<rVex::Base::Instruction*> rVexInstructionList;

    /**
     * Vector of the labels in assembly
     */
		typedef std::list<rVex::Base::Label> rVexLabelVector;

    VexContext() :
    debugEnabled(false),
    hasLabels(false),
    syllableCounter(0),
    instructionCounter(0),
    lastWordAddress(0)
    {
    }
    
    virtual ~VexContext();

    /**
     * Used to select, make a pre-process an pack the parsed syllable
     * in the syllable buffer.
     */
    void packSyllable(rVex::Base::Syllable*, SyllableArguments&);

    /**
     * Clears the syllable buffer to hold new parsed syllables.
     */
    void newInstruction();

    /**
     * Get the syllables in the syllable buffer and put them in the 
     * definitive list. After, clears the syllable buffer to hold 
     * new parsed syllables.
     */
    void endInstruction();
    /**
     * Given a address, returns the instruction.
     */
		rVex::Base::Instruction* getInstruction(unsigned int);

    /**
     * Add the labels to the label vector.
     */
    void setLabel(std::string, GenericAssembly::Utils::LabelScope::Type);

    /**
     * Process the label vector translating the labels to respective instruction
     * addresses.
     */
    void processLabels();

    /**
     * Post process the buffer to substitute pseudo-instructions and to other
     * post-processing stuff.
     */
    void postProcess();

    /**
     * Prints the data to the specified output.
     */
    void print(rVex::Printers::IPrinter& printer);

    /**
     * Encode the Vex Instructions using the referenced PBIW algorithm and
     * print using the referenced PBIW printer.
     * @param The PBIW algorithm used to encode
     * @param The PBIW printer used to print the result
     */
    void encodePBIW(PBIW::Interfaces::IPBIW&) const;

    /**
     * Used to check and switch the debug mode (i.e. verbose output)
     */
    void enableDebugging(bool enableSwitch);

    bool
    isDebuggingEnabled() const
    {
      return this->debugEnabled;
    }

    /* Getters and setters */
    void
    setInstructions(const rVexInstructionList& instructions);

    IContext::InstructionDeque
    getInstructions() const;

    void
    setOperations(const rVexSyllableList& syllables);

    IContext::OperationDeque
    getOperations() const;

    void
    setSyllableBuffer(const SyllableBuffer& syllableBuffer);

    SyllableBuffer&
    getSyllableBuffer();

    void
    setControlSyllables(const ControlSyllablesVector& controlSyllables);

    ControlSyllablesVector&
    getControlSyllables();

    void
    setLabels(const rVexLabelVector& labels);

    IContext::LabelDeque
    getLabels() const;

    void
    endParsing();

  private:

    /**
     * Status variables.
     */
    bool debugEnabled; // Be verbose or not, that's the question!

    rVexLabelVector labels;
    bool hasLabels; // Used to know when a label is defined
    rVexLabelVector labelBuffer; // Used to handle one or more labels at parsing

    ControlSyllablesVector controlSyllables;
    SyllableBuffer syllableBuffer;

    rVexSyllableList syllables;
    rVexSyllableList::iterator startSyllable;

    rVexInstructionList instructions;

    /*
     * Syllable and Instruction counter.
     * Used to address the syllables and instructions being saved in the
     * respective lists.
     */
    unsigned int syllableCounter;
    unsigned int instructionCounter;

    /* 
     * Helps generate the same address scheme used in the Vex cache simulator
     * and correlate rVex and Vex schemes to get the same execution trace.
     */
    unsigned int lastWordAddress;

    /**
     * Functor used to find a label.
     */
		class FindLabel : public std::unary_function<rVex::Base::Label, bool>
    {
    public:

      FindLabel(const std::string label) : label(label)
      {
      }

			bool operator()(const rVex::Base::Label& t) const
      {
        return (t.getName() == label);
      }

    private:
      const std::string label;
    };

  };
}
#endif	/* ASMCONTEXT_H */

