/* 
 * File:   PBIWPattern.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef RVEX96PBIWPATTERN_H
#define	RVEX96PBIWPATTERN_H

#include <vector>
#include "Interfaces/IPBIWPattern.h"
#include "UnitaryPattern.h"

namespace PBIW
{
  using namespace Interfaces;

  /**
   * r-VEX 96 bits length pattern
   */
  class rVex96PBIWPattern : public IPBIWPattern
  {
  public:
    rVex96PBIWPattern();
    rVex96PBIWPattern(const rVex96PBIWPattern& orig);
    virtual ~rVex96PBIWPattern();

    virtual void addPattern(IPattern&);
    virtual UnitaryPattern& getPattern(unsigned int);
    
    virtual bool operator<(const IPBIWPattern&) const;
    virtual bool operator>(const IPBIWPattern&) const;
    virtual bool operator<=(const IPBIWPattern&) const;
    virtual bool operator>=(const IPBIWPattern&) const;

    virtual bool operator==(const IPBIWPattern&) const;
    virtual bool operator!=(const IPBIWPattern&) const;

  private:
    typedef std::vector<UnitaryPattern> PatternVector;
    PatternVector patterns; // Max 4
    
  };
}

#endif	/* RVEX96PBIWPATTERN_H */

