#include "gtest/gtest.h"
#include "src/rVex/rVex.h"

using namespace std;
using namespace rVex;

namespace SyllableTest
{
  TEST(SyllableTest, PrintBinaryADD)      // Test 1
  {
    rVex::Operations::ALU::ADD ADDR;

    ADDR.setGrDestiny(1);
    ADDR.addReadRegister(10);
    ADDR.addReadRegister(63);

    ASSERT_EQ(0x820257E0, ADDR.printRTYPE());

    rVex::Operations::ALU::ADD ADDIS;

    ADDIS.setGrDestiny(1);
    ADDIS.addReadRegister(10);
    ADDIS.setShortImmediate(255);

    ASSERT_EQ(0x828253FC, ADDIS.printISTYPE());
  }

  TEST(SyllableTest, PrintBinaryAND)      // Test 2
  {
    rVex::Operations::ALU::AND ANDR;

    ANDR.addReadRegister(10);
    ANDR.addReadRegister(63);
    ANDR.setGrDestiny(1);

    ASSERT_EQ(0x860257E0, ANDR.printRTYPE());

    rVex::Operations::ALU::AND ANDIS;

    ANDIS.setGrDestiny(1);
    ANDIS.addReadRegister(10);
    ANDIS.setShortImmediate(255);

    ASSERT_EQ(0x868253FC, ANDIS.printISTYPE());
  }
  
TEST(SyllableTest, PrintBinaryANDC)     // Test 3
{
  rVex::Operations::ALU::ANDC ANDC;
  
  ANDC.addReadRegister(10);
  ANDC.addReadRegister(63);
  ANDC.setGrDestiny(1);
  
  ASSERT_EQ(0x880257E0, ANDC.printRTYPE());
  
  rVex::Operations::ALU::ANDC ANDCIS;

  ANDCIS.setGrDestiny(1);
  ANDCIS.addReadRegister(10);
  ANDCIS.setShortImmediate(255);
  
  ASSERT_EQ(0x888253FC, ANDCIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryMAX)      // Test 4
{
  rVex::Operations::ALU::MAX MAXR;
  
  MAXR.addReadRegister(10);
  MAXR.addReadRegister(63);
  MAXR.setGrDestiny(1);
  
  ASSERT_EQ(0x8A0257E0, MAXR.printRTYPE());
  
  rVex::Operations::ALU::MAX MAXIS;
  
  MAXIS.setGrDestiny(1);
  MAXIS.addReadRegister(10);
  MAXIS.setShortImmediate(255);
  
  ASSERT_EQ(0x8A8253FC, MAXIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryMAXU)      // Test 5
{
  rVex::Operations::ALU::MAXU MAXUR;
  
  MAXUR.addReadRegister(10);
  MAXUR.addReadRegister(63);
  MAXUR.setGrDestiny(1);
  
  ASSERT_EQ(0x8C0257E0, MAXUR.printRTYPE());
  
  rVex::Operations::ALU::MAXU MAXUIS;
  
  MAXUIS.setGrDestiny(1);
  MAXUIS.addReadRegister(10);
  MAXUIS.setShortImmediate(255);
  
  ASSERT_EQ(0x8C8253FC, MAXUIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryMIN)      // Test 6
{
  rVex::Operations::ALU::MIN MINR;
  
  MINR.addReadRegister(10);
  MINR.addReadRegister(63);
  MINR.setGrDestiny(1);
  
  ASSERT_EQ(0x8E0257E0, MINR.printRTYPE());
  
  rVex::Operations::ALU::MIN MINIS;
  
  MINIS.setGrDestiny(1);
  MINIS.addReadRegister(10);
  MINIS.setShortImmediate(255);
  
  ASSERT_EQ(0x8E8253FC, MINIS.printISTYPE());
}


TEST(SyllableTest, PrintBinaryMINU)      // Test 7
{
  rVex::Operations::ALU::MINU MINUR;
  
  MINUR.addReadRegister(10);
  MINUR.addReadRegister(63);
  MINUR.setGrDestiny(1);
  
  ASSERT_EQ(0x900257E0, MINUR.printRTYPE());
  
  rVex::Operations::ALU::MINU MINUIS;
  
  MINUIS.setGrDestiny(1);
  MINUIS.addReadRegister(10);
  MINUIS.setShortImmediate(255);
  
  ASSERT_EQ(0x908253FC, MINUIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryOR)      // Test 8
{
  rVex::Operations::ALU::OR ORR;
  
  ORR.addReadRegister(10);
  ORR.addReadRegister(63);
  ORR.setGrDestiny(1);
  
  ASSERT_EQ(0x920257E0, ORR.printRTYPE());
  
  rVex::Operations::ALU::OR ORIS;
  
  ORIS.setGrDestiny(1);
  ORIS.addReadRegister(10);
  ORIS.setShortImmediate(255);
  
  ASSERT_EQ(0x928253FC, ORIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryORC)      // Test 9
{
  rVex::Operations::ALU::ORC ORCR;
  
  ORCR.addReadRegister(10);
  ORCR.addReadRegister(63);
  ORCR.setGrDestiny(1);
  
  ASSERT_EQ(0x940257E0, ORCR.printRTYPE());
  
  rVex::Operations::ALU::ORC ORCIS;
  
  ORCIS.setGrDestiny(1);
  ORCIS.addReadRegister(10);
  ORCIS.setShortImmediate(255);
  
  ASSERT_EQ(0x948253FC, ORCIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySH1ADD)      // Test 10
{
  rVex::Operations::ALU::SH1ADD SH1ADDR;
  
  SH1ADDR.addReadRegister(10);
  SH1ADDR.addReadRegister(63);
  SH1ADDR.setGrDestiny(1);
  
  ASSERT_EQ(0x960257E0, SH1ADDR.printRTYPE());
  
  rVex::Operations::ALU::SH1ADD SH1ADDIS;
  
  SH1ADDIS.setGrDestiny(1);
  SH1ADDIS.addReadRegister(10);
  SH1ADDIS.setShortImmediate(255);
  
  ASSERT_EQ(0x968253FC, SH1ADDIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySH2ADD)      // Test 11
{
  rVex::Operations::ALU::SH2ADD SH2ADDR;
  
  SH2ADDR.addReadRegister(10);
  SH2ADDR.addReadRegister(63);
  SH2ADDR.setGrDestiny(1);
  
  ASSERT_EQ(0x980257E0, SH2ADDR.printRTYPE());
  
  rVex::Operations::ALU::SH2ADD SH2ADDIS;
  
  SH2ADDIS.setGrDestiny(1);
  SH2ADDIS.addReadRegister(10);
  SH2ADDIS.setShortImmediate(255);
  
  ASSERT_EQ(0x988253FC, SH2ADDIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySH3ADD)      // Test 12
{
  rVex::Operations::ALU::SH3ADD SH3ADDR;
  
  SH3ADDR.addReadRegister(10);
  SH3ADDR.addReadRegister(63);
  SH3ADDR.setGrDestiny(1);
  
  ASSERT_EQ(0x9A0257E0, SH3ADDR.printRTYPE());
  
  rVex::Operations::ALU::SH3ADD SH3ADDIS;
  
  SH3ADDIS.setGrDestiny(1);
  SH3ADDIS.addReadRegister(10);
  SH3ADDIS.setShortImmediate(255);
  
  ASSERT_EQ(0x9A8253FC, SH3ADDIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySH4ADD)      // Test 13
{
  rVex::Operations::ALU::SH4ADD SH4ADDR;
  
  SH4ADDR.addReadRegister(10);
  SH4ADDR.addReadRegister(63);
  SH4ADDR.setGrDestiny(1);
  
  ASSERT_EQ(0x9C0257E0, SH4ADDR.printRTYPE());
  
  rVex::Operations::ALU::SH4ADD SH4ADDIS;
  
  SH4ADDIS.setGrDestiny(1);
  SH4ADDIS.addReadRegister(10);
  SH4ADDIS.setShortImmediate(255);
  
  ASSERT_EQ(0x9C8253FC, SH4ADDIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySHL)      // Test 14
{
  rVex::Operations::ALU::SHL SHLR;
  
  SHLR.addReadRegister(10);
  SHLR.addReadRegister(63);
  SHLR.setGrDestiny(1);
  
  ASSERT_EQ(0x9E0257E0, SHLR.printRTYPE());
  
  rVex::Operations::ALU::SHL SHLIS;
  
  SHLIS.setGrDestiny(1);
  SHLIS.addReadRegister(10);
  SHLIS.setShortImmediate(255);
  
  ASSERT_EQ(0x9E8253FC, SHLIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySHR)      // Test 15
{
  rVex::Operations::ALU::SHR SHRR;
  
  SHRR.addReadRegister(10);
  SHRR.addReadRegister(63);
  SHRR.setGrDestiny(1);
  
  ASSERT_EQ(0xA00257E0, SHRR.printRTYPE());
  
  rVex::Operations::ALU::SHR SHRIS;
  
  SHRIS.setGrDestiny(1);
  SHRIS.addReadRegister(10);
  SHRIS.setShortImmediate(255);
  
  ASSERT_EQ(0xA08253FC, SHRIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySHRU)      // Test 16
{
  rVex::Operations::ALU::SHRU SHRUR;
  
  SHRUR.addReadRegister(10);
  SHRUR.addReadRegister(63);
  SHRUR.setGrDestiny(1);
  
  ASSERT_EQ(0xA20257E0, SHRUR.printRTYPE());
  
  rVex::Operations::ALU::SHRU SHRUIS;
  
  SHRUIS.setGrDestiny(1);
  SHRUIS.addReadRegister(10);
  SHRUIS.setShortImmediate(255);
  
  ASSERT_EQ(0xA28253FC, SHRUIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySUB)      // Test 17
{
  rVex::Operations::ALU::SUB SUBR;
  
  SUBR.addReadRegister(10);
  SUBR.addReadRegister(63);
  SUBR.setGrDestiny(1);
  
  ASSERT_EQ(0xA40257E0, SUBR.printRTYPE());
  
  rVex::Operations::ALU::SUB SUBIS;
  
  SUBIS.setGrDestiny(1);
  SUBIS.addReadRegister(10);
  SUBIS.setShortImmediate(255);
  
  ASSERT_EQ(0xA48253FC, SUBIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySXTB)      // Test 18
{
  rVex::Operations::ALU::SXTB SXTBR;
  
  SXTBR.addReadRegister(10);
  SXTBR.addReadRegister(63);
  SXTBR.setGrDestiny(1);
  
  ASSERT_EQ(0xA60257E0, SXTBR.printRTYPE());
  
  rVex::Operations::ALU::SXTB SXTBIS;
  
  SXTBIS.setGrDestiny(1);
  SXTBIS.addReadRegister(10);
  SXTBIS.setShortImmediate(255);
  
  ASSERT_EQ(0xA68253FC, SXTBIS.printISTYPE());
}

TEST(SyllableTest, PrintBinarySXTH)      // Test 19
{
  rVex::Operations::ALU::SXTH SXTHR;
  
  SXTHR.addReadRegister(10);
  SXTHR.addReadRegister(63);
  SXTHR.setGrDestiny(1);
  
  ASSERT_EQ(0xA80257E0, SXTHR.printRTYPE());
  
  rVex::Operations::ALU::SXTH SXTHIS;
  
  SXTHIS.setGrDestiny(1);
  SXTHIS.addReadRegister(10);
  SXTHIS.setShortImmediate(255);
  
  ASSERT_EQ(0xA88253FC, SXTHIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryZXTB)      // Test 20
{
  rVex::Operations::ALU::ZXTB ZXTBR;
  
  ZXTBR.addReadRegister(10);
  ZXTBR.addReadRegister(63);
  ZXTBR.setGrDestiny(1);
  
  ASSERT_EQ(0xAA0257E0, ZXTBR.printRTYPE());
  
  rVex::Operations::ALU::ZXTB ZXTBIS;
  
  ZXTBIS.setGrDestiny(1);
  ZXTBIS.addReadRegister(10);
  ZXTBIS.setShortImmediate(255);
  
  ASSERT_EQ(0xAA8253FC, ZXTBIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryZXTH)      // Test 21
{
  rVex::Operations::ALU::ZXTH ZXTHR;
  
  ZXTHR.addReadRegister(10);
  ZXTHR.addReadRegister(63);
  ZXTHR.setGrDestiny(1);
  
  ASSERT_EQ(0xAC0257E0, ZXTHR.printRTYPE());
  
  rVex::Operations::ALU::ZXTH ZXTHIS;
  
  ZXTHIS.setGrDestiny(1);
  ZXTHIS.addReadRegister(10);
  ZXTHIS.setShortImmediate(255);
  
  ASSERT_EQ(0xAC8253FC, ZXTHIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryXOR)      // Test 22
{
  rVex::Operations::ALU::XOR XOR;
  
  XOR.addReadRegister(10);
  XOR.addReadRegister(63);
  XOR.setGrDestiny(1);
  
  ASSERT_EQ(0xAE0257E0, XOR.printRTYPE());
  
  rVex::Operations::ALU::XOR XORIS;
  
  XORIS.setGrDestiny(1);
  XORIS.addReadRegister(10);
  XORIS.setShortImmediate(255);
  
  ASSERT_EQ(0xAE8253FC, XORIS.printISTYPE());
}

TEST(SyllableTest, PrintBinaryMOV)      // Test 23
{
  rVex::Operations::ALU::MOV MOVR;
  
  MOVR.addReadRegister(0);
  MOVR.addReadRegister(63);
  MOVR.setGrDestiny(1);
  
  ASSERT_EQ(0xB00207E0, MOVR.printRTYPE());
}

//TEST(SyllableTest, PrintBinaryCMPEQ)      // Test 24
//{
//  rVex::Operations::ALU::CMPEQ CMPEQ;
//  
//  CMPEQ.addReadRegister(10);
//  CMPEQ.addReadRegister(63);
//  CMPEQ.setGrDestiny(1);
//  
//  ASSERT_EQ("10110010000000100101011111100001", CMPEQ.print(true, false));
//  ASSERT_EQ("10110010000000100101011111100010", CMPEQ.print(false, true));
//  ASSERT_EQ("10110010000000100101011111100011", CMPEQ.print(true, true));
//  ASSERT_EQ("10110010000000100101011111100000", CMPEQ.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPGE)      // Test 25
//{
//  rVex::Operations::ALU::CMPGE CMPGE;
//  
//  CMPGE.addReadRegister(10);
//  CMPGE.addReadRegister(63);
//  CMPGE.setGrDestiny(1);
//  
//  ASSERT_EQ("10110100000000100101011111100001", CMPGE.print(true, false));
//  ASSERT_EQ("10110100000000100101011111100010", CMPGE.print(false, true));
//  ASSERT_EQ("10110100000000100101011111100011", CMPGE.print(true, true));
//  ASSERT_EQ("10110100000000100101011111100000", CMPGE.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPGEU)      // Test 26
//{
//  rVex::Operations::ALU::CMPGEU CMPGEU;
//  
//  CMPGEU.addReadRegister(10);
//  CMPGEU.addReadRegister(63);
//  CMPGEU.setGrDestiny(1);
//  
//  ASSERT_EQ("10110110000000100101011111100001", CMPGEU.print(true, false));
//  ASSERT_EQ("10110110000000100101011111100010", CMPGEU.print(false, true));
//  ASSERT_EQ("10110110000000100101011111100011", CMPGEU.print(true, true));
//  ASSERT_EQ("10110110000000100101011111100000", CMPGEU.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPGT)      // Test 27
//{
//  rVex::Operations::ALU::CMPGT CMPGT;
//  
//  CMPGT.addReadRegister(10);
//  CMPGT.addReadRegister(63);
//  CMPGT.setGrDestiny(1);
//  
//  ASSERT_EQ("10111000000000100101011111100001", CMPGT.print(true, false));
//  ASSERT_EQ("10111000000000100101011111100010", CMPGT.print(false, true));
//  ASSERT_EQ("10111000000000100101011111100011", CMPGT.print(true, true));
//  ASSERT_EQ("10111000000000100101011111100000", CMPGT.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPGTU)      // Test 28
//{
//  rVex::Operations::ALU::CMPGTU CMPGTU;
//  
//  CMPGTU.addReadRegister(10);
//  CMPGTU.addReadRegister(63);
//  CMPGTU.setGrDestiny(1);
//  
//  ASSERT_EQ("10111010000000100101011111100001", CMPGTU.print(true, false));
//  ASSERT_EQ("10111010000000100101011111100010", CMPGTU.print(false, true));
//  ASSERT_EQ("10111010000000100101011111100011", CMPGTU.print(true, true));
//  ASSERT_EQ("10111010000000100101011111100000", CMPGTU.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPLE)      // Test 29
//{
//  rVex::Operations::ALU::CMPLE CMPLE;
//  
//  CMPLE.addReadRegister(10);
//  CMPLE.addReadRegister(63);
//  CMPLE.setGrDestiny(1);
//  
//  ASSERT_EQ("10111100000000100101011111100001", CMPLE.print(true, false));
//  ASSERT_EQ("10111100000000100101011111100010", CMPLE.print(false, true));
//  ASSERT_EQ("10111100000000100101011111100011", CMPLE.print(true, true));
//  ASSERT_EQ("10111100000000100101011111100000", CMPLE.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPLEU)      // Test 30
//{
//  rVex::Operations::ALU::CMPLEU CMPLEU;
//  
//  CMPLEU.addReadRegister(10);
//  CMPLEU.addReadRegister(63);
//  CMPLEU.setGrDestiny(1);
//  
//  ASSERT_EQ("10111110000000100101011111100001", CMPLEU.print(true, false));
//  ASSERT_EQ("10111110000000100101011111100010", CMPLEU.print(false, true));
//  ASSERT_EQ("10111110000000100101011111100011", CMPLEU.print(true, true));
//  ASSERT_EQ("10111110000000100101011111100000", CMPLEU.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPLT)      // Test 31
//{
//  rVex::Operations::ALU::CMPLT CMPLT;
//  
//  CMPLT.addReadRegister(10);
//  CMPLT.addReadRegister(63);
//  CMPLT.setGrDestiny(1);
//  
//  ASSERT_EQ("11000000000000100101011111100001", CMPLT.print(true, false));
//  ASSERT_EQ("11000000000000100101011111100010", CMPLT.print(false, true));
//  ASSERT_EQ("11000000000000100101011111100011", CMPLT.print(true, true));
//  ASSERT_EQ("11000000000000100101011111100000", CMPLT.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPLTU)      // Test 32
//{
//  rVex::Operations::ALU::CMPLTU CMPLTU;
//  
//  CMPLTU.addReadRegister(10);
//  CMPLTU.addReadRegister(63);
//  CMPLTU.setGrDestiny(1);
//  
//  ASSERT_EQ("11000010000000100101011111100001", CMPLTU.print(true, false));
//  ASSERT_EQ("11000010000000100101011111100010", CMPLTU.print(false, true));
//  ASSERT_EQ("11000010000000100101011111100011", CMPLTU.print(true, true));
//  ASSERT_EQ("11000010000000100101011111100000", CMPLTU.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryCMPNE)      // Test 33
//{
//  rVex::Operations::ALU::CMPNE CMPNE;
//  
//  CMPNE.addReadRegister(10);
//  CMPNE.addReadRegister(63);
//  CMPNE.setGrDestiny(1);
//  
//  ASSERT_EQ("11000100000000100101011111100001", CMPNE.print(true, false));
//  ASSERT_EQ("11000100000000100101011111100010", CMPNE.print(false, true));
//  ASSERT_EQ("11000100000000100101011111100011", CMPNE.print(true, true));
//  ASSERT_EQ("11000100000000100101011111100000", CMPNE.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryNANDL)      // Test 34
//{
//  rVex::Operations::ALU::NANDL NANDL;
//  
//  NANDL.addReadRegister(10);
//  NANDL.addReadRegister(63);
//  NANDL.setGrDestiny(1);
//  
//  ASSERT_EQ("11000110000000100101011111100001", NANDL.print(true, false));
//  ASSERT_EQ("11000110000000100101011111100010", NANDL.print(false, true));
//  ASSERT_EQ("11000110000000100101011111100011", NANDL.print(true, true));
//  ASSERT_EQ("11000110000000100101011111100000", NANDL.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryNORL)      // Test 35
//{
//  rVex::Operations::ALU::NORL NORL;
//  
//  NORL.addReadRegister(10);
//  NORL.addReadRegister(63);
//  NORL.setGrDestiny(1);
//  
//  ASSERT_EQ("11001000000000100101011111100001", NORL.print(true, false));
//  ASSERT_EQ("11001000000000100101011111100010", NORL.print(false, true));
//  ASSERT_EQ("11001000000000100101011111100011", NORL.print(true, true));
//  ASSERT_EQ("11001000000000100101011111100000", NORL.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryORL)      // Test 36
//{
//  rVex::Operations::ALU::ORL ORL;
//  
//  ORL.addReadRegister(10);
//  ORL.addReadRegister(63);
//  ORL.setGrDestiny(1);
//  
//  ASSERT_EQ("11001100000000100101011111100001", ORL.print(true, false));
//  ASSERT_EQ("11001100000000100101011111100010", ORL.print(false, true));
//  ASSERT_EQ("11001100000000100101011111100011", ORL.print(true, true));
//  ASSERT_EQ("11001100000000100101011111100000", ORL.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryMTB)      // Test 37
//{
//  rVex::Operations::ALU::MTB MTB;
//  
//  MTB.addReadRegister(10);
//  MTB.addReadRegister(63);
//  MTB.setGrDestiny(1);
//  
//  ASSERT_EQ("11001110000000100101011111100001", MTB.print(true, false));
//  ASSERT_EQ("11001110000000100101011111100010", MTB.print(false, true));
//  ASSERT_EQ("11001110000000100101011111100011", MTB.print(true, true));
//  ASSERT_EQ("11001110000000100101011111100000", MTB.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryANDL)      // Test 38
//{
//  rVex::Operations::ALU::ANDL ANDL;
//  
//  ANDL.addReadRegister(10);
//  ANDL.addReadRegister(63);
//  ANDL.setGrDestiny(1);
//  
//  ASSERT_EQ("11010000000000100101011111100001", ANDL.print(true, false));
//  ASSERT_EQ("11010000000000100101011111100010", ANDL.print(false, true));
//  ASSERT_EQ("11010000000000100101011111100011", ANDL.print(true, true));
//  ASSERT_EQ("11010000000000100101011111100000", ANDL.print(false, false));
//}
//
////TEST(SyllableTest, PrintBinaryADDCG)      // Test 39
////{
////  rVex::Operations::ALU::ADDCG ADDCG;
////  
////  ADDCG.addReadRegister(10);
////  ADDCG.addReadRegister(63);
////  ADDCG.setGrDestiny(1);
////  
////  ASSERT_EQ("11010000000000100101011111100001", ADDCG.print(true, false));
////  ASSERT_EQ("11010000000000100101011111100010", ADDCG.print(false, true));
////  ASSERT_EQ("11010000000000100101011111100011", ADDCG.print(true, true));
////  ASSERT_EQ("11010000000000100101011111100000", ADDCG.print(false, false));
////}
////
////TEST(SyllableTest, PrintBinaryDIVS)      // Test 40
////{
////  rVex::Operations::ALU::DIVS DIVS;
////  
////  DIVS.addReadRegister(10);
////  DIVS.addReadRegister(63);
////  DIVS.setGrDestiny(1);
////  
////  ASSERT_EQ("11001110000000100101011111100001", DIVS.print(true, false));
////  ASSERT_EQ("11001110000000100101011111100010", DIVS.print(false, true));
////  ASSERT_EQ("11001110000000100101011111100011", DIVS.print(true, true));
////  ASSERT_EQ("11001110000000100101011111100000", DIVS.print(false, false));
////}
//
//TEST(SyllableTest, PrintBinarySLCT)      // Test 41
//{
//  rVex::Operations::ALU::SLCT SLCT;
//  
//  SLCT.addReadRegister(10);
//  SLCT.addReadRegister(63);
//  SLCT.setGrDestiny(1);
//  
//  ASSERT_EQ("01110000000000100101011111100001", SLCT.print(true, false));
//  ASSERT_EQ("01110000000000100101011111100010", SLCT.print(false, true));
//  ASSERT_EQ("01110000000000100101011111100011", SLCT.print(true, true));
//  ASSERT_EQ("01110000000000100101011111100000", SLCT.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinarySLCTF)      // Test 42
//{
//  rVex::Operations::ALU::SLCTF SLCTF;
//  
//  SLCTF.addReadRegister(10);
//  SLCTF.addReadRegister(63);
//  SLCTF.setGrDestiny(1);
//  
//  ASSERT_EQ("01100000000000100101011111100001", SLCTF.print(true, false));
//  ASSERT_EQ("01100000000000100101011111100010", SLCTF.print(false, true));
//  ASSERT_EQ("01100000000000100101011111100011", SLCTF.print(true, true));
//  ASSERT_EQ("01100000000000100101011111100000", SLCTF.print(false, false));
//}

}