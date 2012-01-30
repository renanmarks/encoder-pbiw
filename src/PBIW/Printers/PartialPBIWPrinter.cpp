/* 
 * File:   PartialPBIWPrinter.cpp
 * Author: helix
 * 
 * Created on October 30, 2011, 4:28 PM
 */

#include "PartialPBIWPrinter.h"
#include "src/PBIW/Interfaces/IPBIWPattern.h"
#include "src/PBIW/Interfaces/IPBIWInstruction.h"

namespace PBIW
{
  using namespace Interfaces;

  void
  PartialPBIWPrinter::printPatternsHeader() // O(1)
  {
    printer << "library ieee;\n\
use ieee.std_logic_1164.all;\n\
use ieee.std_logic_unsigned.all;\n\
use ieee.std_logic_arith.all;\n\
\n\
library work;\n\
use work.rVEX_pkg.all;\n\
\n\
entity pcache1 is\n\
\tport (\n\
\t\tAddress: in std_logic_vector(index_pcache-1 downto 0);\n\
\t\tReadPattern: out std_logic_vector(pcache_linesize-1 downto 0)\n\
\t);\n\
end entity pcache1;\n\
\n\
architecture teste of pcache1 is\n\
\ttype PatternLine is array (natural range <>) of std_logic_vector ( pcache_linesize-1 downto 0);\n\
\tconstant PatternCache : PatternLine(0 to index_pcache-1) := (" << std::endl;
  }
  
  void
  PartialPBIWPrinter::printPattern(const IPBIWPattern& pattern, const std::vector<unsigned int>& binary) // O(|operationCount|)
  {
    printer << "\t\t" << pattern.getAddress() << " => b\"";
    
    std::vector<unsigned int>::const_iterator it;
    
    for (it = binary.begin();
         it < binary.end();
         it++)
    {
      // Padding to the left, to read only 24 bits
      unsigned int word = (*it) << 8;
      
      for (int j = 0; j < 24; j++)
      {
        if (word & 0x80000000)
          printer << "1";
        else
          printer << "0";

        word <<= 1;
      }
    }
    
    printer << "\",\n";
  }

  void
  PartialPBIWPrinter::printPatternsFooter() // O(1)
  {
    printer << "\t\tothers=>(others=>'0')\n\
\t);\n\
\n\
begin\n\
\tReadPattern <= PatternCache(conv_integer(Address));\n\
end architecture teste;\n" << std::endl;
  }
  
  void
  PartialPBIWPrinter::printInstructionsHeader() // O(1)
  {
    printer << "library ieee;\n\
use ieee.std_logic_1164.all;\n\
use ieee.std_logic_arith.all;\n\
use ieee.std_logic_unsigned.all;\n\
\n\
library work;\n\
use work.rVEX_pkg.all;\n\
\n\
entity i_mem is\n\
port\n\
(\n\
\tclk\t\t: in std_logic;\n\
\treset\t\t: in std_logic;\n\
\tenable\t\t: in std_logic;\n\
\tread\t\t: in std_logic;\n\
\tselect_program\t: in std_logic;\n\
\taddress\t\t: in std_logic_vector(7 downto 0);\n\
\tinstr\t\t: out std_logic_vector(pbiw-1 downto 0)\n\
);\n\
end i_mem;\n\
\
architecture Behav of i_mem is\n\
\n\
\ttype ROM_Array_0 is array (8 downto 0) of std_logic_vector(pbiw-1 downto 0);\n\
\n\
\tconstant Content_0: ROM_Array_0 := (" << std::endl;
  }

  void
  PartialPBIWPrinter::printInstruction(const IPBIWInstruction& instruction, const std::vector<unsigned int>& binary) // O(1)
  {
    printer << "\t\t" <<instruction.getAddress() << " => b\"";
    
    std::vector<unsigned int>::const_iterator it;
    
    for (it = binary.begin();
         it < binary.end();
         it++)
    {
      unsigned int word = *it;
      
      for (int j = 0; j < 32; j++)
      {
        if ((word & 0x80000000))
          printer << "1";
        else
          printer << "0";

        word <<= 1;
      }
    }

    printer << "\",\n";
  }
  
  void
  PartialPBIWPrinter::printInstructionsFooter() // O(1)
  {
    printer << "\t\tOTHERS => b\"0001110000000000000000000000000000000000000000000000000000000000\" -- NOP|NOP|NOP|STOP\n\
\t);\n\
\n\
begin\n\
\tprocess(clk, reset, read, address)\n\
\tbegin\n\
\t\tif ( reset = '1' ) then\n\
\t\t\tinstr <= \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\";\n\
\t\telsif ( clk'event and clk = '1' ) then\n\
\t\t\tif ( enable = '1' and read = '1' ) then\n\
\t\t\t\tinstr <= Content_0(conv_integer(address));\n\
\t\t\tend if;\n\
\t\telse\n\
\t\t\tinstr <= \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\";\n\
\t\tend if;\n\
\tend process;\n\
end Behav;\n" << std::endl;
  }
  
}
