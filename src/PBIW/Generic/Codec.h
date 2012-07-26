/* 
 * File:   GenericPBIW.h
 * Author: helix
 *
 * Created on July 19, 2012, 8:37 PM
 */

#ifndef PBIW_GENERIC_CODEC_H
#define	PBIW_GENERIC_CODEC_H

#include "src/PBIW/Interfaces/IPBIW.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Codec : public IPBIW
    {
    public:
      Codec();
      Codec(const Codec& orig);
      virtual ~Codec();

      virtual void encode(const std::vector<GenericAssembly::Interfaces::IInstruction*>&);
      virtual void decode(const std::vector<IPBIWInstruction*>&, const std::vector<IPBIWPattern*>&);

      virtual void registerOptimizer(IPBIWOptimizer&);
      virtual void runOptimizers();

      virtual void printStatistics(IPBIWPrinter&);
      virtual void printInstructions(IPBIWPrinter&);
      virtual void printPatterns(IPBIWPrinter&);

      virtual std::vector<IPBIWPattern*> getPatterns();
      virtual std::vector<IPBIWInstruction*> getInstructions();
      virtual std::vector<ILabel*> getLabels();

    private:

    };
  }
}

#endif	/* GENERICPBIW_H */
