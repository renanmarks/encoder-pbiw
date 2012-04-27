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
#include "Interfaces/IPBIWOptimizer.h"
#include "Interfaces/ILabel.h"

namespace PBIW
{
  using PBIW::Interfaces::ILabel;
  using PBIW::Interfaces::IPBIWInstruction;
  using PBIW::Interfaces::IPBIWPattern;
  
  class BaseOptimizer : public IPBIWOptimizer
  {
  public:
    BaseOptimizer();
    BaseOptimizer(const BaseOptimizer& orig);
    virtual ~BaseOptimizer();
    
    virtual void useLabels(const std::vector<Label>&);
    virtual void useInstructions(const std::vector<IPBIWInstruction*>&);
    virtual void usePatterns(const std::vector<IPBIWPattern*>&);

    virtual void print(IPBIWPrinter& printer);

    virtual std::vector<IPBIWPattern*> getPatterns()
    { return std::vector<IPBIWPattern*>(patterns.begin(), patterns.end()); }
    
    virtual std::vector<IPBIWInstruction*> getInstructions()
    { return std::vector<IPBIWInstruction*>(instructions.begin(), instructions.end()); }

    virtual void setupOptimizer();
    
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
    
    /**
     * Functor used to find a pattern.
     */
    class FindPattern : public std::unary_function<IPBIWPattern*, bool>
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
    virtual void run() = 0;
  
  protected:
    typedef std::deque<IPBIWInstruction*> PBIWInstructionList;
    typedef std::deque<IPBIWPattern*> PBIWPatternList;
    typedef std::set<IPBIWPattern*> PBIWPatternSet;
    typedef std::list<Label> LabelList;
    
    PBIWInstructionList instructions;
    PBIWInstructionList branchingInstructions;
    PBIWPatternList patterns;
    LabelList labels;
  };
}

#endif	/* BASEOPTIMIZER_H */
