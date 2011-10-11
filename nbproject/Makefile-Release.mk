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
	${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o \
	${OBJECTDIR}/src/PBIW/PBIW.o \
	${OBJECTDIR}/src/rVex/SyllableMUL.o \
	${OBJECTDIR}/src/VexParser/scanner.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o \
	${OBJECTDIR}/src/rVex/SyllableALU.o \
	${OBJECTDIR}/src/rVex/SyllableMISC.o \
	${OBJECTDIR}/src/VexParser/VexContext.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o \
	${OBJECTDIR}/src/pbiw_encoder.o \
	${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o \
	${OBJECTDIR}/src/VexParser/Expressions/Expression.o \
	${OBJECTDIR}/src/rVex/SyllableCTRL.o \
	${OBJECTDIR}/src/rVex/Syllable.o \
	${OBJECTDIR}/src/VexParser/driver.o \
	${OBJECTDIR}/src/rVex/SyllableMEM.o \
	${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o \
	${OBJECTDIR}/src/VexParser/Expressions/Arguments.o \
	${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o \
	${OBJECTDIR}/src/VexParser/parser.tab.o \
	${OBJECTDIR}/src/rVex/Instruction.o \
	${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o

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

${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o: src/rVex/Operations/CTRL/GOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o src/rVex/Operations/CTRL/GOTO.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o: src/rVex/Operations/CTRL/RETURN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o src/rVex/Operations/CTRL/RETURN.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o: src/rVex/Operations/CTRL/ICALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o src/rVex/Operations/CTRL/ICALL.cpp

${OBJECTDIR}/src/PBIW/PBIW.o: src/PBIW/PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIW.o src/PBIW/PBIW.cpp

${OBJECTDIR}/src/rVex/SyllableMUL.o: src/rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMUL.o src/rVex/SyllableMUL.cpp

${OBJECTDIR}/src/VexParser/scanner.o: src/VexParser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/scanner.o src/VexParser/scanner.cc

${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o: src/rVex/Operations/CTRL/BR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o src/rVex/Operations/CTRL/BR.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o: src/rVex/Operations/CTRL/RFI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o src/rVex/Operations/CTRL/RFI.cpp

${OBJECTDIR}/src/rVex/SyllableALU.o: src/rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableALU.o src/rVex/SyllableALU.cpp

${OBJECTDIR}/src/rVex/SyllableMISC.o: src/rVex/SyllableMISC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMISC.o src/rVex/SyllableMISC.cpp

${OBJECTDIR}/src/VexParser/VexContext.o: src/VexParser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/VexContext.o src/VexParser/VexContext.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o: src/rVex/Operations/CTRL/CALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o src/rVex/Operations/CTRL/CALL.cpp

${OBJECTDIR}/src/pbiw_encoder.o: src/pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pbiw_encoder.o src/pbiw_encoder.cpp

${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o: src/PBIW/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o src/PBIW/rVex64PBIWInstruction.cpp

${OBJECTDIR}/src/VexParser/Expressions/Expression.o: src/VexParser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser/Expressions
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/Expressions/Expression.o src/VexParser/Expressions/Expression.cpp

${OBJECTDIR}/src/rVex/SyllableCTRL.o: src/rVex/SyllableCTRL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableCTRL.o src/rVex/SyllableCTRL.cpp

${OBJECTDIR}/src/rVex/Syllable.o: src/rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Syllable.o src/rVex/Syllable.cpp

${OBJECTDIR}/src/VexParser/driver.o: src/VexParser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/driver.o src/VexParser/driver.cc

${OBJECTDIR}/src/rVex/SyllableMEM.o: src/rVex/SyllableMEM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMEM.o src/rVex/SyllableMEM.cpp

${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o: src/PBIW/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o src/PBIW/rVex96PBIWPattern.cpp

${OBJECTDIR}/src/VexParser/Expressions/Arguments.o: src/VexParser/Expressions/Arguments.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser/Expressions
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/Expressions/Arguments.o src/VexParser/Expressions/Arguments.cpp

${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o: src/rVex/Printers/rVexPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Printers
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o src/rVex/Printers/rVexPrinter.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o: src/rVex/Operations/CTRL/BRF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o src/rVex/Operations/CTRL/BRF.cpp

${OBJECTDIR}/src/VexParser/parser.tab.o: src/VexParser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/parser.tab.o src/VexParser/parser.tab.cc

${OBJECTDIR}/src/rVex/Instruction.o: src/rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Instruction.o src/rVex/Instruction.cpp

${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o: src/rVex/Operations/CTRL/IGOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	${RM} $@.d
	$(COMPILE.cc) -O3 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o src/rVex/Operations/CTRL/IGOTO.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lgtest 

${TESTDIR}/TestFiles/f1: ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lgtest 


${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o src/rVex/Operations/CTRL/GOTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO_nomain.o src/rVex/Operations/CTRL/GOTO.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO.o ${OBJECTDIR}/src/rVex/Operations/CTRL/GOTO_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o src/rVex/Operations/CTRL/RETURN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN_nomain.o src/rVex/Operations/CTRL/RETURN.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN.o ${OBJECTDIR}/src/rVex/Operations/CTRL/RETURN_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o src/rVex/Operations/CTRL/ICALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL_nomain.o src/rVex/Operations/CTRL/ICALL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL.o ${OBJECTDIR}/src/rVex/Operations/CTRL/ICALL_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/PBIW_nomain.o: ${OBJECTDIR}/src/PBIW/PBIW.o src/PBIW/PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/PBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIW_nomain.o src/PBIW/PBIW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/PBIW.o ${OBJECTDIR}/src/PBIW/PBIW_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o: ${OBJECTDIR}/src/rVex/SyllableMUL.o src/rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableMUL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o src/rVex/SyllableMUL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableMUL.o ${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/scanner_nomain.o: ${OBJECTDIR}/src/VexParser/scanner.o src/VexParser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/scanner_nomain.o src/VexParser/scanner.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/scanner.o ${OBJECTDIR}/src/VexParser/scanner_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/BR_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o src/rVex/Operations/CTRL/BR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BR_nomain.o src/rVex/Operations/CTRL/BR.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/BR.o ${OBJECTDIR}/src/rVex/Operations/CTRL/BR_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/RFI_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o src/rVex/Operations/CTRL/RFI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI_nomain.o src/rVex/Operations/CTRL/RFI.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI.o ${OBJECTDIR}/src/rVex/Operations/CTRL/RFI_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableALU_nomain.o: ${OBJECTDIR}/src/rVex/SyllableALU.o src/rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableALU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableALU_nomain.o src/rVex/SyllableALU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableALU.o ${OBJECTDIR}/src/rVex/SyllableALU_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableMISC_nomain.o: ${OBJECTDIR}/src/rVex/SyllableMISC.o src/rVex/SyllableMISC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableMISC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMISC_nomain.o src/rVex/SyllableMISC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableMISC.o ${OBJECTDIR}/src/rVex/SyllableMISC_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/VexContext_nomain.o: ${OBJECTDIR}/src/VexParser/VexContext.o src/VexParser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/VexContext.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/VexContext_nomain.o src/VexParser/VexContext.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/VexContext.o ${OBJECTDIR}/src/VexParser/VexContext_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Operations/CTRL/CALL_nomain.o: ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o src/rVex/Operations/CTRL/CALL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Operations/CTRL
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL_nomain.o src/rVex/Operations/CTRL/CALL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL.o ${OBJECTDIR}/src/rVex/Operations/CTRL/CALL_nomain.o;\
	fi

${OBJECTDIR}/src/pbiw_encoder_nomain.o: ${OBJECTDIR}/src/pbiw_encoder.o src/pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/pbiw_encoder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pbiw_encoder_nomain.o src/pbiw_encoder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/pbiw_encoder.o ${OBJECTDIR}/src/pbiw_encoder_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction_nomain.o: ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o src/PBIW/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction_nomain.o src/PBIW/rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/Expressions/Expression_nomain.o: ${OBJECTDIR}/src/VexParser/Expressions/Expression.o src/VexParser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/Expressions/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/Expressions/Expression_nomain.o src/VexParser/Expressions/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/Expressions/Expression.o ${OBJECTDIR}/src/VexParser/Expressions/Expression_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o: ${OBJECTDIR}/src/rVex/SyllableCTRL.o src/rVex/SyllableCTRL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableCTRL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o src/rVex/SyllableCTRL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableCTRL.o ${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Syllable_nomain.o: ${OBJECTDIR}/src/rVex/Syllable.o src/rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Syllable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Syllable_nomain.o src/rVex/Syllable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Syllable.o ${OBJECTDIR}/src/rVex/Syllable_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/driver_nomain.o: ${OBJECTDIR}/src/VexParser/driver.o src/VexParser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/driver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/driver_nomain.o src/VexParser/driver.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/driver.o ${OBJECTDIR}/src/VexParser/driver_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o: ${OBJECTDIR}/src/rVex/SyllableMEM.o src/rVex/SyllableMEM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableMEM.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o src/rVex/SyllableMEM.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableMEM.o ${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o;\
	fi

${OBJECTDIR}/src/PBIW/rVex96PBIWPattern_nomain.o: ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o src/PBIW/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern_nomain.o src/PBIW/rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/Expressions/Arguments_nomain.o: ${OBJECTDIR}/src/VexParser/Expressions/Arguments.o src/VexParser/Expressions/Arguments.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/Expressions/Arguments.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/Expressions/Arguments_nomain.o src/VexParser/Expressions/Arguments.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/Expressions/Arguments.o ${OBJECTDIR}/src/VexParser/Expressions/Arguments_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Printers/rVexPrinter_nomain.o: ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o src/rVex/Printers/rVexPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex/Printers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Printers/rVexPrinter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Printers/rVexPrinter_nomain.o src/rVex/Printers/rVexPrinter.cpp;\
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
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF_nomain.o src/rVex/Operations/CTRL/BRF.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF.o ${OBJECTDIR}/src/rVex/Operations/CTRL/BRF_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/parser.tab_nomain.o: ${OBJECTDIR}/src/VexParser/parser.tab.o src/VexParser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/parser.tab.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/parser.tab_nomain.o src/VexParser/parser.tab.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/parser.tab.o ${OBJECTDIR}/src/VexParser/parser.tab_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Instruction_nomain.o: ${OBJECTDIR}/src/rVex/Instruction.o src/rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Instruction_nomain.o src/rVex/Instruction.cpp;\
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
	    $(COMPILE.cc) -O3 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO_nomain.o src/rVex/Operations/CTRL/IGOTO.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO.o ${OBJECTDIR}/src/rVex/Operations/CTRL/IGOTO_nomain.o;\
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
