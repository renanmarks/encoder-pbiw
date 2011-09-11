#include "gtest/gtest.h"
#include "rVex/rVex.h"

using namespace std;
using namespace rVex;

TEST(SyllableTest, PrintBinaryADD)      // Test 1
{
  rVex::Operations::ALU::ADD add;
  
  add.addReadRegister(10);
  add.addReadRegister(63);
  add.setGrDestiny(1);
  
  ASSERT_EQ("10000010000000100101011111100001", add.print(true, false));
  ASSERT_EQ("10000010000000100101011111100010", add.print(false, true));
  ASSERT_EQ("10000010000000100101011111100011", add.print(true, true));
  ASSERT_EQ("10000010000000100101011111100000", add.print(false, false));
}

TEST(SyllableTest, PrintBinaryAND)      // Test 2
{
  rVex::Operations::ALU::AND AND;
  
  AND.addReadRegister(10);
  AND.addReadRegister(63);
  AND.setGrDestiny(1);
  
  ASSERT_EQ("10000110000000100101011111100001", AND.print(true, false));
  ASSERT_EQ("10000110000000100101011111100010", AND.print(false, true));
  ASSERT_EQ("10000110000000100101011111100011", AND.print(true, true));
  ASSERT_EQ("10000110000000100101011111100000", AND.print(false, false));
}

TEST(SyllableTest, PrintBinaryANDC)     // Test 3
{
  rVex::Operations::ALU::ANDC ANDC;
  
  ANDC.addReadRegister(10);
  ANDC.addReadRegister(63);
  ANDC.setGrDestiny(1);
  
  ASSERT_EQ("10001000000000100101011111100001", ANDC.print(true, false));
  ASSERT_EQ("10001000000000100101011111100010", ANDC.print(false, true));
  ASSERT_EQ("10001000000000100101011111100011", ANDC.print(true, true));
  ASSERT_EQ("10001000000000100101011111100000", ANDC.print(false, false));
}

TEST(SyllableTest, PrintBinaryMAX)      // Test 4
{
  rVex::Operations::ALU::MAX MAX;
  
  MAX.addReadRegister(10);
  MAX.addReadRegister(63);
  MAX.setGrDestiny(1);
  
  ASSERT_EQ("10001010000000100101011111100001", MAX.print(true, false));
  ASSERT_EQ("10001010000000100101011111100010", MAX.print(false, true));
  ASSERT_EQ("10001010000000100101011111100011", MAX.print(true, true));
  ASSERT_EQ("10001010000000100101011111100000", MAX.print(false, false));
}

TEST(SyllableTest, PrintBinaryMAXU)      // Test 5
{
  rVex::Operations::ALU::MAXU MAXU;
  
  MAXU.addReadRegister(10);
  MAXU.addReadRegister(63);
  MAXU.setGrDestiny(1);
  
  ASSERT_EQ("10001100000000100101011111100001", MAXU.print(true, false));
  ASSERT_EQ("10001100000000100101011111100010", MAXU.print(false, true));
  ASSERT_EQ("10001100000000100101011111100011", MAXU.print(true, true));
  ASSERT_EQ("10001100000000100101011111100000", MAXU.print(false, false));
}

TEST(SyllableTest, PrintBinaryMIN)      // Test 6
{
  rVex::Operations::ALU::MIN MIN;
  
  MIN.addReadRegister(10);
  MIN.addReadRegister(63);
  MIN.setGrDestiny(1);
  
  ASSERT_EQ("10001110000000100101011111100001", MIN.print(true, false));
  ASSERT_EQ("10001110000000100101011111100010", MIN.print(false, true));
  ASSERT_EQ("10001110000000100101011111100011", MIN.print(true, true));
  ASSERT_EQ("10001110000000100101011111100000", MIN.print(false, false));
}

TEST(SyllableTest, PrintBinaryMINU)      // Test 7
{
  rVex::Operations::ALU::MINU MINU;
  
  MINU.addReadRegister(10);
  MINU.addReadRegister(63);
  MINU.setGrDestiny(1);
  
  ASSERT_EQ("10010000000000100101011111100001", MINU.print(true, false));
  ASSERT_EQ("10010000000000100101011111100010", MINU.print(false, true));
  ASSERT_EQ("10010000000000100101011111100011", MINU.print(true, true));
  ASSERT_EQ("10010000000000100101011111100000", MINU.print(false, false));
}

TEST(SyllableTest, PrintBinaryOR)      // Test 8
{
  rVex::Operations::ALU::OR OR;
  
  OR.addReadRegister(10);
  OR.addReadRegister(63);
  OR.setGrDestiny(1);
  
  ASSERT_EQ("10010010000000100101011111100001", OR.print(true, false));
  ASSERT_EQ("10010010000000100101011111100010", OR.print(false, true));
  ASSERT_EQ("10010010000000100101011111100011", OR.print(true, true));
  ASSERT_EQ("10010010000000100101011111100000", OR.print(false, false));
}

TEST(SyllableTest, PrintBinaryORC)      // Test 9
{
  rVex::Operations::ALU::ORC ORC;
  
  ORC.addReadRegister(10);
  ORC.addReadRegister(63);
  ORC.setGrDestiny(1);
  
  ASSERT_EQ("10010100000000100101011111100001", ORC.print(true, false));
  ASSERT_EQ("10010100000000100101011111100010", ORC.print(false, true));
  ASSERT_EQ("10010100000000100101011111100011", ORC.print(true, true));
  ASSERT_EQ("10010100000000100101011111100000", ORC.print(false, false));
}

TEST(SyllableTest, PrintBinarySH1ADD)      // Test 10
{
  rVex::Operations::ALU::SH1ADD SH1ADD;
  
  SH1ADD.addReadRegister(10);
  SH1ADD.addReadRegister(63);
  SH1ADD.setGrDestiny(1);
  
  ASSERT_EQ("10010110000000100101011111100001", SH1ADD.print(true, false));
  ASSERT_EQ("10010110000000100101011111100010", SH1ADD.print(false, true));
  ASSERT_EQ("10010110000000100101011111100011", SH1ADD.print(true, true));
  ASSERT_EQ("10010110000000100101011111100000", SH1ADD.print(false, false));
}

TEST(SyllableTest, PrintBinarySH2ADD)      // Test 11
{
  rVex::Operations::ALU::SH2ADD SH2ADD;
  
  SH2ADD.addReadRegister(10);
  SH2ADD.addReadRegister(63);
  SH2ADD.setGrDestiny(1);
  
  ASSERT_EQ("10011000000000100101011111100001", SH2ADD.print(true, false));
  ASSERT_EQ("10011000000000100101011111100010", SH2ADD.print(false, true));
  ASSERT_EQ("10011000000000100101011111100011", SH2ADD.print(true, true));
  ASSERT_EQ("10011000000000100101011111100000", SH2ADD.print(false, false));
}

TEST(SyllableTest, PrintBinarySH3ADD)      // Test 12
{
  rVex::Operations::ALU::SH3ADD SH3ADD;
  
  SH3ADD.addReadRegister(10);
  SH3ADD.addReadRegister(63);
  SH3ADD.setGrDestiny(1);
  
  ASSERT_EQ("10011010000000100101011111100001", SH3ADD.print(true, false));
  ASSERT_EQ("10011010000000100101011111100010", SH3ADD.print(false, true));
  ASSERT_EQ("10011010000000100101011111100011", SH3ADD.print(true, true));
  ASSERT_EQ("10011010000000100101011111100000", SH3ADD.print(false, false));
}

TEST(SyllableTest, PrintBinarySH4ADD)      // Test 13
{
  rVex::Operations::ALU::SH4ADD SH4ADD;
  
  SH4ADD.addReadRegister(10);
  SH4ADD.addReadRegister(63);
  SH4ADD.setGrDestiny(1);
  
  ASSERT_EQ("10011100000000100101011111100001", SH4ADD.print(true, false));
  ASSERT_EQ("10011100000000100101011111100010", SH4ADD.print(false, true));
  ASSERT_EQ("10011100000000100101011111100011", SH4ADD.print(true, true));
  ASSERT_EQ("10011100000000100101011111100000", SH4ADD.print(false, false));
}

TEST(SyllableTest, PrintBinarySHL)      // Test 14
{
  rVex::Operations::ALU::SHL SHL;
  
  SHL.addReadRegister(10);
  SHL.addReadRegister(63);
  SHL.setGrDestiny(1);
  
  ASSERT_EQ("10011110000000100101011111100001", SHL.print(true, false));
  ASSERT_EQ("10011110000000100101011111100010", SHL.print(false, true));
  ASSERT_EQ("10011110000000100101011111100011", SHL.print(true, true));
  ASSERT_EQ("10011110000000100101011111100000", SHL.print(false, false));
}

TEST(SyllableTest, PrintBinarySHR)      // Test 15
{
  rVex::Operations::ALU::SHR SHR;
  
  SHR.addReadRegister(10);
  SHR.addReadRegister(63);
  SHR.setGrDestiny(1);
  
  ASSERT_EQ("10100000000000100101011111100001", SHR.print(true, false));
  ASSERT_EQ("10100000000000100101011111100010", SHR.print(false, true));
  ASSERT_EQ("10100000000000100101011111100011", SHR.print(true, true));
  ASSERT_EQ("10100000000000100101011111100000", SHR.print(false, false));
}

TEST(SyllableTest, PrintBinarySHRU)      // Test 16
{
  rVex::Operations::ALU::SHRU SHRU;
  
  SHRU.addReadRegister(10);
  SHRU.addReadRegister(63);
  SHRU.setGrDestiny(1);
  
  ASSERT_EQ("10100010000000100101011111100001", SHRU.print(true, false));
  ASSERT_EQ("10100010000000100101011111100010", SHRU.print(false, true));
  ASSERT_EQ("10100010000000100101011111100011", SHRU.print(true, true));
  ASSERT_EQ("10100010000000100101011111100000", SHRU.print(false, false));
}

TEST(SyllableTest, PrintBinarySUB)      // Test 17
{
  rVex::Operations::ALU::SUB SUB;
  
  SUB.addReadRegister(10);
  SUB.addReadRegister(63);
  SUB.setGrDestiny(1);
  
  ASSERT_EQ("10100100000000100101011111100001", SUB.print(true, false));
  ASSERT_EQ("10100100000000100101011111100010", SUB.print(false, true));
  ASSERT_EQ("10100100000000100101011111100011", SUB.print(true, true));
  ASSERT_EQ("10100100000000100101011111100000", SUB.print(false, false));
}

TEST(SyllableTest, PrintBinarySXTB)      // Test 18
{
  rVex::Operations::ALU::SXTB SXTB;
  
  SXTB.addReadRegister(10);
  SXTB.addReadRegister(63);
  SXTB.setGrDestiny(1);
  
  ASSERT_EQ("10100110000000100101011111100001", SXTB.print(true, false));
  ASSERT_EQ("10100110000000100101011111100010", SXTB.print(false, true));
  ASSERT_EQ("10100110000000100101011111100011", SXTB.print(true, true));
  ASSERT_EQ("10100110000000100101011111100000", SXTB.print(false, false));
}

TEST(SyllableTest, PrintBinarySXTH)      // Test 19
{
  rVex::Operations::ALU::SXTH SXTH;
  
  SXTH.addReadRegister(10);
  SXTH.addReadRegister(63);
  SXTH.setGrDestiny(1);
  
  ASSERT_EQ("10101000000000100101011111100001", SXTH.print(true, false));
  ASSERT_EQ("10101000000000100101011111100010", SXTH.print(false, true));
  ASSERT_EQ("10101000000000100101011111100011", SXTH.print(true, true));
  ASSERT_EQ("10101000000000100101011111100000", SXTH.print(false, false));
}

TEST(SyllableTest, PrintBinaryZXTB)      // Test 20
{
  rVex::Operations::ALU::ZXTB ZXTB;
  
  ZXTB.addReadRegister(10);
  ZXTB.addReadRegister(63);
  ZXTB.setGrDestiny(1);
  
  ASSERT_EQ("10101010000000100101011111100001", ZXTB.print(true, false));
  ASSERT_EQ("10101010000000100101011111100010", ZXTB.print(false, true));
  ASSERT_EQ("10101010000000100101011111100011", ZXTB.print(true, true));
  ASSERT_EQ("10101010000000100101011111100000", ZXTB.print(false, false));
}

TEST(SyllableTest, PrintBinaryZXTH)      // Test 21
{
  rVex::Operations::ALU::ZXTH ZXTH;
  
  ZXTH.addReadRegister(10);
  ZXTH.addReadRegister(63);
  ZXTH.setGrDestiny(1);
  
  ASSERT_EQ("10101100000000100101011111100001", ZXTH.print(true, false));
  ASSERT_EQ("10101100000000100101011111100010", ZXTH.print(false, true));
  ASSERT_EQ("10101100000000100101011111100011", ZXTH.print(true, true));
  ASSERT_EQ("10101100000000100101011111100000", ZXTH.print(false, false));
}

TEST(SyllableTest, PrintBinaryXOR)      // Test 22
{
  rVex::Operations::ALU::XOR XOR;
  
  XOR.addReadRegister(10);
  XOR.addReadRegister(63);
  XOR.setGrDestiny(1);
  
  ASSERT_EQ("10101110000000100101011111100001", XOR.print(true, false));
  ASSERT_EQ("10101110000000100101011111100010", XOR.print(false, true));
  ASSERT_EQ("10101110000000100101011111100011", XOR.print(true, true));
  ASSERT_EQ("10101110000000100101011111100000", XOR.print(false, false));
}

TEST(SyllableTest, PrintBinaryMOV)      // Test 23
{
  rVex::Operations::ALU::MOV MOV;
  
  MOV.addReadRegister(10);
  MOV.addReadRegister(63);
  MOV.setGrDestiny(1);
  
  ASSERT_EQ("10110000000000100101011111100001", MOV.print(true, false));
  ASSERT_EQ("10110000000000100101011111100010", MOV.print(false, true));
  ASSERT_EQ("10110000000000100101011111100011", MOV.print(true, true));
  ASSERT_EQ("10110000000000100101011111100000", MOV.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPEQ)      // Test 24
{
  rVex::Operations::ALU::CMPEQ CMPEQ;
  
  CMPEQ.addReadRegister(10);
  CMPEQ.addReadRegister(63);
  CMPEQ.setGrDestiny(1);
  
  ASSERT_EQ("10110010000000100101011111100001", CMPEQ.print(true, false));
  ASSERT_EQ("10110010000000100101011111100010", CMPEQ.print(false, true));
  ASSERT_EQ("10110010000000100101011111100011", CMPEQ.print(true, true));
  ASSERT_EQ("10110010000000100101011111100000", CMPEQ.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPGE)      // Test 25
{
  rVex::Operations::ALU::CMPGE CMPGE;
  
  CMPGE.addReadRegister(10);
  CMPGE.addReadRegister(63);
  CMPGE.setGrDestiny(1);
  
  ASSERT_EQ("10110100000000100101011111100001", CMPGE.print(true, false));
  ASSERT_EQ("10110100000000100101011111100010", CMPGE.print(false, true));
  ASSERT_EQ("10110100000000100101011111100011", CMPGE.print(true, true));
  ASSERT_EQ("10110100000000100101011111100000", CMPGE.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPGEU)      // Test 26
{
  rVex::Operations::ALU::CMPGEU CMPGEU;
  
  CMPGEU.addReadRegister(10);
  CMPGEU.addReadRegister(63);
  CMPGEU.setGrDestiny(1);
  
  ASSERT_EQ("10110110000000100101011111100001", CMPGEU.print(true, false));
  ASSERT_EQ("10110110000000100101011111100010", CMPGEU.print(false, true));
  ASSERT_EQ("10110110000000100101011111100011", CMPGEU.print(true, true));
  ASSERT_EQ("10110110000000100101011111100000", CMPGEU.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPGT)      // Test 27
{
  rVex::Operations::ALU::CMPGT CMPGT;
  
  CMPGT.addReadRegister(10);
  CMPGT.addReadRegister(63);
  CMPGT.setGrDestiny(1);
  
  ASSERT_EQ("10111000000000100101011111100001", CMPGT.print(true, false));
  ASSERT_EQ("10111000000000100101011111100010", CMPGT.print(false, true));
  ASSERT_EQ("10111000000000100101011111100011", CMPGT.print(true, true));
  ASSERT_EQ("10111000000000100101011111100000", CMPGT.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPGTU)      // Test 28
{
  rVex::Operations::ALU::CMPGTU CMPGTU;
  
  CMPGTU.addReadRegister(10);
  CMPGTU.addReadRegister(63);
  CMPGTU.setGrDestiny(1);
  
  ASSERT_EQ("10111010000000100101011111100001", CMPGTU.print(true, false));
  ASSERT_EQ("10111010000000100101011111100010", CMPGTU.print(false, true));
  ASSERT_EQ("10111010000000100101011111100011", CMPGTU.print(true, true));
  ASSERT_EQ("10111010000000100101011111100000", CMPGTU.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPLE)      // Test 29
{
  rVex::Operations::ALU::CMPLE CMPLE;
  
  CMPLE.addReadRegister(10);
  CMPLE.addReadRegister(63);
  CMPLE.setGrDestiny(1);
  
  ASSERT_EQ("10111100000000100101011111100001", CMPLE.print(true, false));
  ASSERT_EQ("10111100000000100101011111100010", CMPLE.print(false, true));
  ASSERT_EQ("10111100000000100101011111100011", CMPLE.print(true, true));
  ASSERT_EQ("10111100000000100101011111100000", CMPLE.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPLEU)      // Test 30
{
  rVex::Operations::ALU::CMPLEU CMPLEU;
  
  CMPLEU.addReadRegister(10);
  CMPLEU.addReadRegister(63);
  CMPLEU.setGrDestiny(1);
  
  ASSERT_EQ("10111110000000100101011111100001", CMPLEU.print(true, false));
  ASSERT_EQ("10111110000000100101011111100010", CMPLEU.print(false, true));
  ASSERT_EQ("10111110000000100101011111100011", CMPLEU.print(true, true));
  ASSERT_EQ("10111110000000100101011111100000", CMPLEU.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPLT)      // Test 31
{
  rVex::Operations::ALU::CMPLT CMPLT;
  
  CMPLT.addReadRegister(10);
  CMPLT.addReadRegister(63);
  CMPLT.setGrDestiny(1);
  
  ASSERT_EQ("11000000000000100101011111100001", CMPLT.print(true, false));
  ASSERT_EQ("11000000000000100101011111100010", CMPLT.print(false, true));
  ASSERT_EQ("11000000000000100101011111100011", CMPLT.print(true, true));
  ASSERT_EQ("11000000000000100101011111100000", CMPLT.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPLTU)      // Test 32
{
  rVex::Operations::ALU::CMPLTU CMPLTU;
  
  CMPLTU.addReadRegister(10);
  CMPLTU.addReadRegister(63);
  CMPLTU.setGrDestiny(1);
  
  ASSERT_EQ("11000010000000100101011111100001", CMPLTU.print(true, false));
  ASSERT_EQ("11000010000000100101011111100010", CMPLTU.print(false, true));
  ASSERT_EQ("11000010000000100101011111100011", CMPLTU.print(true, true));
  ASSERT_EQ("11000010000000100101011111100000", CMPLTU.print(false, false));
}

TEST(SyllableTest, PrintBinaryCMPNE)      // Test 33
{
  rVex::Operations::ALU::CMPNE CMPNE;
  
  CMPNE.addReadRegister(10);
  CMPNE.addReadRegister(63);
  CMPNE.setGrDestiny(1);
  
  ASSERT_EQ("11000100000000100101011111100001", CMPNE.print(true, false));
  ASSERT_EQ("11000100000000100101011111100010", CMPNE.print(false, true));
  ASSERT_EQ("11000100000000100101011111100011", CMPNE.print(true, true));
  ASSERT_EQ("11000100000000100101011111100000", CMPNE.print(false, false));
}

TEST(SyllableTest, PrintBinaryNANDL)      // Test 34
{
  rVex::Operations::ALU::NANDL NANDL;
  
  NANDL.addReadRegister(10);
  NANDL.addReadRegister(63);
  NANDL.setGrDestiny(1);
  
  ASSERT_EQ("11000110000000100101011111100001", NANDL.print(true, false));
  ASSERT_EQ("11000110000000100101011111100010", NANDL.print(false, true));
  ASSERT_EQ("11000110000000100101011111100011", NANDL.print(true, true));
  ASSERT_EQ("11000110000000100101011111100000", NANDL.print(false, false));
}

TEST(SyllableTest, PrintBinaryNORL)      // Test 35
{
  rVex::Operations::ALU::NORL NORL;
  
  NORL.addReadRegister(10);
  NORL.addReadRegister(63);
  NORL.setGrDestiny(1);
  
  ASSERT_EQ("11001000000000100101011111100001", NORL.print(true, false));
  ASSERT_EQ("11001000000000100101011111100010", NORL.print(false, true));
  ASSERT_EQ("11001000000000100101011111100011", NORL.print(true, true));
  ASSERT_EQ("11001000000000100101011111100000", NORL.print(false, false));
}

TEST(SyllableTest, PrintBinaryORL)      // Test 36
{
  rVex::Operations::ALU::ORL ORL;
  
  ORL.addReadRegister(10);
  ORL.addReadRegister(63);
  ORL.setGrDestiny(1);
  
  ASSERT_EQ("11001100000000100101011111100001", ORL.print(true, false));
  ASSERT_EQ("11001100000000100101011111100010", ORL.print(false, true));
  ASSERT_EQ("11001100000000100101011111100011", ORL.print(true, true));
  ASSERT_EQ("11001100000000100101011111100000", ORL.print(false, false));
}

TEST(SyllableTest, PrintBinaryMTB)      // Test 37
{
  rVex::Operations::ALU::MTB MTB;
  
  MTB.addReadRegister(10);
  MTB.addReadRegister(63);
  MTB.setGrDestiny(1);
  
  ASSERT_EQ("11001110000000100101011111100001", MTB.print(true, false));
  ASSERT_EQ("11001110000000100101011111100010", MTB.print(false, true));
  ASSERT_EQ("11001110000000100101011111100011", MTB.print(true, true));
  ASSERT_EQ("11001110000000100101011111100000", MTB.print(false, false));
}

TEST(SyllableTest, PrintBinaryANDL)      // Test 38
{
  rVex::Operations::ALU::ANDL ANDL;
  
  ANDL.addReadRegister(10);
  ANDL.addReadRegister(63);
  ANDL.setGrDestiny(1);
  
  ASSERT_EQ("11010000000000100101011111100001", ANDL.print(true, false));
  ASSERT_EQ("11010000000000100101011111100010", ANDL.print(false, true));
  ASSERT_EQ("11010000000000100101011111100011", ANDL.print(true, true));
  ASSERT_EQ("11010000000000100101011111100000", ANDL.print(false, false));
}

//TEST(SyllableTest, PrintBinaryADDCG)      // Test 39
//{
//  rVex::Operations::ALU::ADDCG ADDCG;
//  
//  ADDCG.addReadRegister(10);
//  ADDCG.addReadRegister(63);
//  ADDCG.setGrDestiny(1);
//  
//  ASSERT_EQ("11010000000000100101011111100001", ADDCG.print(true, false));
//  ASSERT_EQ("11010000000000100101011111100010", ADDCG.print(false, true));
//  ASSERT_EQ("11010000000000100101011111100011", ADDCG.print(true, true));
//  ASSERT_EQ("11010000000000100101011111100000", ADDCG.print(false, false));
//}
//
//TEST(SyllableTest, PrintBinaryDIVS)      // Test 40
//{
//  rVex::Operations::ALU::DIVS DIVS;
//  
//  DIVS.addReadRegister(10);
//  DIVS.addReadRegister(63);
//  DIVS.setGrDestiny(1);
//  
//  ASSERT_EQ("11001110000000100101011111100001", DIVS.print(true, false));
//  ASSERT_EQ("11001110000000100101011111100010", DIVS.print(false, true));
//  ASSERT_EQ("11001110000000100101011111100011", DIVS.print(true, true));
//  ASSERT_EQ("11001110000000100101011111100000", DIVS.print(false, false));
//}

TEST(SyllableTest, PrintBinarySLCT)      // Test 41
{
  rVex::Operations::ALU::SLCT SLCT;
  
  SLCT.addReadRegister(10);
  SLCT.addReadRegister(63);
  SLCT.setGrDestiny(1);
  
  ASSERT_EQ("01110000000000100101011111100001", SLCT.print(true, false));
  ASSERT_EQ("01110000000000100101011111100010", SLCT.print(false, true));
  ASSERT_EQ("01110000000000100101011111100011", SLCT.print(true, true));
  ASSERT_EQ("01110000000000100101011111100000", SLCT.print(false, false));
}

TEST(SyllableTest, PrintBinarySLCTF)      // Test 42
{
  rVex::Operations::ALU::SLCTF SLCTF;
  
  SLCTF.addReadRegister(10);
  SLCTF.addReadRegister(63);
  SLCTF.setGrDestiny(1);
  
  ASSERT_EQ("01100000000000100101011111100001", SLCTF.print(true, false));
  ASSERT_EQ("01100000000000100101011111100010", SLCTF.print(false, true));
  ASSERT_EQ("01100000000000100101011111100011", SLCTF.print(true, true));
  ASSERT_EQ("01100000000000100101011111100000", SLCTF.print(false, false));
}
