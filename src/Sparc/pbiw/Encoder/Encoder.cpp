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
            ifstream help("help.txt");
            std::string helpMessage;

//            help.seekg(0, ios::end);
//            int size = help.tellg();
//            help.seekg(0, ios::beg);

            while (!help.eof())
            {
                // TODO
            }

            return helpMessage;
        }

        std::string Encoder::getTargetFlag() const
        {
            return "sparcv8";
        }
    }
}
