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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/rVex64PBIWInstruction.o \
	${OBJECTDIR}/VexParser/parser.tab.o \
	${OBJECTDIR}/pbiw_encoder.o \
	${OBJECTDIR}/VexParser/Expressions/Expression.o \
	${OBJECTDIR}/rVex/Instruction.o \
	${OBJECTDIR}/rVex/SyllableALU.o \
	${OBJECTDIR}/rVex/SyllableMUL.o \
	${OBJECTDIR}/VexParser/scanner.o \
	${OBJECTDIR}/rVex96PBIWPattern.o \
	${OBJECTDIR}/VexParser/driver.o \
	${OBJECTDIR}/rVex/Syllable.o \
	${OBJECTDIR}/VexParser/VexContext.o \
	${OBJECTDIR}/PBIW.o \
	${OBJECTDIR}/rVex/Operands/Expression.o

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
LDLIBSOPTIONS=-L/usr/local/lib/gtest -lgtest -lgtest_main

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/rVex64PBIWInstruction.o: rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp

${OBJECTDIR}/VexParser/parser.tab.o: VexParser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/parser.tab.o VexParser/parser.tab.cc

${OBJECTDIR}/pbiw_encoder.o: pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder.o pbiw_encoder.cpp

${OBJECTDIR}/VexParser/Expressions/Expression.o: VexParser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/VexParser/Expressions
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/Expressions/Expression.o VexParser/Expressions/Expression.cpp

${OBJECTDIR}/rVex/Instruction.o: rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Instruction.o rVex/Instruction.cpp

${OBJECTDIR}/rVex/SyllableALU.o: rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableALU.o rVex/SyllableALU.cpp

${OBJECTDIR}/rVex/SyllableMUL.o: rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableMUL.o rVex/SyllableMUL.cpp

${OBJECTDIR}/VexParser/scanner.o: VexParser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/scanner.o VexParser/scanner.cc

${OBJECTDIR}/rVex96PBIWPattern.o: rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp

${OBJECTDIR}/VexParser/driver.o: VexParser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/driver.o VexParser/driver.cc

${OBJECTDIR}/rVex/Syllable.o: rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Syllable.o rVex/Syllable.cpp

${OBJECTDIR}/VexParser/VexContext.o: VexParser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/VexContext.o VexParser/VexContext.cpp

${OBJECTDIR}/PBIW.o: PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW.o PBIW.cpp

${OBJECTDIR}/rVex/Operands/Expression.o: rVex/Operands/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex/Operands
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Operands/Expression.o rVex/Operands/Expression.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/VexContextTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/rVexInstrucionMulTest.o ${TESTDIR}/tests/rVexInstructionTest.o ${TESTDIR}/tests/rVexSyllableMulTest.o ${TESTDIR}/tests/rVexSyllableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/VexContextTest.o: tests/VexContextTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/VexContextTest.o tests/VexContextTest.cpp


${TESTDIR}/tests/rVexInstrucionMulTest.o: tests/rVexInstrucionMulTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexInstrucionMulTest.o tests/rVexInstrucionMulTest.cpp


${TESTDIR}/tests/rVexInstructionTest.o: tests/rVexInstructionTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexInstructionTest.o tests/rVexInstructionTest.cpp


${TESTDIR}/tests/rVexSyllableMulTest.o: tests/rVexSyllableMulTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexSyllableMulTest.o tests/rVexSyllableMulTest.cpp


${TESTDIR}/tests/rVexSyllableTest.o: tests/rVexSyllableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexSyllableTest.o tests/rVexSyllableTest.cpp


${OBJECTDIR}/rVex64PBIWInstruction_nomain.o: ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex64PBIWInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction_nomain.o rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex64PBIWInstruction.o ${OBJECTDIR}/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/VexParser/parser.tab_nomain.o: ${OBJECTDIR}/VexParser/parser.tab.o VexParser/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VexParser/parser.tab.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/parser.tab_nomain.o VexParser/parser.tab.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/VexParser/parser.tab.o ${OBJECTDIR}/VexParser/parser.tab_nomain.o;\
	fi

${OBJECTDIR}/pbiw_encoder_nomain.o: ${OBJECTDIR}/pbiw_encoder.o pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/pbiw_encoder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder_nomain.o pbiw_encoder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/pbiw_encoder.o ${OBJECTDIR}/pbiw_encoder_nomain.o;\
	fi

${OBJECTDIR}/VexParser/Expressions/Expression_nomain.o: ${OBJECTDIR}/VexParser/Expressions/Expression.o VexParser/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/VexParser/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VexParser/Expressions/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/Expressions/Expression_nomain.o VexParser/Expressions/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/VexParser/Expressions/Expression.o ${OBJECTDIR}/VexParser/Expressions/Expression_nomain.o;\
	fi

${OBJECTDIR}/rVex/Instruction_nomain.o: ${OBJECTDIR}/rVex/Instruction.o rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/Instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Instruction_nomain.o rVex/Instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Instruction.o ${OBJECTDIR}/rVex/Instruction_nomain.o;\
	fi

${OBJECTDIR}/rVex/SyllableALU_nomain.o: ${OBJECTDIR}/rVex/SyllableALU.o rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/SyllableALU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableALU_nomain.o rVex/SyllableALU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/SyllableALU.o ${OBJECTDIR}/rVex/SyllableALU_nomain.o;\
	fi

${OBJECTDIR}/rVex/SyllableMUL_nomain.o: ${OBJECTDIR}/rVex/SyllableMUL.o rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/SyllableMUL.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableMUL_nomain.o rVex/SyllableMUL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/SyllableMUL.o ${OBJECTDIR}/rVex/SyllableMUL_nomain.o;\
	fi

${OBJECTDIR}/VexParser/scanner_nomain.o: ${OBJECTDIR}/VexParser/scanner.o VexParser/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VexParser/scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/scanner_nomain.o VexParser/scanner.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/VexParser/scanner.o ${OBJECTDIR}/VexParser/scanner_nomain.o;\
	fi

${OBJECTDIR}/rVex96PBIWPattern_nomain.o: ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex96PBIWPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern_nomain.o rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex96PBIWPattern.o ${OBJECTDIR}/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/VexParser/driver_nomain.o: ${OBJECTDIR}/VexParser/driver.o VexParser/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VexParser/driver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/driver_nomain.o VexParser/driver.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/VexParser/driver.o ${OBJECTDIR}/VexParser/driver_nomain.o;\
	fi

${OBJECTDIR}/rVex/Syllable_nomain.o: ${OBJECTDIR}/rVex/Syllable.o rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/Syllable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Syllable_nomain.o rVex/Syllable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Syllable.o ${OBJECTDIR}/rVex/Syllable_nomain.o;\
	fi

${OBJECTDIR}/VexParser/VexContext_nomain.o: ${OBJECTDIR}/VexParser/VexContext.o VexParser/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/VexParser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VexParser/VexContext.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/VexParser/VexContext_nomain.o VexParser/VexContext.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/VexParser/VexContext.o ${OBJECTDIR}/VexParser/VexContext_nomain.o;\
	fi

${OBJECTDIR}/PBIW_nomain.o: ${OBJECTDIR}/PBIW.o PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW_nomain.o PBIW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PBIW.o ${OBJECTDIR}/PBIW_nomain.o;\
	fi

${OBJECTDIR}/rVex/Operands/Expression_nomain.o: ${OBJECTDIR}/rVex/Operands/Expression.o rVex/Operands/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex/Operands
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/Operands/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Operands/Expression_nomain.o rVex/Operands/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Operands/Expression.o ${OBJECTDIR}/rVex/Operands/Expression_nomain.o;\
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
