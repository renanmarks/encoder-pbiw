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

namespace PBIW
{
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

    /**
     * Must be implemented by specific optimizers.
     */
    virtual void run() = 0;
  
  private:
    typedef std::list<IPBIWInstruction*> PBIWInstructionList;
    typedef std::list<IPBIWPattern*> PBIWPatternList;
    typedef std::set<IPBIWPattern*> PBIWPatternSet;
    typedef std::list<Label> LabelList;
    
    PBIWInstructionList instructions;
    PBIWPatternList patterns;
    LabelList labels;
  };
}

#endif	/* BASEOPTIMIZER_H */
