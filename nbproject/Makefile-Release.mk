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
	${OBJECTDIR}/src/PBIW/PBIW.o \
	${OBJECTDIR}/src/rVex/SyllableMUL.o \
	${OBJECTDIR}/src/VexParser/scanner.o \
	${OBJECTDIR}/src/rVex/SyllableALU.o \
	${OBJECTDIR}/src/VexParser/VexContext.o \
	${OBJECTDIR}/src/pbiw_encoder.o \
	${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o \
	${OBJECTDIR}/src/rVex/SyllableCTRL.o \
	${OBJECTDIR}/src/VexParser/Expressions/Expression.o \
	${OBJECTDIR}/src/rVex/Syllable.o \
	${OBJECTDIR}/src/VexParser/driver.o \
	${OBJECTDIR}/src/rVex/SyllableMEM.o \
	${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o \
	${OBJECTDIR}/src/VexParser/parser.tab.o \
	${OBJECTDIR}/src/rVex/Instruction.o

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

${OBJECTDIR}/src/PBIW/PBIW.o: src/PBIW/PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIW.o src/PBIW/PBIW.cpp

${OBJECTDIR}/src/rVex/SyllableMUL.o: src/rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMUL.o src/rVex/SyllableMUL.cpp

${OBJECTDIR}/src/VexParser/scanner.o: src/VexParser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/scanner.o src/VexParser/scanner.cc

${OBJECTDIR}/src/rVex/SyllableALU.o: src/rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableALU.o src/rVex/SyllableALU.cpp

${OBJECTDIR}/src/VexParser/VexContext.o: src/VexParser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/VexContext.o src/VexParser/VexContext.cpp

${OBJECTDIR}/src/pbiw_encoder.o: src/pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pbiw_encoder.o src/pbiw_encoder.cpp

${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o: src/PBIW/rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o src/PBIW/rVex64PBIWInstruction.cpp

${OBJECTDIR}/src/rVex/SyllableCTRL.o: src/rVex/SyllableCTRL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableCTRL.o src/rVex/SyllableCTRL.cpp

${OBJECTDIR}/src/VexParser/Expressions/Expression.o: src/VexParser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser/Expressions
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/Expressions/Expression.o src/VexParser/Expressions/Expression.cpp

${OBJECTDIR}/src/rVex/Syllable.o: src/rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Syllable.o src/rVex/Syllable.cpp

${OBJECTDIR}/src/VexParser/driver.o: src/VexParser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/driver.o src/VexParser/driver.cc

${OBJECTDIR}/src/rVex/SyllableMEM.o: src/rVex/SyllableMEM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMEM.o src/rVex/SyllableMEM.cpp

${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o: src/PBIW/rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o src/PBIW/rVex96PBIWPattern.cpp

${OBJECTDIR}/src/VexParser/parser.tab.o: src/VexParser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/parser.tab.o src/VexParser/parser.tab.cc

${OBJECTDIR}/src/rVex/Instruction.o: src/rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Instruction.o src/rVex/Instruction.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/src/Tests/Parser/VexContextTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lgtest 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/src/Tests/rVex/rVexInstrucionMulTest.o ${TESTDIR}/src/Tests/rVex/rVexInstructionTest.o ${TESTDIR}/src/Tests/rVex/rVexSyllableMulTest.o ${TESTDIR}/src/Tests/rVex/rVexSyllableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lgtest 


${TESTDIR}/src/Tests/Parser/VexContextTest.o: src/Tests/Parser/VexContextTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/Parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/Parser/VexContextTest.o src/Tests/Parser/VexContextTest.cpp


${TESTDIR}/src/Tests/rVex/rVexInstrucionMulTest.o: src/Tests/rVex/rVexInstrucionMulTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/rVex/rVexInstrucionMulTest.o src/Tests/rVex/rVexInstrucionMulTest.cpp


${TESTDIR}/src/Tests/rVex/rVexInstructionTest.o: src/Tests/rVex/rVexInstructionTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/rVex/rVexInstructionTest.o src/Tests/rVex/rVexInstructionTest.cpp


${TESTDIR}/src/Tests/rVex/rVexSyllableMulTest.o: src/Tests/rVex/rVexSyllableMulTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/rVex/rVexSyllableMulTest.o src/Tests/rVex/rVexSyllableMulTest.cpp


${TESTDIR}/src/Tests/rVex/rVexSyllableTest.o: src/Tests/rVex/rVexSyllableTest.cpp 
	${MKDIR} -p ${TESTDIR}/src/Tests/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/src/Tests/rVex/rVexSyllableTest.o src/Tests/rVex/rVexSyllableTest.cpp


${OBJECTDIR}/src/PBIW/PBIW_nomain.o: ${OBJECTDIR}/src/PBIW/PBIW.o src/PBIW/PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/PBIW
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/PBIW/PBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/PBIW_nomain.o src/PBIW/PBIW.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMUL_nomain.o src/rVex/SyllableMUL.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/scanner_nomain.o src/VexParser/scanner.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/scanner.o ${OBJECTDIR}/src/VexParser/scanner_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableALU_nomain.o: ${OBJECTDIR}/src/rVex/SyllableALU.o src/rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableALU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableALU_nomain.o src/rVex/SyllableALU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableALU.o ${OBJECTDIR}/src/rVex/SyllableALU_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/VexContext_nomain.o: ${OBJECTDIR}/src/VexParser/VexContext.o src/VexParser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/VexContext.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/VexContext_nomain.o src/VexParser/VexContext.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/VexContext.o ${OBJECTDIR}/src/VexParser/VexContext_nomain.o;\
	fi

${OBJECTDIR}/src/pbiw_encoder_nomain.o: ${OBJECTDIR}/src/pbiw_encoder.o src/pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/pbiw_encoder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pbiw_encoder_nomain.o src/pbiw_encoder.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction_nomain.o src/PBIW/rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction.o ${OBJECTDIR}/src/PBIW/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o: ${OBJECTDIR}/src/rVex/SyllableCTRL.o src/rVex/SyllableCTRL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/SyllableCTRL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o src/rVex/SyllableCTRL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/SyllableCTRL.o ${OBJECTDIR}/src/rVex/SyllableCTRL_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/Expressions/Expression_nomain.o: ${OBJECTDIR}/src/VexParser/Expressions/Expression.o src/VexParser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/Expressions/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/Expressions/Expression_nomain.o src/VexParser/Expressions/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/VexParser/Expressions/Expression.o ${OBJECTDIR}/src/VexParser/Expressions/Expression_nomain.o;\
	fi

${OBJECTDIR}/src/rVex/Syllable_nomain.o: ${OBJECTDIR}/src/rVex/Syllable.o src/rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/rVex/Syllable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Syllable_nomain.o src/rVex/Syllable.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/driver_nomain.o src/VexParser/driver.cc;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/SyllableMEM_nomain.o src/rVex/SyllableMEM.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern_nomain.o src/PBIW/rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern.o ${OBJECTDIR}/src/PBIW/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/src/VexParser/parser.tab_nomain.o: ${OBJECTDIR}/src/VexParser/parser.tab.o src/VexParser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/src/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/VexParser/parser.tab.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VexParser/parser.tab_nomain.o src/VexParser/parser.tab.cc;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/rVex/Instruction_nomain.o src/rVex/Instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/rVex/Instruction.o ${OBJECTDIR}/src/rVex/Instruction_nomain.o;\
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
