#ifndef PBIWSPARCENCODER_H
#define PBIWSPARCENCODER_H

#include <string>
#include "GenericEncoder/GenericEncoderInterface.h"
#include "Sparc/pbiw/elfio/elfio.hpp"

namespace Sparc
{
    namespace PBIW
    {
        class Encoder : public PBIWFramework::GenericEncoderInterface
        {
        public:
            explicit Encoder(const std::list<std::string>&inputFlags);
            virtual ~Encoder();

            virtual void run();
            virtual std::list<std::string> getSupportedCPUList() const;
            virtual std::string getUsage() const;
            virtual std::string getTargetFlag() const;

        private:
            Encoder(const Encoder&);
            Encoder& operator=(const Encoder&);

            std::list<std::string> flagList;

            std::string elfFile;
            std::string layoutFile;
            bool flag_o;
            bool flag_e;
            bool flag_d;
            bool flag_p;

            ELFIO::elfio elf;
        };
    }
}

#endif // PBIWSPARCENCODER_H
