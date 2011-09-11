/* 
 * File:   pbiw_encoder.cpp
 * Author: helix
 *
 * Created on July 20, 2011, 3:15 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "VexParser/driver.h"
#include "VexParser/VexContext.h"
#include "pbiw_encoder.h"

int
main( int argc, char** argv )
{
  VexParser::VexContext context;
  VexParser::Driver driver(context);
  bool result = false;
  
  for (int ai=1; ai < argc; ++ai)
  {
    if (argv[ai] == std::string("-p"))
    {
      driver.trace_parsing=true;
    } else if (argv[ai] == std::string("-s"))
    {
      driver.trace_scanning=true;
    } else
    {
      // read a file with expressions

      std::fstream infile(argv[ai]);
      if (!infile.good())
      {
        std::cerr << "Could not open file: " << argv[ai] << std::endl;
        return 0;
      }

      result = driver.parse_stream(infile, argv[ai]);
    }
  }
  
  return result ? 0 : 1;
}
