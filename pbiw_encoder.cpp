/* 
 * File:   pbiw_encoder.cpp
 * Author: helix
 *
 * Created on July 20, 2011, 3:15 PM
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

#include "grammar/vextypes.h"
#include "grammar/grammar.h"
#include "pbiw_encoder.h"

int main(int argc, char** argv) 
{
  
    #ifdef YYDEBUG
    yydebug = 1;
    #endif

    if (argc < 2)
    {
      fprintf(stderr,"Usage: %s <vex_file.s>\n", argv[0]);
      return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) 
    {
      fprintf(stderr, "Error: can't open input file %s\n", argv[1]);
      return 1;
    }

    yyout = stdout;

    yyparse();
    
    
    return 0;
}

