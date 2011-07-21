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
  using namespace Interfaces;
  
  namespace Concrete
  {
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


      public:
        PBIW();
        PBIW(const PBIW& orig);
        virtual ~PBIW();

        virtual void encode();
        virtual void decode();

        virtual std::ostream getInstructions();
        virtual std::ostream getPatterns();
    };
  }
}


#endif	/* PBIW_H */

