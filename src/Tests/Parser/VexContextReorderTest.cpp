#include <memory>

#include "gtest/gtest.h"
#include "../../rVex/rVex.h"
#include "../../VexParser/Expressions/Expression.h"
#include "../../VexParser/VexContext.h"

namespace VexContextReorderTest
{
  using namespace VexParser;
  using namespace rVex;
  
  TEST( VexContextReorderTest, reorder )
  {
    // Se no final do teste ou no meio der erros bizarros de memória do tipo
    // "double deallocation", reinstancie todas as classes no HEAP;
    // EX:
    // Operations::ALU::ADD* addOp = new Operations::ALU::ADD();
    
    Operations::ALU::ADD addOp;
    Operations::MEM::LDB ldbOp;
    
    Expression r0("$r0.0");
    Expression r1("$r0.1");
    Expression r2("$r0.2");
    
    Arguments destiny(&r1);
    Arguments source(&r0);
    source.addArgument(&r2);
    
    SyllableArguments sArguments(&destiny, &source);
    
    addOp.fillSyllable(&sArguments);
    // fillsyllable do ldb seguindo os argumentos que pede
    // ex: ldb $r0.d = imm[$r0.s1]
    
    Instruction instruction;
    
    instruction.addSyllable(addOp);
    instruction.addSyllable(ldbOp);
    
    VexContext context;
    
    context.packSyllable(&addOp, &sArguments);
    // pack
    // pack
    // pack
    context.endInstruction();
    
    //context.getInstruction(0).
  }
}
