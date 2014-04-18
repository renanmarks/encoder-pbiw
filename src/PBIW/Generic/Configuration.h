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
 * File:   Configuration.h
 * Author: helix
 *
 * Created on July 22, 2012, 7:18 PM
 */

#ifndef PBIW_GENERIC_CONFIGURATION_H
#define	PBIW_GENERIC_CONFIGURATION_H

namespace PBIW
{
  namespace Generic
  {
    /**
    * Holds all configuration options used by the Generic PBIW codec.
    * This class uses a fluent syntax to ease the configuration.
    */
    class Configuration
    {
    public:
      /**
      * Types of cancellation bits.
      */
      typedef struct {
        typedef enum {
          NONE,       // No use of cancellation bits
          INDIVIDUAL, // One bit disables one operation
          MATRIX      // One bit disables one row/column of the execution matrix
        } Type;
      } CancellationBits;

      /**
      * Types of PBIW instruction formats.
      */
      typedef struct {
        typedef enum {
          CONSTRAINED,  // Read and write share different slots
          UNCONSTRAINED // Read and write share the same slots
        } Type;
      } InstructionFormat;

      Configuration();
      Configuration(const Configuration& orig);
      virtual ~Configuration();
      
      void setWriteFieldCount(unsigned int writeFieldCount);
      unsigned int getWriteFieldCount() const;
      
      void setReadFieldCount(unsigned int readFieldCount);
      unsigned int getReadFieldCount() const;
      
      void setInstructionFormatType(InstructionFormat::Type instructionFormatType);
      InstructionFormat::Type getInstructionFormatType() const;
      
      void setOperationCount(unsigned int operationCount);
      unsigned int getOperationCount() const;
      
      void setCancellationType(CancellationBits::Type cancellationType);
      CancellationBits::Type getCancellationType() const;

    private:
      CancellationBits::Type cancellationType;
      unsigned int operationCount;

      InstructionFormat::Type instructionFormatType;
      unsigned int readFieldCount;
      unsigned int writeFieldCount;
    };
  
  }
}

#endif	/* CONFIGURATION_H */

