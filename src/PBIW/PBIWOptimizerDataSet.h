/* 
 * File:   PBIWOptimizerDataSet.h
 * Author: renato
 *
 * Created on May 11, 2012, 5:20 PM
 */

#ifndef PBIWOPTIMIZERDATASET_H
#define	PBIWOPTIMIZERDATASET_H

#include <deque>
#include <iostream>
#include "PBIWOptimizerJoinPatterns.h"
#include "Interfaces/IPBIWPrinter.h"

namespace PBIW
{
    using namespace Interfaces;
    
    class PBIWOptimizerDataSet {
    public:
        PBIWOptimizerDataSet();
        PBIWOptimizerDataSet(const PBIWOptimizerDataSet& orig);
        virtual ~PBIWOptimizerDataSet();
        
        typedef std::deque<PBIWOptimizerJoinPatterns> Optimizers;
        typedef std::deque<IPBIWPattern*> Patterns;
        typedef std::vector<IPBIWPattern*> VectorPatterns;
        
        virtual void minimumPatterns();
        
        virtual void printPatterns(IPBIWPrinter&) const;
        
        virtual Optimizers getOptimizers() const
        {   return Optimizers(optimizers.begin(), optimizers.end());  }
        
        virtual void setOptimizers(const PBIWOptimizerJoinPatterns& optimizer);
        
    private:
        Optimizers optimizers;
        Patterns uniquePatterns;
    };
}

#endif	/* PBIWOPTIMIZERDATASET_H */

