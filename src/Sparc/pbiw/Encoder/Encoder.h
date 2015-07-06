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
            explicit Encoder();
            virtual ~Encoder();

            virtual void run();
            virtual std::list<std::string> getSupportedCPUList() const;
            virtual std::string getUsage() const;
            virtual std::string getTargetFlag() const;
        };
    }
}

#endif // PBIWSPARCENCODER_H
