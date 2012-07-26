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
#include "src/rVex/Instruction.h"
#include "src/rVex/Label.h"
#include "src/rVex/SyllableMUL.h"
#include "src/rVex/SyllableMISC.h"
#include "src/rVex/SyllableMEM.h"
#include "src/rVex/SyllableCTRL.h"
#include "src/rVex/SyllableALU.h"
#include "src/PBIW/Interfaces/IPBIW.h"
#include "src/PBIW/Interfaces/IPBIWPrinter.h"
#include "Structs/SyllableBufferItem.h"
#include "src/GenericAssembly/Interfaces/IContext.h"

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
    typedef std::vector<rVex::SyllableCTRL*> ControlSyllablesVector;

    /**
     * Buffer to hold the syllables processed until an end of instruction
     * is issued.
     */
    typedef std::deque<Structs::SyllableBufferItem> SyllableBuffer;

    /**
     * The two main lists which holds the instructions and its respective
     * syllables parsed.
     */
    typedef std::list<rVex::Syllable*> rVexSyllableList;
    typedef std::list<rVex::Instruction*> rVexInstructionList;

    /**
     * Vector of the labels in assembly
     */
    typedef std::list<rVex::Label> rVexLabelVector;

    /**
     * All the memory allocated by the syllables are freed.
     */
    VexContext(rVex::Printers::IPrinter& printer) :
    debugEnabled(false),
    printer(printer),
    hasLabel(false),
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
    void packSyllable(rVex::Syllable*, SyllableArguments&);

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
    rVex::Instruction* getInstruction(unsigned int);

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
    void print();

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
    rVex::Printers::IPrinter& printer; // Printer used to output data

    rVexLabelVector labels;
    bool hasLabel; // Used to know when a label is defined

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
    class FindLabel : public std::unary_function<rVex::Label, bool>
    {
    public:

      FindLabel(const std::string label) : label(label)
      {
      }

      bool operator()(const rVex::Label& t) const
      {
        return (t.getName() == label);
      }

    private:
      const std::string label;
    };

  };
}
#endif	/* ASMCONTEXT_H */

