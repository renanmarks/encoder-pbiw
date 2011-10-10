#include <memory>

#include "gtest/gtest.h"
#include "../../rVex/rVex.h"
#include "../../VexParser/Expressions/Expression.h"
#include "../../VexParser/VexContext.h"
#include "VexParser/VexTypes.h"

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
    
    Operations::ALU::ADD* addOp = new Operations::ALU::ADD();     // Op = 65
    Operations::MEM::LDB* ldbOp = new Operations::MEM::LDB();     // Op = 20
    Operations::ALU::SUB* subOp = new Operations::ALU::SUB();     // Op = 82
//    Operations::CTRL::BR* brOp = new Operations::CTRL::BR();
    Operations::MUL::MPYL* mpylOp = new Operations::MUL::MPYL();  // Op = 7
    
    
    Expression r0("$r0.0");
    Expression r1("$r0.1");
    Expression r2("$r0.2");
    
    Arguments destiny(&r1);
    Arguments source(&r0);
    source.addArgument(&r2);
    
    SyllableArguments sArguments(&destiny, &source);
    
    addOp->fillSyllable(&sArguments);
    ldbOp->fillSyllable(&sArguments);
    subOp->fillSyllable(&sArguments);
//    brOp->fillSyllable(&sArguments);
    mpylOp->fillSyllable(&sArguments);
    // fillsyllable do ldb seguindo os argumentos que pede
    // ex: ldb $r0.d = imm[$r0.s1]
    
    
    
    Instruction* instruction = new Instruction();

    if(instruction->addSyllable(*addOp))
        std::cout << "Passou" << std::endl;

    if(instruction->addSyllable(*ldbOp))
        std::cout << "Passou" << std::endl;
    
    if(instruction->addSyllable(*subOp))
        std::cout << "Passou" << std::endl;
    
//    if(instruction->addSyllable(*brOp))
//        std::cout << "Passou" << std::endl;
    
    if(instruction->addSyllable(*mpylOp))
        std::cout << "Passou" << std::endl;
    
    VexContext* context = new VexContext();
    
    context->packSyllable(addOp, &sArguments);
    context->packSyllable(ldbOp, &sArguments);
    context->packSyllable(subOp, &sArguments);
//    context->packSyllable(brOp, &sArguments);
    context->packSyllable(mpylOp, &sArguments);
    
    // pack
    // pack
    // pack
    context->endInstruction();
    
    context->reorder(instruction);
    
    instruction->print();
    
    context->getInstruction(0).print();
    context->getInstruction(1).print();
    context->getInstruction(2).print();
    context->getInstruction(3).print();
  }
}
