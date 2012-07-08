// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the VexParser::Driver class. */

#include <fstream>
#include <sstream>

#include "driver.h"
#include "scanner.h"

namespace VexParser {

Driver::Driver(class VexContext& _calc)
    : trace_scanning(false),
      trace_parsing(false),
      context(_calc)
{
}

bool Driver::parse_stream(std::istream& in, const std::string& sname) // O(1)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(trace_scanning); // O(1)
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(trace_parsing); // O(1)
    return (parser.parse() == 0);  // Parser complex
}

bool Driver::parse_file(const std::string &filename) // O(|filename|)
{
    std::ifstream in(filename.c_str()); // O(|filename|)
    if (!in.good()) return false;
    return parse_stream(in, filename); // O(1)
}

bool Driver::parse_string(const std::string &input, const std::string& sname) // O(1)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname); 
}

void Driver::error(const class location& l, 
		   const std::string& m) // O(|filename|)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m) // O(|filename|)
{
    std::cerr << m << std::endl;
}

} // namespace VexParser
