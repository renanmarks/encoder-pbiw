/* 
 * File:   rVexSyllabe.h
 * Author: helix
 *
 * Created on July 23, 2011, 5:08 PM
 */

#ifndef RVEXSYLLABE_H
#define	RVEXSYLLABE_H

#include "IVLIWOperation.h"

namespace rVex
{
  using namespace Base;

  /**
   * A r-Vex instruction syllabe (operation)
   */
  class rVexSyllable : public IVLIWOperation
  {
    public:
      rVexSyllable();
      rVexSyllable(const rVexSyllable& orig);
      virtual ~rVexSyllable();

      virtual void setOpcode(int);
      virtual int getOpcode();

      virtual void setReadRegisters(const std::vector<int>&);
      virtual std::vector<int> getReadRegisters();

      virtual void setWriteRegisters(const std::vector<int>&);
      virtual std::vector<int> getWriteRegisters();

    private:
      int opcode;
      std::vector<int> readRegisters;
      std::vector<int> writeRegisters;
  };
}

#endif	/* RVEXSYLLABE_H */

