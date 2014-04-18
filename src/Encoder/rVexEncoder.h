/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   Encoder.h
 * Author: helix
 *
 * Created on October 6, 2012, 10:50 PM
 */

#ifndef RVEXENCODER_H
#define	RVEXENCODER_H

#include <list>
#include <map>
#include <string>
#include "PBIW/PBIWOptimizerDataSet.h"
#include "rVex/Parser/VexContext.h"

namespace Encoder
{
  class rVexEncoder
  {
  public:
    explicit rVexEncoder(const std::list<std::string>&);
    virtual ~rVexEncoder();
    
    void run();
  
  private:
    rVexEncoder(const rVexEncoder&);
    
    typedef struct
    {
      typedef enum
      {
        TraceParsing,
        TraceScanning,
        DebugMode,
        PrintDineroData
      } Type;
    } Config;
    
    typedef struct
    {
      typedef enum
      {
        Unconstrained, // versão 1.0
        Constrained    // versão 2.0
      } Type;
    } Algorithm;
    
    typedef struct
    {
      typedef enum
      {
        PatternJoin
      } Type;
    } Optimization;
    
    std::map<Config::Type, bool> config;
    std::map<Optimization::Type, bool> optimizations;
    Algorithm::Type algorithm;
    
    std::list<std::string> flagList;
    std::string flagString;
    std::list<std::string> inputFilenames;
    
    PBIW::PBIWPatternSetOptimizer patternSetOptimizer;
    
    void encodeAlgorithm(PBIW::Interfaces::IPBIWPrinter&, 
                          PBIW::Interfaces::IPBIWPrinter&,
                          PBIW::Interfaces::IPBIWPrinter&,
                          PBIW::Interfaces::IPBIW&,
                          VexParser::VexContext&);
    
    template <class TPBIWPrinter> void
    encodePBIW(const std::string&, PBIW::Interfaces::IPBIW&, VexParser::VexContext&);
    
    void encodePartialPBIW(const std::string&, VexParser::VexContext&);
    void encodeFullPBIW(const std::string&, VexParser::VexContext&);
    
    void assemble(const std::string&, VexParser::VexContext&);
    void processPBIW(const std::string&, VexParser::VexContext&);
  };
}

#endif	/* RVEXENCODER_H */

