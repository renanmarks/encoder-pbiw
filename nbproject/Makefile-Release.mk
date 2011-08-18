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
	${OBJECTDIR}/grammar/lex.o \
	${OBJECTDIR}/pbiw_encoder.o \
	${OBJECTDIR}/rVex96PBIWPattern.o \
	${OBJECTDIR}/rVexSyllable.o \
	${OBJECTDIR}/rVexInstruction.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f4

${TESTDIR}/TestFiles/f4: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/grammar/grammar.o: grammar/grammar.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/grammar.o grammar/grammar.c

${OBJECTDIR}/rVex64PBIWInstruction.o: rVex64PBIWInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex64PBIWInstruction.o rVex64PBIWInstruction.cpp

${OBJECTDIR}/grammar/lex.o: grammar/lex.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/lex.o grammar/lex.c

${OBJECTDIR}/pbiw_encoder.o: pbiw_encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/pbiw_encoder.o pbiw_encoder.cpp

${OBJECTDIR}/rVex96PBIWPattern.o: rVex96PBIWPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVex96PBIWPattern.o rVex96PBIWPattern.cpp

${OBJECTDIR}/rVexSyllable.o: rVexSyllable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVexSyllable.o rVexSyllable.cpp

${OBJECTDIR}/rVexInstruction.o: rVexInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVexInstruction.o rVexInstruction.cpp

${OBJECTDIR}/PBIW.o: PBIW.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/PBIW.o PBIW.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/rVexSyllableTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lgtest 


${TESTDIR}/rVexSyllableTest.o: rVexSyllableTest.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/rVexSyllableTest.o rVexSyllableTest.cpp


${OBJECTDIR}/grammar/grammar_nomain.o: ${OBJECTDIR}/grammar/grammar.o grammar/grammar.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/grammar/grammar.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/grammar_nomain.o grammar/grammar.c;\
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

${OBJECTDIR}/grammar/lex_nomain.o: ${OBJECTDIR}/grammar/lex.o grammar/lex.c 
	${MKDIR} -p ${OBJECTDIR}/grammar
	@NMOUTPUT=`${NM} ${OBJECTDIR}/grammar/lex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/grammar/lex_nomain.o grammar/lex.c;\
	else  \
	    ${CP} ${OBJECTDIR}/grammar/lex.o ${OBJECTDIR}/grammar/lex_nomain.o;\
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

${OBJECTDIR}/rVexSyllable_nomain.o: ${OBJECTDIR}/rVexSyllable.o rVexSyllable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVexSyllable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVexSyllable_nomain.o rVexSyllable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVexSyllable.o ${OBJECTDIR}/rVexSyllable_nomain.o;\
	fi

${OBJECTDIR}/rVexInstruction_nomain.o: ${OBJECTDIR}/rVexInstruction.o rVexInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rVexInstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/rVexInstruction_nomain.o rVexInstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/rVexInstruction.o ${OBJECTDIR}/rVexInstruction_nomain.o;\
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
