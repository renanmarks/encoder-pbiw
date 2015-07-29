#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <iosfwd>
#include "Sparc/pbiw/tools/ParseFile.h"
#include "Sparc/pbiw/tools/Encode.h"
#include "Sparc/pbiw/tools/InstructionLayout.h"
#include "Sparc/pbiw/tools/ElfHandling.h"

#include "Sparc/pbiw/elfio/elfio.hpp"
#include "Sparc/pbiw/tools/Decode.h"
#include "Sparc/pbiw/tools/Provider.h"

#include "Encoder.h"

namespace Sparc
{
    namespace PBIW
    {
        Encoder::Encoder(const std::list<std::string>& inputFlags)
            : flagList(inputFlags),
              flag_o(false),
              flag_e(false),
              flag_d(false),
              flag_p(false)
        {
            std::list<std::string>::const_iterator it;
            std::string flags;

            for (it = inputFlags.begin(); it != inputFlags.end(); it++)
            {
                flags += *it;
                flags += " ";

                if ( (*it)[0] == '-')
                {
                    if (*it == "-o") { flag_o = true; continue; }
                    if (*it == "-e") { flag_e = true; continue; }
                    if (*it == "-d") { flag_d = true; continue; }
                    if (*it == "-p") { flag_p = true; continue; }
                }

                if (flag_o && (strcasecmp(it->substr(it->size()-4, 4).c_str(), ".txt") != 0))
                {
                    layoutFile = *it;
                }
                else if(elf.load(*it)) {
                    elfFile = *it;
                }
            }
        }

        Encoder::~Encoder()
        {

        }

        void Encoder::run()
        {
            Sparc::PBIW::Tools::Provider provider(elfFile);

            if((elfFile != "") && (flagList.size() == 2)){ //Default encode
                provider.defaultEncode();
            }
            else if(flag_p && (elfFile != "") && (flagList.size() == 3)){ //Default encode and print
                provider.defaultEncode(flag_p);
            }
            else if(flag_d && (elfFile != "") && (flagList.size() == 3)) { //Decode
                provider.defaultDecode();
            }
            else if(flag_d && flag_p && (elfFile != "") && (flagList.size() == 4)) { //Decode and print
                provider.defaultDecode(flag_p);
            }
            else if(flag_o && (layoutFile != "") && (elfFile != "") && (flagList.size() == 4)) {//Encode with other layout
                provider.otherLayoutEncode(layoutFile);
            }
            else if(flag_o && flag_p && (layoutFile != "") && (elfFile != "") && (flagList.size() == 5)) {//Encode with other layout and print
                provider.otherLayoutEncode(layoutFile, flag_p);
            }
            else if(flag_e && flag_d && (elfFile != "") && (flagList.size() == 4)) {//Default Encode and Decode
                provider.defaultEncode();
                provider.defaultDecode();
            }
            else if(flag_e && flag_p && flag_d && (elfFile != "") && (flagList.size() == 5)) {//Default Encode and Decode and print
                provider.defaultEncode(flag_p);
                provider.defaultDecode(flag_p);
            }
            else if(flag_e && flag_d && flag_o && (layoutFile != "") && (elfFile != "") && (flagList.size() == 6)) {//Encode and Decode with other layout
                provider.otherLayoutEncode(layoutFile);
                provider.defaultDecode();

            }
            else if(flag_e && flag_d && flag_o && flag_p && (layoutFile != "") && (elfFile != "") && (flagList.size() == 7)) {//Encode and Decode with other layout and print
                provider.otherLayoutEncode(layoutFile, flag_p);
                provider.defaultDecode(flag_p);
            }
            else {
                cerr << "Invalid syntax of arguments. To see the help, type -h flag." << endl;
            }

            return;
        }

        std::list<std::string> Encoder::getSupportedCPUList() const
        {
            std::list<std::string> cpus;

            cpus.push_back(getTargetFlag() + " (SPARCv8 Processor)");

            return cpus;
        }

        std::string Encoder::getUsage() const
        {
            std::string helpMessage = "Options/Syntax of commands to Encoder/Decoder PBIW-SPARC\n\
Usage: [options] file...\n\
Options:\n\
  -h 				Display this information\n\
  -o				Flag to use other layout <layoutFile>\n\
  -e				Encode instructions to PBIW formats\n\
  -d				Decode/restore instructions and patterns of PBIW formats to original SPARCv8 format\n\
\n\
Syntax:\n\
  Encode 			./pbiw_sparc elfFile\n\
  Decode 			./pbiw_sparc -d elfFile\n\
  Encode with other layout 	./pbiw_sparc -o layoutFile.txt elfFile\n\
  Encode and Decode		./pbiw_sparc -e -d elfFile\n\
  Encode and decode with	./pbiw_sparc -e -d -o layoutFile.txt elfFile\n\
  other layout\n\
\n\
Layout file description:\n\
\n\
      index_size <size of pattern index>\n\
\n\
      instruction\n\
      fmt0_10 <init_bit, size> <init_bit, size> ...\n\
      fmt0_100 <init_bit, size> <init_bit, size> ...\n\
      fmt1 <init_bit, size> <init_bit, size> ...\n\
      fmt2_0 <init_bit, size> <init_bit, size> ...\n\
      fmt2_1 <init_bit, size> <init_bit, size> ...\n\
\n\
      pattern\n\
      fmt0_10 <init_bit, size> <init_bit, size> ...\n\
      fmt0_100 <init_bit, size> <init_bit, size> ...\n\
      fmt1 <init_bit, size> <init_bit, size> ...\n\
      fmt2_0 <init_bit, size> <init_bit, size> ...\n\
      fmt2_1 <init_bit, size> <init_bit, size> ...\n\
\n\
Glossary:\n\
  elfFile               File ELF 32 bit, SPARCv8\n\
  layoutFile.tx         File with the description of PBIW pattern and instructions\n\
  fmtX                  X: one of three SPARCv8 formats of instructions\n\
  fmt1	                Call instruction\n\
  fmt0_XX               YY = 10 to branch instructions / 100 to NOP/SETHI instructions\n\
  fmt2_XX               YY = 0 instructions with triad registers / 1 instructions with immediate (two registers)\n\
  <init_bit, size>      Set of substrings (of the original instruction) that compose the instruction/patter encoded\n\
                        use least one and maximum n for each fmtX_YY\n\
                        init_bit: start bit of the substring and size: length  in bits of the substring";

            return helpMessage;
        }

        std::string Encoder::getTargetFlag() const
        {
            return "sparcv8";
        }
    }
}
