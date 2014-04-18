
set(
	PBIW_SRC

	BaseOptimizer
	PBIWOptimizerDataSet
	PBIWOptimizerJoinPatterns
	Generic/Codec
	Generic/Configuration
	Generic/Factory
	Generic/Instruction
	Generic/Label
	Generic/Operand
	Generic/Operation
	Generic/Pattern
	Generic/Printer
	Optimizers/JoinPattern/OperationInformation
	Optimizers/JoinPattern/PatternBuilder
	Optimizers/JoinPattern/PatternInformation
	Utils/OperandVector
	Utils/OperandVectorDTO
)

add_library(PBIW_MODULE STATIC ${PBIW_SRC})
