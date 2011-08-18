/* 
 * File:   rVexInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:19 PM
 */

#ifndef RVEXINSTRUCTION_H
#define	RVEXINSTRUCTION_H

#include "IVLIWInstruction.h"
#include "rVexSyllable.h"

namespace rVex
{
  class rVexInstruction
  {
    public:
      rVexInstruction();
      rVexInstruction(const rVexInstruction& orig);
      virtual ~rVexInstruction();

      virtual bool addOperation(const rVexSyllable&);
      virtual bool removeOperation(const rVexSyllable&);

      virtual std::vector<rVexSyllable> getSyllables() const;
    
    private:
      std::vector<rVexSyllable> syllables;
      
  };
}

#endif	/* RVEXINSTRUCTION_H */

