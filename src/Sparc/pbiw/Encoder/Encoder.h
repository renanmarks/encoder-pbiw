#ifndef PBIWSPARCENCODER_H
#define PBIWSPARCENCODER_H

#include <string>
#include "GenericEncoder/GenericEncoderInterface.h"

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
        };
    }
}

#endif // PBIWSPARCENCODER_H
