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
	${OBJECTDIR}/new_grammar/parser.tab.o \
	${OBJECTDIR}/rVex64PBIWInstruction.o \
	${OBJECTDIR}/new_grammar/VexContext.o \
	${OBJECTDIR}/new_grammar/scanner.o \
	${OBJECTDIR}/pbiw_encoder.o \
	${OBJECTDIR}/new_grammar/Expressions/Expression.o \
	${OBJECTDIR}/new_grammar/driver.o \
	${OBJECTDIR}/rVex/Instruction.o \
	${OBJECTDIR}/rVex/SyllableALU.o \
	${OBJECTDIR}/rVex/SyllableMUL.o \
	${OBJECTDIR}/rVex96PBIWPattern.o \
	${OBJECTDIR}/rVex/Syllable.o \
	${OBJECTDIR}/PBIW.o \
	${OBJECTDIR}/rVex/Operands/Expression.o

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/new_grammar/parser.tab.o: new_grammar/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/parser.tab.o new_grammar/parser.tab.cc

${OBJECTDIR}/rVex64PBIWInstruction.o: rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp

${OBJECTDIR}/new_grammar/VexContext.o: new_grammar/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/VexContext.o new_grammar/VexContext.cpp

${OBJECTDIR}/new_grammar/scanner.o: new_grammar/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/scanner.o new_grammar/scanner.cc

${OBJECTDIR}/pbiw_encoder.o: pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder.o pbiw_encoder.cpp

${OBJECTDIR}/new_grammar/Expressions/Expression.o: new_grammar/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/new_grammar/Expressions
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/Expressions/Expression.o new_grammar/Expressions/Expression.cpp

${OBJECTDIR}/new_grammar/driver.o: new_grammar/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/driver.o new_grammar/driver.cc

${OBJECTDIR}/rVex/Instruction.o: rVex/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Instruction.o rVex/Instruction.cpp

${OBJECTDIR}/rVex/SyllableALU.o: rVex/SyllableALU.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableALU.o rVex/SyllableALU.cpp

${OBJECTDIR}/rVex/SyllableMUL.o: rVex/SyllableMUL.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableMUL.o rVex/SyllableMUL.cpp

${OBJECTDIR}/rVex96PBIWPattern.o: rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp

${OBJECTDIR}/rVex/Syllable.o: rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Syllable.o rVex/Syllable.cpp

${OBJECTDIR}/PBIW.o: PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW.o PBIW.cpp

${OBJECTDIR}/rVex/Operands/Expression.o: rVex/Operands/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex/Operands
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Operands/Expression.o rVex/Operands/Expression.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/VexContextTest.o ${TESTDIR}/tests/rVexInstrucionMulTest.o ${TESTDIR}/tests/rVexInstructionTest.o ${TESTDIR}/tests/rVexSyllableMulTest.o ${TESTDIR}/tests/rVexSyllableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lgtest 


${TESTDIR}/tests/VexContextTest.o: tests/VexContextTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/VexContextTest.o tests/VexContextTest.cpp


${TESTDIR}/tests/rVexInstrucionMulTest.o: tests/rVexInstrucionMulTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexInstrucionMulTest.o tests/rVexInstrucionMulTest.cpp


${TESTDIR}/tests/rVexInstructionTest.o: tests/rVexInstructionTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexInstructionTest.o tests/rVexInstructionTest.cpp


${TESTDIR}/tests/rVexSyllableMulTest.o: tests/rVexSyllableMulTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexSyllableMulTest.o tests/rVexSyllableMulTest.cpp


${TESTDIR}/tests/rVexSyllableTest.o: tests/rVexSyllableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -s -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/rVexSyllableTest.o tests/rVexSyllableTest.cpp


${OBJECTDIR}/new_grammar/parser.tab_nomain.o: ${OBJECTDIR}/new_grammar/parser.tab.o new_grammar/parser.tab.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/parser.tab.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/parser.tab_nomain.o new_grammar/parser.tab.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/new_grammar/parser.tab.o ${OBJECTDIR}/new_grammar/parser.tab_nomain.o;\
	fi

${OBJECTDIR}/rVex64PBIWInstruction_nomain.o: ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex64PBIWInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction_nomain.o rVex64PBIWInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex64PBIWInstruction.o ${OBJECTDIR}/rVex64PBIWInstruction_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/VexContext_nomain.o: ${OBJECTDIR}/new_grammar/VexContext.o new_grammar/VexContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/VexContext.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/VexContext_nomain.o new_grammar/VexContext.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/new_grammar/VexContext.o ${OBJECTDIR}/new_grammar/VexContext_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/scanner_nomain.o: ${OBJECTDIR}/new_grammar/scanner.o new_grammar/scanner.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/scanner_nomain.o new_grammar/scanner.cc;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder_nomain.o pbiw_encoder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/pbiw_encoder.o ${OBJECTDIR}/pbiw_encoder_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/Expressions/Expression_nomain.o: ${OBJECTDIR}/new_grammar/Expressions/Expression.o new_grammar/Expressions/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/new_grammar/Expressions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/Expressions/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/Expressions/Expression_nomain.o new_grammar/Expressions/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/new_grammar/Expressions/Expression.o ${OBJECTDIR}/new_grammar/Expressions/Expression_nomain.o;\
	fi

${OBJECTDIR}/new_grammar/driver_nomain.o: ${OBJECTDIR}/new_grammar/driver.o new_grammar/driver.cc 
	${MKDIR} -p ${OBJECTDIR}/new_grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/new_grammar/driver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/new_grammar/driver_nomain.o new_grammar/driver.cc;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Instruction_nomain.o rVex/Instruction.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableALU_nomain.o rVex/SyllableALU.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/SyllableMUL_nomain.o rVex/SyllableMUL.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/SyllableMUL.o ${OBJECTDIR}/rVex/SyllableMUL_nomain.o;\
	fi

${OBJECTDIR}/rVex96PBIWPattern_nomain.o: ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex96PBIWPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern_nomain.o rVex96PBIWPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex96PBIWPattern.o ${OBJECTDIR}/rVex96PBIWPattern_nomain.o;\
	fi

${OBJECTDIR}/rVex/Syllable_nomain.o: ${OBJECTDIR}/rVex/Syllable.o rVex/Syllable.cpp 
	${MKDIR} -p ${OBJECTDIR}/rVex
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVex/Syllable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Syllable_nomain.o rVex/Syllable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Syllable.o ${OBJECTDIR}/rVex/Syllable_nomain.o;\
	fi

${OBJECTDIR}/PBIW_nomain.o: ${OBJECTDIR}/PBIW.o PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PBIW.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW_nomain.o PBIW.cpp;\
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
	    $(COMPILE.cc) -O2 -s -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex/Operands/Expression_nomain.o rVex/Operands/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVex/Operands/Expression.o ${OBJECTDIR}/rVex/Operands/Expression_nomain.o;\
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
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pbiw_encoder

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
