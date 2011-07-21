/* 
 * File:   PBIW.h
 * Author: helix
 *
 * Created on July 20, 2011, 4:13 PM
 */

#ifndef PBIW_H
#define	PBIW_H

#include "IPBIW.h"

namespace PBIW
{ 
  namespace Concrete
  {
    using namespace Interfaces;
    using namespace Base;
    
    /**
    * Classe que realiza a codificação PBIW
    * 
    * Entrada do codificador: 128 caracteres ascii 0/1 que representam a instrução 
    * VEX em formato binário.
    * 
    * Saída do codificador: instruções e padrões em formato ascii onde cada
    * caractere é 0/1.
    */
    class PBIW: public IPBIW
    {
      private:
        std::vector<IVLIWInstruction> originalInstructions;
        
        std::vector<IPBIWInstruction> codedInstructions;
        std::vector<IPBIWPattern> codedPatterns;

      public:
        PBIW();
        PBIW(const PBIW& orig);
        virtual ~PBIW();

        virtual void encode(std::vector<IVLIWInstruction>);
        virtual void decode(std::vector<IPBIWInstruction>, std::vector<IPBIWPattern>);

        virtual std::ostream getInstructions();
        virtual std::ostream getPatterns();
    };
  }
}


#endif	/* PBIW_H */

