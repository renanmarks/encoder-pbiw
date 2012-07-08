/* 
 * File:   IPBIWPattern.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:23 PM
 */

#ifndef IPBIWPATTERN_H
#define	IPBIWPATTERN_H

#include <vector>

namespace PBIW
{
  namespace Interfaces
  {
    class IOperation;
    class IPBIWPrinter;
    
    /**
     * PBIW Pattern interface
     */
    class IPBIWPattern
    {
      public:
        typedef std::vector<IOperation*> OperationVector;
        
        virtual ~IPBIWPattern() {}
        
        /**
         * Deep copy this instruction.
         */
        virtual IPBIWPattern* clone() const = 0;
        
        /**
         * Set pattern's absolute memory address.
         */
        virtual void setAddress(unsigned int) = 0;
        
        /**
         * Get pattern's absolute memory address.
         */
        virtual unsigned int getAddress() const = 0;
        
        /**
         * Add a single pattern to this sets of patterns.
         * @param Pattern to be added
         */
        virtual void addOperation(IOperation*) = 0;
        
        /**
         * Returns a pattern of this set of patterns.
         * @param Index of pattern to be returned
         * @return The operation
         */
        virtual IOperation* getOperation(unsigned int) const = 0;
        virtual IOperation* operator[](const unsigned int) const = 0;
        
        /**
         * Checks if this pattern contains a Control Operation (branch, etc)
         */
        virtual bool hasControlOperation() const = 0;
        
        /**
         * Returns how many operations this pattern contains.
         * @return Quantity of operations
         */
        virtual unsigned int getOperationCount() const = 0;
        
        /**
         * Updates the old indexes in the operations to the new one informed.
         */
        virtual void updateIndexes(int oldIndex, int newIndex) = 0;
        
        virtual void incrementUsageCounter() = 0;
        virtual int getUsageCounter() const = 0;
        virtual void resetUsageCounter() = 0;
        
        virtual void reorganize() = 0;
        
        /**
         * Print this pattern using the specified printer.
         * @param An IPBIWPrinter
         */
        virtual void print(IPBIWPrinter&) const = 0;
        
        virtual bool operator<(const IPBIWPattern&) const = 0;
        virtual bool operator>(const IPBIWPattern&) const = 0;
        virtual bool operator<=(const IPBIWPattern&) const = 0;
        virtual bool operator>=(const IPBIWPattern&) const = 0;

        virtual bool operator==(const IPBIWPattern&) const = 0;
        virtual bool operator!=(const IPBIWPattern&) const = 0;
        
    };
  }
}

#endif	/* IPBIWPATTERN_H */

