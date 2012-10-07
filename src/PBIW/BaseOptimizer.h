/* 
 * File:   BaseOptimizer.h
 * Author: helix
 *
 * Created on December 22, 2011, 3:37 PM
 */

#ifndef BASEOPTIMIZER_H
#define	BASEOPTIMIZER_H

#include <list>
#include <set>
#include <deque>
#include "src/PBIW/Interfaces/IPBIWOptimizer.h"
#include "src/PBIW/Interfaces/ILabel.h"
#include "src/PBIW/Interfaces/IPBIWPrinter.h"
#include "src/PBIW/Interfaces/IPBIWFactory.h"
#include "src/PBIW/Interfaces/IPBIW.h"

namespace PBIW
{
  using PBIW::Interfaces::ILabel;
  using PBIW::Interfaces::IPBIWInstruction;
  using PBIW::Interfaces::IPBIWPattern;
  using PBIW::Interfaces::IPBIWPrinter;
  using PBIW::Interfaces::IPBIWOptimizer;
  using PBIW::Interfaces::IPBIWFactory;
  using PBIW::Interfaces::IPBIW;
  
  class BaseOptimizer : public IPBIWOptimizer
  {
  public:
    BaseOptimizer();
    BaseOptimizer(const BaseOptimizer& orig);
    virtual ~BaseOptimizer();
    
    virtual void useContext(const IPBIW& context);
    
    virtual void useLabels(const std::deque<ILabel*>&);
    virtual void useInstructions(const std::deque<IPBIWInstruction*>&);
    virtual void usePatterns(const std::deque<IPBIWPattern*>&);

    virtual void printStatistics(IPBIWPrinter&);
    virtual void printInstructions(IPBIWPrinter&);
    virtual void printPatterns(IPBIWPrinter&);
    
    virtual unsigned int getOriginalInstructionCount() const
    { return contextPBIW->getOriginalInstructionCount(); }
    
    virtual std::deque<IPBIWPattern*> getPatterns() const 
    { return patterns; }
    
    virtual std::deque<IPBIWInstruction*> getInstructions() const
    { return instructions; }
    
    virtual std::deque<ILabel*> getLabels() const
    { return labels; }

    virtual void setupOptimizer();
    
    /**
     * Functor used to find a instruction.
     */
    class FindInstruction : public std::unary_function<IPBIWInstruction, bool>
    {
    public:
        FindInstruction(const IPBIWInstruction* instruction) : instruction(instruction) {}

        bool operator()(IPBIWInstruction* const& t) const 
        { return (t == instruction); }
        
    private:
        const IPBIWInstruction* instruction;
    };
    
    /**
     * Functor used to find a label.
     */
    class FindLabel : public std::unary_function<ILabel, bool>
    {
    public:
        FindLabel(const std::string label) : label(label) {}

        bool operator()(const ILabel* t) const 
        { return (t->getName() == label); }
        
    private:
        const std::string label;
    };
    
    /**
     * Functor used to find a pattern.
     */
    class FindPattern : public std::unary_function<IPBIWPattern, bool>
    {
    public:
        FindPattern(const IPBIWPattern* pattern) : _pattern(pattern) {}

        bool operator()(IPBIWPattern* const& t) const 
        { return (t->getAddress() == _pattern->getAddress()); }
        
    private:
        const IPBIWPattern* _pattern;
    };
    
    /**
     * Must be implemented by specific optimizers.
     */
    virtual void run(IPBIWFactory& factory) = 0;
  
  protected:
    typedef std::deque<IPBIWInstruction*> PBIWInstructionList;
    typedef std::deque<IPBIWPattern*> PBIWPatternList;
    typedef std::set<IPBIWPattern*> PBIWPatternSet;
    typedef std::deque<ILabel*> LabelList;

    const IPBIW* contextPBIW;
    PBIWInstructionList instructions;
    PBIWInstructionList branchingInstructions;
    PBIWPatternList patterns;
    LabelList labels;
  };
}

#endif	/* BASEOPTIMIZER_H */
