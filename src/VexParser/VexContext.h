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
#include "../rVex/Instruction.h"
#include "../rVex/Label.h"
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
  private:
    
    /**
     * Status variables.
     */
    bool debugEnabled; // Be verbose or not, that's the question!
    rVex::Printers::IPrinter& printer; // Printer used to output data
    
    /**
     * Vector of the labels in assembly
     */
    typedef std::vector<rVex::Label> LabelVector;
    LabelVector labels;
    
    bool hasLabel; // Used to know when a label is defined
    
    /**
     * Functor used to find a label.
     */
    class FindLabel : public std::unary_function<rVex::Label, bool>
    {
    public:
        FindLabel(const std::string label) : label(label) {}

        bool operator()(const rVex::Label& t) const 
        { return (t.name == label); }
        
    private:
        const std::string label;
    };
    
    /**
     * Buffer to hold the syllables processed until an end of instruction
     * is issued.
     */
    typedef std::vector<rVex::SyllableCTRL*> ControlSyllablesVector;
    ControlSyllablesVector controlSyllables;
    
    /**
     * Buffer to hold the syllables processed until an end of instruction
     * is issued.
     */
    typedef std::vector<rVex::Syllable*> SyllableBuffer;
    SyllableBuffer syllableBuffer;
    
    /**
     * Syllable and Instruction counter.
     * Used to address the syllables and instructions being saved in the
     * respective lists.
     */
    unsigned int syllableCounter;
    unsigned int instructionCounter;
    
    /**
     * The two main lists which holds the instructions and its respective
     * syllables parsed.
     */
    typedef std::list<rVex::Syllable*> SyllableList;
    SyllableList syllables;
    SyllableList::iterator startSyllable;
    
    typedef std::list<rVex::Instruction*> InstructionList;
    InstructionList instructions;
    
  public:
    /**
     * All the memory allocated by the syllables are freed.
     */
    VexContext(rVex::Printers::IPrinter& printer) : 
      debugEnabled(false), 
      syllableCounter(0), 
      instructionCounter(0),
      hasLabel(false),
      printer(printer)
    { }
    
    virtual ~VexContext( );
    
    /**
     * Used to select, make a pre-process an pack the parsed syllable
     * in the syllable buffer.
     */
    void packSyllable(rVex::Syllable*, SyllableArguments*);
    void packSyllable(rVex::SyllableALU*, SyllableArguments*);
    void packSyllable(rVex::SyllableMEM*, SyllableArguments*);
    void packSyllable(rVex::SyllableMUL*, SyllableArguments*);
    void packSyllable(rVex::SyllableCTRL*, SyllableArguments*);
    void packSyllable(rVex::SyllableMISC*, SyllableArguments*);
    
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
    void setLabel(std::string, rVex::Label::LabelScope);
    
    /**
     * Process the label vector translating the labels to respective instruction
     * addresses.
     */
    void processLabels();
    
    /**
     * Reorder the syllables in the buffer to store them in correct order.
     */
    void reorder(SyllableBuffer&);
    
    /**
     * Prints the data to the specified output.
     */
    void print();
    
    /**
     * Used to check and switch the debug mode (i.e. verbose output)
     */
    void enableDebugging(bool enableSwitch);
    bool isDebuggingEnabled() const
    { return this->debugEnabled; }
    
  };
}
#endif	/* ASMCONTEXT_H */

