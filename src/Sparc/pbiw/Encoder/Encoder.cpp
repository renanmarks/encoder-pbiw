#include "Encoder.h"

namespace Sparc
{
    namespace PBIW
    {
        Encoder::Encoder(const std::list<std::string>& inputFlags)
            : flagList(inputFlags)
        {

        }

        Encoder::~Encoder()
        {

        }

        void Encoder::run()
        {

        }

        std::list<std::string> Encoder::getSupportedCPUList() const
        {
            std::list<std::string> cpus;

            cpus.push_back(getTargetFlag() + " (SPARCv8 Processor)");

            return cpus;
        }

        std::string Encoder::getUsage() const
        {

        }

        std::string Encoder::getTargetFlag() const
        {
            return "sparcv8";
        }
    }
}
