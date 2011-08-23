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
	${OBJECTDIR}/grammar/grammar.o \
	${OBJECTDIR}/rVex64PBIWInstruction.o \
	${OBJECTDIR}/rVex/Operations/ALU/ADD.o \
	${OBJECTDIR}/grammar/lex.o \
	${OBJECTDIR}/new_grammar/parser.o \
	${OBJECTDIR}/new_grammar/scanner.o \
	${OBJECTDIR}/pbiw_encoder.o \
	${OBJECTDIR}/new_grammar/driver.o \
	${OBJECTDIR}/rVex/Instruction.o \
	${OBJECTDIR}/rVex96PBIWPattern.o \
	${OBJECTDIR}/PBIW.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
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
LDLIBSOPTIONS=-Lgtest/lib gtest/lib/libgtest.so gtest/lib/libgtest_dll.so gtest/lib/libgtest_main.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f4

${TESTDIR}/TestFiles/f4: gtest/lib/libgtest.so

${TESTDIR}/TestFiles/f4: gtest/lib/libgtest_dll.so

${TESTDIR}/TestFiles/f4: gtest/lib/libgtest_main.so

${TESTDIR}/TestFiles/f4: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/grammar/grammar.o: grammar/grammar.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/grammar.o grammar/grammar.c

${OBJECTDIR}/rVex64PBIWInstruction.o: rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp

${OBJECTDIR}/rVex/Operations/ALU/ADD.o: rVex/Operations/ALU/ADD.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex/Operations/ALU
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Operations/ALU/ADD.o rVex/Operations/ALU/ADD.cpp

${OBJECTDIR}/grammar/lex.o: grammar/lex.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/lex.o grammar/lex.c

${OBJECTDIR}/new_grammar/parser.o: new_grammar/parser.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/parser.o new_grammar/parser.cc

${OBJECTDIR}/new_grammar/scanner.o: new_grammar/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/scanner.o new_grammar/scanner.cc

${OBJECTDIR}/pbiw_encoder.o: pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder.o pbiw_encoder.cpp

${OBJECTDIR}/new_grammar/driver.o: new_grammar/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/driver.o new_grammar/driver.cc

${OBJECTDIR}/rVex/Instruction.o: rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Instruction.o rVex/Instruction.cpp

${OBJECTDIR}/rVex96PBIWPattern.o: rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp

${OBJECTDIR}/PBIW.o: PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW.o PBIW.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/rVexInstructionTest.o ${TESTDIR}/tests/rVexSyllableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lgtest 


${TESTDIR}/tests/rVexInstructionTest.o: tests/rVexInstructionTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexInstructionTest.o tests/rVexInstructionTest.cpp


${TESTDIR}/tests/rVexSyllableTest.o: tests/rVexSyllableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexSyllableTest.o tests/rVexSyllableTest.cpp


${OBJECTDIR}/grammar/grammar_nomain.o: ${OBJECTDIR}/grammar/grammar.o grammar/grammar.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/grammar/grammar.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/grammar_nomain.o grammar/grammar.c;\
	else  \
	    ${CP} ${OBJECTDIR}/grammar/grammar.o ${OBJECTDIR}/grammar/grammar_nomain.o;\
	fi

${OBJECTDIR}/rVex64PBIWInstruction_nomain.o: ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex64PBIWInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction_nomain.o rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex64PBIWInstruction.o ${OBJECTDIR}/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/rVex/Operations/ALU/ADD_nomain.o: ${OBJECTDIR}/rVex/Operations/ALU/ADD.o rVex/Operations/ALU/ADD.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex/Operations/ALU
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/Operations/ALU/ADD.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Operations/ALU/ADD_nomain.o rVex/Operations/ALU/ADD.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Operations/ALU/ADD.o ${OBJECTDIR}/rVex/Operations/ALU/ADD_nomain.o;\
	fi

${OBJECTDIR}/grammar/lex_nomain.o: ${OBJECTDIR}/grammar/lex.o grammar/lex.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/grammar/lex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/lex_nomain.o grammar/lex.c;\
	else  \
	    ${CP} ${OBJECTDIR}/grammar/lex.o ${OBJECTDIR}/grammar/lex_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/parser_nomain.o: ${OBJECTDIR}/new_grammar/parser.o new_grammar/parser.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/parser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/parser_nomain.o new_grammar/parser.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/new_grammar/parser.o ${OBJECTDIR}/new_grammar/parser_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/scanner_nomain.o: ${OBJECTDIR}/new_grammar/scanner.o new_grammar/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/scanner_nomain.o new_grammar/scanner.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/new_grammar/scanner.o ${OBJECTDIR}/new_grammar/scanner_nomain.o;\
	fi

${OBJECTDIR}/pbiw_encoder_nomain.o: ${OBJECTDIR}/pbiw_encoder.o pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/pbiw_encoder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder_nomain.o pbiw_encoder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/pbiw_encoder.o ${OBJECTDIR}/pbiw_encoder_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/driver_nomain.o: ${OBJECTDIR}/new_grammar/driver.o new_grammar/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/driver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/driver_nomain.o new_grammar/driver.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/new_grammar/driver.o ${OBJECTDIR}/new_grammar/driver_nomain.o;\
	fi

${OBJECTDIR}/rVex/Instruction_nomain.o: ${OBJECTDIR}/rVex/Instruction.o rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/Instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Instruction_nomain.o rVex/Instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Instruction.o ${OBJECTDIR}/rVex/Instruction_nomain.o;\
	fi

${OBJECTDIR}/rVex96PBIWPattern_nomain.o: ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex96PBIWPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern_nomain.o rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex96PBIWPattern.o ${OBJECTDIR}/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/PBIW_nomain.o: ${OBJECTDIR}/PBIW.o PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW_nomain.o PBIW.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PBIW.o ${OBJECTDIR}/PBIW_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f4

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
