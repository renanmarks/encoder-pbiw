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

