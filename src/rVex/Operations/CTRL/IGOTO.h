/* 
 * File:   IIGOTO.h
 * Author: renato
 *
 * Created on 7 de Setembro de 2011, 00:28
 */

#ifndef IIGOTO_H
#define	IIGOTO_H

#include "../../SyllableCTRL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      class IGOTO : public SyllableCTRL
      {
        public:
          unsigned int getOpcode() const { return this->opIGOTO; }
          SyllableType::Type getSyllableType() const { return SyllableType::CTRL; }
          
          virtual void print(rVex::Printers::IPrinter&, bool, bool) const;
          
          virtual void fillSyllable(VexParser::SyllableArguments& arguments)
          { this->fillTypeXIX(arguments); }
      };
    }
  }
}

#endif	/* IIGOTO_H */

