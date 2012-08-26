#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/rVex/Operations/MEM/STH.o \
	${OBJECTDIR}/src/PBIW/Generic/Label.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/Operation.o \
	${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o \
	${OBJECTDIR}/src/rVex/PBIWFull/Operand.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/STW.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/MTB.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW.o \
	${OBJECTDIR}/src/rVex/SyllableMUL.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/Factory.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/LDBU.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/DIVS.o \
	${OBJECTDIR}/src/rVex/Parser/driver.o \
	${OBJECTDIR}/src/PBIW/Generic/Instruction.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o \
	${OBJECTDIR}/src/rVex/PBIWFull/Operation.o \
	${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o \
	${OBJECTDIR}/src/PBIW/Generic/Printer.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/LDH.o \
	${OBJECTDIR}/src/rVex/PBIWFull/Factory.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/STB.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction.o \
	${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet.o \
	${OBJECTDIR}/src/PBIW/Generic/Codec.o \
	${OBJECTDIR}/src/rVex/SyllableALU.o \
	${OBJECTDIR}/src/rVex/Label.o \
	${OBJECTDIR}/src/rVex/SyllableMISC.o \
	${OBJECTDIR}/src/rVex/Parser/scanner.o \
	${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder.o \
	${OBJECTDIR}/src/PBIW/Utils/OperandVector.o \
	${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO.o \
	${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW.o \
	${OBJECTDIR}/src/PBIW/Generic/Operation.o \
	${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation.o \
	${OBJECTDIR}/src/rVex/Parser/Structs/ISection.o \
	${OBJECTDIR}/src/PBIW/Generic/Configuration.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/LDHU.o \
	${OBJECTDIR}/src/PBIW/Generic/Pattern.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT.o \
	${OBJECTDIR}/src/pbiw_encoder.o \
	${OBJECTDIR}/src/rVex/Utils/DependencyChains.o \
	${OBJECTDIR}/src/rVex/Parser/Structs/Function.o \
	${OBJECTDIR}/src/rVex/Parser/parser.tab.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF.o \
	${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker.o \
	${OBJECTDIR}/src/PBIW/Generic/Factory.o \
	${OBJECTDIR}/src/rVex/Parser/Expressions/Expression.o \
	${OBJECTDIR}/src/rVex/SyllableCTRL.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE.o \
	${OBJECTDIR}/src/rVex/Syllable.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern.o \
	${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns.o \
	${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector.o \
	${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/LDB.o \
	${OBJECTDIR}/src/rVex/Operand.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/Operand.o \
	${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.o \
	${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments.o \
	${OBJECTDIR}/src/PBIW/Generic/Operand.o \
	${OBJECTDIR}/src/rVex/SyllableMEM.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE.o \
	${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.o \
	${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/SLCT.o \
	${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder.o \
	${OBJECTDIR}/src/rVex/Printers/VHDLPrinter.o \
	${OBJECTDIR}/src/rVex/Parser/VexContext.o \
	${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT.o \
	${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o \
	${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor.o \
	${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU.o \
	${OBJECTDIR}/src/rVex/Instruction.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o \
	${OBJECTDIR}/src/rVex/Operations/MEM/LDW.o \
	${OBJECTDIR}/src/PBIW/BaseOptimizer.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/rVex/Operations/MEM/STH.o: src/rVex/Operations/MEM/STH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/STH.o src/rVex/Operations/MEM/STH.cpp

${OBJECTDIR}/src/PBIW/Generic/Label.o: src/PBIW/Generic/Label.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Label.o src/PBIW/Generic/Label.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o: src/rVex/Operations/CTRL/GOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o src/rVex/Operations/CTRL/GOTO.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE.o: src/rVex/Operations/ALU/CMPNE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE.o src/rVex/Operations/ALU/CMPNE.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/Operation.o: src/rVex/PBIWPartial/Operation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Operation.o src/rVex/PBIWPartial/Operation.cpp

${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter.o: src/rVex/PBIWFull/Printers/FullPBIWPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter.o src/rVex/PBIWFull/Printers/FullPBIWPrinter.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o: src/rVex/Operations/CTRL/ICALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o src/rVex/Operations/CTRL/ICALL.cpp

${OBJECTDIR}/src/rVex/PBIWFull/Operand.o: src/rVex/PBIWFull/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Operand.o src/rVex/PBIWFull/Operand.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/STW.o: src/rVex/Operations/MEM/STW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/STW.o src/rVex/Operations/MEM/STW.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ.o: src/rVex/Operations/ALU/CMPEQ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ.o src/rVex/Operations/ALU/CMPEQ.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/MTB.o: src/rVex/Operations/ALU/MTB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/MTB.o src/rVex/Operations/ALU/MTB.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o: src/rVex/Operations/CTRL/RETURN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o src/rVex/Operations/CTRL/RETURN.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW.o: src/rVex/PBIWPartial/PartialPBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW.o src/rVex/PBIWPartial/PartialPBIW.cpp

${OBJECTDIR}/src/rVex/SyllableMUL.o: src/rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMUL.o src/rVex/SyllableMUL.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/Factory.o: src/rVex/PBIWPartial/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Factory.o src/rVex/PBIWPartial/Factory.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/LDBU.o: src/rVex/Operations/MEM/LDBU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDBU.o src/rVex/Operations/MEM/LDBU.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/DIVS.o: src/rVex/Operations/ALU/DIVS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/DIVS.o src/rVex/Operations/ALU/DIVS.cpp

${OBJECTDIR}/src/rVex/Parser/driver.o: src/rVex/Parser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/driver.o src/rVex/Parser/driver.cc

${OBJECTDIR}/src/PBIW/Generic/Instruction.o: src/PBIW/Generic/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Instruction.o src/PBIW/Generic/Instruction.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU.o: src/rVex/Operations/ALU/CMPLEU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU.o src/rVex/Operations/ALU/CMPLEU.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o: src/rVex/Operations/CTRL/BR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o src/rVex/Operations/CTRL/BR.cpp

${OBJECTDIR}/src/rVex/PBIWFull/Operation.o: src/rVex/PBIWFull/Operation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Operation.o src/rVex/PBIWFull/Operation.cpp

${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem.o: src/rVex/Parser/Structs/SyllableBufferItem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Structs
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem.o src/rVex/Parser/Structs/SyllableBufferItem.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o: src/rVex/Operations/CTRL/RFI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o src/rVex/Operations/CTRL/RFI.cpp

${OBJECTDIR}/src/PBIW/Generic/Printer.o: src/PBIW/Generic/Printer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Printer.o src/PBIW/Generic/Printer.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/LDH.o: src/rVex/Operations/MEM/LDH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDH.o src/rVex/Operations/MEM/LDH.cpp

${OBJECTDIR}/src/rVex/PBIWFull/Factory.o: src/rVex/PBIWFull/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Factory.o src/rVex/PBIWFull/Factory.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.o: src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.o src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/STB.o: src/rVex/Operations/MEM/STB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/STB.o src/rVex/Operations/MEM/STB.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG.o: src/rVex/Operations/ALU/ADDCG.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG.o src/rVex/Operations/ALU/ADDCG.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction.o: src/rVex/PBIWPartial/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction.o src/rVex/PBIWPartial/rVex64PBIWInstruction.cpp

${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet.o: src/PBIW/PBIWOptimizerDataSet.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet.o src/PBIW/PBIWOptimizerDataSet.cpp

${OBJECTDIR}/src/PBIW/Generic/Codec.o: src/PBIW/Generic/Codec.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Codec.o src/PBIW/Generic/Codec.cpp

${OBJECTDIR}/src/rVex/SyllableALU.o: src/rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableALU.o src/rVex/SyllableALU.cpp

${OBJECTDIR}/src/rVex/Label.o: src/rVex/Label.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Label.o src/rVex/Label.cpp

${OBJECTDIR}/src/rVex/SyllableMISC.o: src/rVex/SyllableMISC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMISC.o src/rVex/SyllableMISC.cpp

${OBJECTDIR}/src/rVex/Parser/scanner.o: src/rVex/Parser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/scanner.o src/rVex/Parser/scanner.cc

${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder.o: src/rVex/Utils/OperandVectorBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Utils
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder.o src/rVex/Utils/OperandVectorBuilder.cpp

${OBJECTDIR}/src/PBIW/Utils/OperandVector.o: src/PBIW/Utils/OperandVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Utils
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Utils/OperandVector.o src/PBIW/Utils/OperandVector.cpp

${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO.o: src/PBIW/Utils/OperandVectorDTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Utils
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO.o src/PBIW/Utils/OperandVectorDTO.cpp

${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW.o: src/rVex/PBIWFull/FullPBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW.o src/rVex/PBIWFull/FullPBIW.cpp

${OBJECTDIR}/src/PBIW/Generic/Operation.o: src/PBIW/Generic/Operation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Operation.o src/PBIW/Generic/Operation.cpp

${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation.o: src/PBIW/Optimizers/JoinPattern/PatternInformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation.o src/PBIW/Optimizers/JoinPattern/PatternInformation.cpp

${OBJECTDIR}/src/rVex/Parser/Structs/ISection.o: src/rVex/Parser/Structs/ISection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Structs
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Structs/ISection.o src/rVex/Parser/Structs/ISection.cpp

${OBJECTDIR}/src/PBIW/Generic/Configuration.o: src/PBIW/Generic/Configuration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Configuration.o src/PBIW/Generic/Configuration.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/LDHU.o: src/rVex/Operations/MEM/LDHU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDHU.o src/rVex/Operations/MEM/LDHU.cpp

${OBJECTDIR}/src/PBIW/Generic/Pattern.o: src/PBIW/Generic/Pattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Pattern.o src/PBIW/Generic/Pattern.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT.o: src/rVex/Operations/ALU/CMPGT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT.o src/rVex/Operations/ALU/CMPGT.cpp

${OBJECTDIR}/src/pbiw_encoder.o: src/pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pbiw_encoder.o src/pbiw_encoder.cpp

${OBJECTDIR}/src/rVex/Utils/DependencyChains.o: src/rVex/Utils/DependencyChains.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Utils
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Utils/DependencyChains.o src/rVex/Utils/DependencyChains.cpp

${OBJECTDIR}/src/rVex/Parser/Structs/Function.o: src/rVex/Parser/Structs/Function.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Structs
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Structs/Function.o src/rVex/Parser/Structs/Function.cpp

${OBJECTDIR}/src/rVex/Parser/parser.tab.o: src/rVex/Parser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/parser.tab.o src/rVex/Parser/parser.tab.cc

${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o: src/rVex/Operations/CTRL/CALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o src/rVex/Operations/CTRL/CALL.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF.o: src/rVex/Operations/ALU/SLCTF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF.o src/rVex/Operations/ALU/SLCTF.cpp

${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker.o: src/rVex/Parser/Processors/SyllablePacker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Processors
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker.o src/rVex/Parser/Processors/SyllablePacker.cpp

${OBJECTDIR}/src/PBIW/Generic/Factory.o: src/PBIW/Generic/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Factory.o src/PBIW/Generic/Factory.cpp

${OBJECTDIR}/src/rVex/Parser/Expressions/Expression.o: src/rVex/Parser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Expressions
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Expressions/Expression.o src/rVex/Parser/Expressions/Expression.cpp

${OBJECTDIR}/src/rVex/SyllableCTRL.o: src/rVex/SyllableCTRL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableCTRL.o src/rVex/SyllableCTRL.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE.o: src/rVex/Operations/ALU/CMPLE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE.o src/rVex/Operations/ALU/CMPLE.cpp

${OBJECTDIR}/src/rVex/Syllable.o: src/rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Syllable.o src/rVex/Syllable.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern.o: src/rVex/PBIWPartial/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern.o src/rVex/PBIWPartial/rVex96PBIWPattern.cpp

${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns.o: src/PBIW/PBIWOptimizerJoinPatterns.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns.o src/PBIW/PBIWOptimizerJoinPatterns.cpp

${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector.o: src/GenericAssembly/Utils/OperandVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GenericAssembly/Utils
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector.o src/GenericAssembly/Utils/OperandVector.cpp

${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation.o: src/PBIW/Optimizers/JoinPattern/OperationInformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation.o src/PBIW/Optimizers/JoinPattern/OperationInformation.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/LDB.o: src/rVex/Operations/MEM/LDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDB.o src/rVex/Operations/MEM/LDB.cpp

${OBJECTDIR}/src/rVex/Operand.o: src/rVex/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operand.o src/rVex/Operand.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/Operand.o: src/rVex/PBIWPartial/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Operand.o src/rVex/PBIWPartial/Operand.cpp

${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.o: src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.o src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.cpp

${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments.o: src/rVex/Parser/Expressions/Arguments.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Expressions
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments.o src/rVex/Parser/Expressions/Arguments.cpp

${OBJECTDIR}/src/PBIW/Generic/Operand.o: src/PBIW/Generic/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Operand.o src/PBIW/Generic/Operand.cpp

${OBJECTDIR}/src/rVex/SyllableMEM.o: src/rVex/SyllableMEM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMEM.o src/rVex/SyllableMEM.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE.o: src/rVex/Operations/ALU/CMPGE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE.o src/rVex/Operations/ALU/CMPGE.cpp

${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.o: src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.o src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.cpp

${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction.o: src/rVex/PBIWFull/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction.o src/rVex/PBIWFull/rVex64PBIWInstruction.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/SLCT.o: src/rVex/Operations/ALU/SLCT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/SLCT.o src/rVex/Operations/ALU/SLCT.cpp

${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder.o: src/PBIW/Optimizers/JoinPattern/PatternBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder.o src/PBIW/Optimizers/JoinPattern/PatternBuilder.cpp

${OBJECTDIR}/src/rVex/Printers/VHDLPrinter.o: src/rVex/Printers/VHDLPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Printers/VHDLPrinter.o src/rVex/Printers/VHDLPrinter.cpp

${OBJECTDIR}/src/rVex/Parser/VexContext.o: src/rVex/Parser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/VexContext.o src/rVex/Parser/VexContext.cpp

${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern.o: src/rVex/PBIWFull/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern.o src/rVex/PBIWFull/rVex96PBIWPattern.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU.o: src/rVex/Operations/ALU/CMPLTU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU.o src/rVex/Operations/ALU/CMPLTU.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU.o: src/rVex/Operations/ALU/CMPGEU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU.o src/rVex/Operations/ALU/CMPGEU.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT.o: src/rVex/Operations/ALU/CMPLT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT.o src/rVex/Operations/ALU/CMPLT.cpp

${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o: src/rVex/Printers/rVexPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o src/rVex/Printers/rVexPrinter.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o: src/rVex/Operations/CTRL/BRF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o src/rVex/Operations/CTRL/BRF.cpp

${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor.o: src/rVex/Parser/Processors/PseudoSyllableProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Processors
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor.o src/rVex/Parser/Processors/PseudoSyllableProcessor.cpp

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU.o: src/rVex/Operations/ALU/CMPGTU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU.o src/rVex/Operations/ALU/CMPGTU.cpp

${OBJECTDIR}/src/rVex/Instruction.o: src/rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Instruction.o src/rVex/Instruction.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o: src/rVex/Operations/CTRL/IGOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o src/rVex/Operations/CTRL/IGOTO.cpp

${OBJECTDIR}/src/rVex/Operations/MEM/LDW.o: src/rVex/Operations/MEM/LDW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDW.o src/rVex/Operations/MEM/LDW.cpp

${OBJECTDIR}/src/PBIW/BaseOptimizer.o: src/PBIW/BaseOptimizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/BaseOptimizer.o src/PBIW/BaseOptimizer.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/src/Tests/Parser/ExpressionTest.o ${TESTDIR}/src/Tests/Parser/VexContextTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} /usr/local/lib/gtest/libgtest.so /usr/local/lib/gtest/libgtest_main.so 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/src/Tests/rVex/rVexInstructionTest.o ${TESTDIR}/src/Tests/rVex/rVexSyllableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} /usr/local/lib/gtest/libgtest.so /usr/local/lib/gtest/libgtest_main.so 


${TESTDIR}/src/Tests/Parser/ExpressionTest.o: src/Tests/Parser/ExpressionTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/Parser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/Parser/ExpressionTest.o src/Tests/Parser/ExpressionTest.cpp


${TESTDIR}/src/Tests/Parser/VexContextTest.o: src/Tests/Parser/VexContextTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/Parser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/Parser/VexContextTest.o src/Tests/Parser/VexContextTest.cpp


${TESTDIR}/src/Tests/rVex/rVexInstructionTest.o: src/Tests/rVex/rVexInstructionTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/rVex/rVexInstructionTest.o src/Tests/rVex/rVexInstructionTest.cpp


${TESTDIR}/src/Tests/rVex/rVexSyllableTest.o: src/Tests/rVex/rVexSyllableTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/rVex/rVexSyllableTest.o src/Tests/rVex/rVexSyllableTest.cpp


${OBJECTDIR}/src/rVex/Operations/MEM/STH_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/STH.o src/rVex/Operations/MEM/STH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/STH.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/STH_nomain.o src/rVex/Operations/MEM/STH.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/STH.o ${OBJECTDIR}/src/rVex/Operations/MEM/STH_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Label_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Label.o src/PBIW/Generic/Label.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Label.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Label_nomain.o src/PBIW/Generic/Label.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Label.o ${OBJECTDIR}/src/PBIW/Generic/Label_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o src/rVex/Operations/CTRL/GOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO_nomain.o src/rVex/Operations/CTRL/GOTO.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE.o src/rVex/Operations/ALU/CMPNE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE_nomain.o src/rVex/Operations/ALU/CMPNE.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPNE_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/Operation_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/Operation.o src/rVex/PBIWPartial/Operation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/Operation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Operation_nomain.o src/rVex/PBIWPartial/Operation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/Operation.o ${OBJECTDIR}/src/rVex/PBIWPartial/Operation_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter.o src/rVex/PBIWFull/Printers/FullPBIWPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter_nomain.o src/rVex/PBIWFull/Printers/FullPBIWPrinter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter.o ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWPrinter_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o src/rVex/Operations/CTRL/ICALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL_nomain.o src/rVex/Operations/CTRL/ICALL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/Operand_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/Operand.o src/rVex/PBIWFull/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/Operand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Operand_nomain.o src/rVex/PBIWFull/Operand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/Operand.o ${OBJECTDIR}/src/rVex/PBIWFull/Operand_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/STW_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/STW.o src/rVex/Operations/MEM/STW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/STW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/STW_nomain.o src/rVex/Operations/MEM/STW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/STW.o ${OBJECTDIR}/src/rVex/Operations/MEM/STW_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ.o src/rVex/Operations/ALU/CMPEQ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ_nomain.o src/rVex/Operations/ALU/CMPEQ.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPEQ_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/MTB_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/MTB.o src/rVex/Operations/ALU/MTB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/MTB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/MTB_nomain.o src/rVex/Operations/ALU/MTB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/MTB.o ${OBJECTDIR}/src/rVex/Operations/ALU/MTB_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o src/rVex/Operations/CTRL/RETURN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN_nomain.o src/rVex/Operations/CTRL/RETURN.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW.o src/rVex/PBIWPartial/PartialPBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW_nomain.o src/rVex/PBIWPartial/PartialPBIW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW.o ${OBJECTDIR}/src/rVex/PBIWPartial/PartialPBIW_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o: ${OBJECTDIR}/src/rVex/SyllableMUL.o src/rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableMUL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o src/rVex/SyllableMUL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableMUL.o ${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/Factory_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/Factory.o src/rVex/PBIWPartial/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/Factory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Factory_nomain.o src/rVex/PBIWPartial/Factory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/Factory.o ${OBJECTDIR}/src/rVex/PBIWPartial/Factory_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/LDBU_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/LDBU.o src/rVex/Operations/MEM/LDBU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/LDBU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDBU_nomain.o src/rVex/Operations/MEM/LDBU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/LDBU.o ${OBJECTDIR}/src/rVex/Operations/MEM/LDBU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/DIVS_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/DIVS.o src/rVex/Operations/ALU/DIVS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/DIVS.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/DIVS_nomain.o src/rVex/Operations/ALU/DIVS.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/DIVS.o ${OBJECTDIR}/src/rVex/Operations/ALU/DIVS_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/driver_nomain.o: ${OBJECTDIR}/src/rVex/Parser/driver.o src/rVex/Parser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/driver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/driver_nomain.o src/rVex/Parser/driver.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/driver.o ${OBJECTDIR}/src/rVex/Parser/driver_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Instruction_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Instruction.o src/PBIW/Generic/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Instruction_nomain.o src/PBIW/Generic/Instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Instruction.o ${OBJECTDIR}/src/PBIW/Generic/Instruction_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU.o src/rVex/Operations/ALU/CMPLEU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU_nomain.o src/rVex/Operations/ALU/CMPLEU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLEU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/BR_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o src/rVex/Operations/CTRL/BR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BR_nomain.o src/rVex/Operations/CTRL/BR.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o ${OBJECTDIR}/src/rVex/Operations/CTRL/BR_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/Operation_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/Operation.o src/rVex/PBIWFull/Operation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/Operation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Operation_nomain.o src/rVex/PBIWFull/Operation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/Operation.o ${OBJECTDIR}/src/rVex/PBIWFull/Operation_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem.o src/rVex/Parser/Structs/SyllableBufferItem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Structs
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem_nomain.o src/rVex/Parser/Structs/SyllableBufferItem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem.o ${OBJECTDIR}/src/rVex/Parser/Structs/SyllableBufferItem_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/RFI_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o src/rVex/Operations/CTRL/RFI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI_nomain.o src/rVex/Operations/CTRL/RFI.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Printer_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Printer.o src/PBIW/Generic/Printer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Printer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Printer_nomain.o src/PBIW/Generic/Printer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Printer.o ${OBJECTDIR}/src/PBIW/Generic/Printer_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/LDH_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/LDH.o src/rVex/Operations/MEM/LDH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/LDH.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDH_nomain.o src/rVex/Operations/MEM/LDH.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/LDH.o ${OBJECTDIR}/src/rVex/Operations/MEM/LDH_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/Factory_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/Factory.o src/rVex/PBIWFull/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/Factory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Factory_nomain.o src/rVex/PBIWFull/Factory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/Factory.o ${OBJECTDIR}/src/rVex/PBIWFull/Factory_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.o src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter_nomain.o src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter.o ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWDebugPrinter_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/STB_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/STB.o src/rVex/Operations/MEM/STB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/STB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/STB_nomain.o src/rVex/Operations/MEM/STB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/STB.o ${OBJECTDIR}/src/rVex/Operations/MEM/STB_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG.o src/rVex/Operations/ALU/ADDCG.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG_nomain.o src/rVex/Operations/ALU/ADDCG.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG.o ${OBJECTDIR}/src/rVex/Operations/ALU/ADDCG_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction.o src/rVex/PBIWPartial/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction_nomain.o src/rVex/PBIWPartial/rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction.o ${OBJECTDIR}/src/rVex/PBIWPartial/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet_nomain.o: ${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet.o src/PBIW/PBIWOptimizerDataSet.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet_nomain.o src/PBIW/PBIWOptimizerDataSet.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet.o ${OBJECTDIR}/src/PBIW/PBIWOptimizerDataSet_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Codec_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Codec.o src/PBIW/Generic/Codec.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Codec.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Codec_nomain.o src/PBIW/Generic/Codec.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Codec.o ${OBJECTDIR}/src/PBIW/Generic/Codec_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableALU_nomain.o: ${OBJECTDIR}/src/rVex/SyllableALU.o src/rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableALU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableALU_nomain.o src/rVex/SyllableALU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableALU.o ${OBJECTDIR}/src/rVex/SyllableALU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Label_nomain.o: ${OBJECTDIR}/src/rVex/Label.o src/rVex/Label.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Label.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Label_nomain.o src/rVex/Label.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Label.o ${OBJECTDIR}/src/rVex/Label_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableMISC_nomain.o: ${OBJECTDIR}/src/rVex/SyllableMISC.o src/rVex/SyllableMISC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableMISC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMISC_nomain.o src/rVex/SyllableMISC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableMISC.o ${OBJECTDIR}/src/rVex/SyllableMISC_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/scanner_nomain.o: ${OBJECTDIR}/src/rVex/Parser/scanner.o src/rVex/Parser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/scanner_nomain.o src/rVex/Parser/scanner.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/scanner.o ${OBJECTDIR}/src/rVex/Parser/scanner_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder_nomain.o: ${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder.o src/rVex/Utils/OperandVectorBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder_nomain.o src/rVex/Utils/OperandVectorBuilder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder.o ${OBJECTDIR}/src/rVex/Utils/OperandVectorBuilder_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Utils/OperandVector_nomain.o: ${OBJECTDIR}/src/PBIW/Utils/OperandVector.o src/PBIW/Utils/OperandVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Utils/OperandVector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Utils/OperandVector_nomain.o src/PBIW/Utils/OperandVector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Utils/OperandVector.o ${OBJECTDIR}/src/PBIW/Utils/OperandVector_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO_nomain.o: ${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO.o src/PBIW/Utils/OperandVectorDTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO_nomain.o src/PBIW/Utils/OperandVectorDTO.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO.o ${OBJECTDIR}/src/PBIW/Utils/OperandVectorDTO_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW.o src/rVex/PBIWFull/FullPBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW_nomain.o src/rVex/PBIWFull/FullPBIW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW.o ${OBJECTDIR}/src/rVex/PBIWFull/FullPBIW_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Operation_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Operation.o src/PBIW/Generic/Operation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Operation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Operation_nomain.o src/PBIW/Generic/Operation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Operation.o ${OBJECTDIR}/src/PBIW/Generic/Operation_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation_nomain.o: ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation.o src/PBIW/Optimizers/JoinPattern/PatternInformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation_nomain.o src/PBIW/Optimizers/JoinPattern/PatternInformation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation.o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternInformation_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Structs/ISection_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Structs/ISection.o src/rVex/Parser/Structs/ISection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Structs
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Structs/ISection.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Structs/ISection_nomain.o src/rVex/Parser/Structs/ISection.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Structs/ISection.o ${OBJECTDIR}/src/rVex/Parser/Structs/ISection_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Configuration_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Configuration.o src/PBIW/Generic/Configuration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Configuration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Configuration_nomain.o src/PBIW/Generic/Configuration.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Configuration.o ${OBJECTDIR}/src/PBIW/Generic/Configuration_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/LDHU_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/LDHU.o src/rVex/Operations/MEM/LDHU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/LDHU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDHU_nomain.o src/rVex/Operations/MEM/LDHU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/LDHU.o ${OBJECTDIR}/src/rVex/Operations/MEM/LDHU_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Pattern_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Pattern.o src/PBIW/Generic/Pattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Pattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Pattern_nomain.o src/PBIW/Generic/Pattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Pattern.o ${OBJECTDIR}/src/PBIW/Generic/Pattern_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT.o src/rVex/Operations/ALU/CMPGT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT_nomain.o src/rVex/Operations/ALU/CMPGT.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGT_nomain.o;\
	fi

${OBJECTDIR}/src/pbiw_encoder_nomain.o: ${OBJECTDIR}/src/pbiw_encoder.o src/pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/pbiw_encoder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pbiw_encoder_nomain.o src/pbiw_encoder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/pbiw_encoder.o ${OBJECTDIR}/src/pbiw_encoder_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Utils/DependencyChains_nomain.o: ${OBJECTDIR}/src/rVex/Utils/DependencyChains.o src/rVex/Utils/DependencyChains.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Utils/DependencyChains.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Utils/DependencyChains_nomain.o src/rVex/Utils/DependencyChains.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Utils/DependencyChains.o ${OBJECTDIR}/src/rVex/Utils/DependencyChains_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Structs/Function_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Structs/Function.o src/rVex/Parser/Structs/Function.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Structs
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Structs/Function.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Structs/Function_nomain.o src/rVex/Parser/Structs/Function.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Structs/Function.o ${OBJECTDIR}/src/rVex/Parser/Structs/Function_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/parser.tab_nomain.o: ${OBJECTDIR}/src/rVex/Parser/parser.tab.o src/rVex/Parser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/parser.tab.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/parser.tab_nomain.o src/rVex/Parser/parser.tab.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/parser.tab.o ${OBJECTDIR}/src/rVex/Parser/parser.tab_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/CALL_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o src/rVex/Operations/CTRL/CALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL_nomain.o src/rVex/Operations/CTRL/CALL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF.o src/rVex/Operations/ALU/SLCTF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF_nomain.o src/rVex/Operations/ALU/SLCTF.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF.o ${OBJECTDIR}/src/rVex/Operations/ALU/SLCTF_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker.o src/rVex/Parser/Processors/SyllablePacker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Processors
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker_nomain.o src/rVex/Parser/Processors/SyllablePacker.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker.o ${OBJECTDIR}/src/rVex/Parser/Processors/SyllablePacker_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Factory_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Factory.o src/PBIW/Generic/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Factory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Factory_nomain.o src/PBIW/Generic/Factory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Factory.o ${OBJECTDIR}/src/PBIW/Generic/Factory_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Expressions/Expression_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Expressions/Expression.o src/rVex/Parser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Expressions/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Expressions/Expression_nomain.o src/rVex/Parser/Expressions/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Expressions/Expression.o ${OBJECTDIR}/src/rVex/Parser/Expressions/Expression_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o: ${OBJECTDIR}/src/rVex/SyllableCTRL.o src/rVex/SyllableCTRL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableCTRL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o src/rVex/SyllableCTRL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableCTRL.o ${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE.o src/rVex/Operations/ALU/CMPLE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE_nomain.o src/rVex/Operations/ALU/CMPLE.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLE_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Syllable_nomain.o: ${OBJECTDIR}/src/rVex/Syllable.o src/rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Syllable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Syllable_nomain.o src/rVex/Syllable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Syllable.o ${OBJECTDIR}/src/rVex/Syllable_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern.o src/rVex/PBIWPartial/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern_nomain.o src/rVex/PBIWPartial/rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern.o ${OBJECTDIR}/src/rVex/PBIWPartial/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns_nomain.o: ${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns.o src/PBIW/PBIWOptimizerJoinPatterns.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns_nomain.o src/PBIW/PBIWOptimizerJoinPatterns.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns.o ${OBJECTDIR}/src/PBIW/PBIWOptimizerJoinPatterns_nomain.o;\
	fi

${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector_nomain.o: ${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector.o src/GenericAssembly/Utils/OperandVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GenericAssembly/Utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector_nomain.o src/GenericAssembly/Utils/OperandVector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector.o ${OBJECTDIR}/src/GenericAssembly/Utils/OperandVector_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation_nomain.o: ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation.o src/PBIW/Optimizers/JoinPattern/OperationInformation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation_nomain.o src/PBIW/Optimizers/JoinPattern/OperationInformation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation.o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/OperationInformation_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/LDB_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/LDB.o src/rVex/Operations/MEM/LDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/LDB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDB_nomain.o src/rVex/Operations/MEM/LDB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/LDB.o ${OBJECTDIR}/src/rVex/Operations/MEM/LDB_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operand_nomain.o: ${OBJECTDIR}/src/rVex/Operand.o src/rVex/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operand_nomain.o src/rVex/Operand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operand.o ${OBJECTDIR}/src/rVex/Operand_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/Operand_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/Operand.o src/rVex/PBIWPartial/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/Operand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Operand_nomain.o src/rVex/PBIWPartial/Operand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/Operand.o ${OBJECTDIR}/src/rVex/PBIWPartial/Operand_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.o src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter_nomain.o src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.o ${OBJECTDIR}/src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments.o src/rVex/Parser/Expressions/Arguments.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments_nomain.o src/rVex/Parser/Expressions/Arguments.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments.o ${OBJECTDIR}/src/rVex/Parser/Expressions/Arguments_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Generic/Operand_nomain.o: ${OBJECTDIR}/src/PBIW/Generic/Operand.o src/PBIW/Generic/Operand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Generic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Generic/Operand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Generic/Operand_nomain.o src/PBIW/Generic/Operand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Generic/Operand.o ${OBJECTDIR}/src/PBIW/Generic/Operand_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o: ${OBJECTDIR}/src/rVex/SyllableMEM.o src/rVex/SyllableMEM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableMEM.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o src/rVex/SyllableMEM.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableMEM.o ${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE.o src/rVex/Operations/ALU/CMPGE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE_nomain.o src/rVex/Operations/ALU/CMPGE.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGE_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter_nomain.o: ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.o src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWPartial/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter_nomain.o src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter.o ${OBJECTDIR}/src/rVex/PBIWPartial/Printers/PartialPBIWPrinter_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction.o src/rVex/PBIWFull/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction_nomain.o src/rVex/PBIWFull/rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction.o ${OBJECTDIR}/src/rVex/PBIWFull/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/SLCT_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/SLCT.o src/rVex/Operations/ALU/SLCT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/SLCT.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/SLCT_nomain.o src/rVex/Operations/ALU/SLCT.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/SLCT.o ${OBJECTDIR}/src/rVex/Operations/ALU/SLCT_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder_nomain.o: ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder.o src/PBIW/Optimizers/JoinPattern/PatternBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder_nomain.o src/PBIW/Optimizers/JoinPattern/PatternBuilder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder.o ${OBJECTDIR}/src/PBIW/Optimizers/JoinPattern/PatternBuilder_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Printers/VHDLPrinter_nomain.o: ${OBJECTDIR}/src/rVex/Printers/VHDLPrinter.o src/rVex/Printers/VHDLPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Printers/VHDLPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Printers/VHDLPrinter_nomain.o src/rVex/Printers/VHDLPrinter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Printers/VHDLPrinter.o ${OBJECTDIR}/src/rVex/Printers/VHDLPrinter_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/VexContext_nomain.o: ${OBJECTDIR}/src/rVex/Parser/VexContext.o src/rVex/Parser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/VexContext.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/VexContext_nomain.o src/rVex/Parser/VexContext.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/VexContext.o ${OBJECTDIR}/src/rVex/Parser/VexContext_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern_nomain.o: ${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern.o src/rVex/PBIWFull/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/PBIWFull
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern_nomain.o src/rVex/PBIWFull/rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern.o ${OBJECTDIR}/src/rVex/PBIWFull/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU.o src/rVex/Operations/ALU/CMPLTU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU_nomain.o src/rVex/Operations/ALU/CMPLTU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLTU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU.o src/rVex/Operations/ALU/CMPGEU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU_nomain.o src/rVex/Operations/ALU/CMPGEU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGEU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT.o src/rVex/Operations/ALU/CMPLT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT_nomain.o src/rVex/Operations/ALU/CMPLT.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPLT_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Printers/rVexPrinter_nomain.o: ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o src/rVex/Printers/rVexPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Printers/rVexPrinter_nomain.o src/rVex/Printers/rVexPrinter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o ${OBJECTDIR}/src/rVex/Printers/rVexPrinter_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/BRF_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o src/rVex/Operations/CTRL/BRF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF_nomain.o src/rVex/Operations/CTRL/BRF.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor_nomain.o: ${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor.o src/rVex/Parser/Processors/PseudoSyllableProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Parser/Processors
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor_nomain.o src/rVex/Parser/Processors/PseudoSyllableProcessor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor.o ${OBJECTDIR}/src/rVex/Parser/Processors/PseudoSyllableProcessor_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU_nomain.o: ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU.o src/rVex/Operations/ALU/CMPGTU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU_nomain.o src/rVex/Operations/ALU/CMPGTU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU.o ${OBJECTDIR}/src/rVex/Operations/ALU/CMPGTU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Instruction_nomain.o: ${OBJECTDIR}/src/rVex/Instruction.o src/rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Instruction_nomain.o src/rVex/Instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Instruction.o ${OBJECTDIR}/src/rVex/Instruction_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o src/rVex/Operations/CTRL/IGOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO_nomain.o src/rVex/Operations/CTRL/IGOTO.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/MEM/LDW_nomain.o: ${OBJECTDIR}/src/rVex/Operations/MEM/LDW.o src/rVex/Operations/MEM/LDW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/MEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/MEM/LDW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/MEM/LDW_nomain.o src/rVex/Operations/MEM/LDW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/MEM/LDW.o ${OBJECTDIR}/src/rVex/Operations/MEM/LDW_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/BaseOptimizer_nomain.o: ${OBJECTDIR}/src/PBIW/BaseOptimizer.o src/PBIW/BaseOptimizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/BaseOptimizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/BaseOptimizer_nomain.o src/PBIW/BaseOptimizer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/BaseOptimizer.o ${OBJECTDIR}/src/PBIW/BaseOptimizer_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
