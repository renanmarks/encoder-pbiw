 
set(
	RVEX_SRC

	Encoder/rVexEncoder
	Base/Instruction
	Base/Label
	Base/Operand
	Base/Syllable
	Base/SyllableALU
	Base/SyllableCTRL
	Base/SyllableMEM
	Base/SyllableMISC
	Base/SyllableMUL
	Operations/ALU/ADDCG
	Operations/ALU/CMPEQ
	Operations/ALU/CMPGE
	Operations/ALU/CMPGEU
	Operations/ALU/CMPGT
	Operations/ALU/CMPGTU
	Operations/ALU/CMPLE
	Operations/ALU/CMPLEU
	Operations/ALU/CMPLT
	Operations/ALU/CMPLTU
	Operations/ALU/CMPNE
	Operations/ALU/DIVS
	Operations/ALU/MTB
	Operations/ALU/SLCT
	Operations/ALU/SLCTF
	Operations/CTRL/BR
	Operations/CTRL/BRF
	Operations/CTRL/CALL
	Operations/CTRL/GOTO
	Operations/CTRL/ICALL
	Operations/CTRL/IGOTO
	Operations/CTRL/RETURN
	Operations/CTRL/RFI
	Operations/MEM/LDB
	Operations/MEM/LDBU
	Operations/MEM/LDH
	Operations/MEM/LDHU
	Operations/MEM/LDW
	Operations/MEM/STB
	Operations/MEM/STH
	Operations/MEM/STW
	Parser/Expressions/Arguments
	Parser/Expressions/Expression
	Parser/Processors/PseudoSyllableProcessor
	Parser/Processors/SyllablePacker
	Parser/Structs/Function
	Parser/Structs/ISection
	Parser/Structs/SyllableBufferItem
	Parser/VexContext
	Parser/driver
	Parser/parser.tab
	Parser/scanner
	PBIWFull/Factory
	PBIWFull/FullPBIW
	PBIWFull/Operand
	PBIWFull/Operation
	PBIWFull/Printers/FullPBIWDebugPrinter
	PBIWFull/Printers/FullPBIWPrinter
	PBIWFull/rVex64PBIWInstruction
	PBIWFull/rVex96PBIWPattern
	PBIWPartial/Factory
	PBIWPartial/Operand
	PBIWPartial/Operation
	PBIWPartial/PartialPBIW
	PBIWPartial/Printers/PartialPBIWDebugPrinter
	PBIWPartial/Printers/PartialPBIWPrinter
	PBIWPartial/rVex64PBIWInstruction
	PBIWPartial/rVex96PBIWPattern
	Printers/DineroTool/AssemblyPrinter
	Printers/DineroTool/PBIWPrinter
	Printers/rVexPrinter
	Printers/VHDLPrinter
	Utils/DependencyChains
	Utils/OperandVectorBuilder
)

add_library(RVEX_MODULE STATIC ${RVEX_SRC})
target_link_libraries(RVEX_MODULE PBIW_MODULE)	# Como linkar
