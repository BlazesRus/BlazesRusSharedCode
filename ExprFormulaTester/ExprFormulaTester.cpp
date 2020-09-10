// ExprFormulaTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//#include "AltNum\AltDec.hpp"
#include "AltNum\MediumDec.hpp"
//#include "Databases\MediumDecFormula.hpp"
#include <string>
#include <boost/timer/timer.hpp>

int main()
{
    //AltDec MultTest01 = "2/3";
    //AltDec MultTest02 = "3/4";
    //MultTest01 *= MultTest02;
    //std::cout << "(2/3) * (3/4) = " << MultTest01.ToOptimalString() << " (Should be 1/2)" << std::endl;//Success
    //AltDec MultTest03 = "1.5";
    //AltDec MultTest04 = "0.5";
    //MultTest03 *= MultTest04;
    //std::cout << "(1.5) * (0.5) = " << MultTest03.ToOptimalString() << " (Should be 0.75)" << std::endl;//Success
    //AltDec MultTest05 = "1.5";
    //AltDec MultTest06 = "3/4";
    //MultTest05 *= MultTest06;
    //std::cout << "(1.5) * (3/4) = " << MultTest05.ToOptimalString() << " (Should be 1.25 or 1 1/4)" << std::endl;//Failed
    //AltDec MultTest07 = "3/4";
    //AltDec MultTest08 = "1.5";
    //MultTest07 *= MultTest08;
    //std::cout << "(3/4) * 1.5 = " << MultTest07.ToOptimalString() << " (Should be 1.25 or 1 1/4)" << std::endl;//Failed
    //AltDec DivTest01 = "1.5";
    //AltDec DivTest02 = "2.5";
    //DivTest01 /= DivTest02;
    //std::cout << "1.5 / 2.5 = " << DivTest01.ToOptimalString() << " (Should be 0.6 or 3/5)" << std::endl;//Success
    //AltDec DivTest03 = "2/3";
    //AltDec DivTest04 = "1/2";
    //DivTest03 /= DivTest04;
    //std::cout << "(2/3) / (1/2) = " << DivTest03.ToOptimalString() << " (Should be 4/3)" << std::endl;//Failed
    //AltDec AddTest01 = "2";
    //AltDec AddTest02 = "-1 1/3";
    //AddTest01 += AddTest02;
    //std::cout << "2.0 + (-1 1/3) = " << AddTest01.ToOptimalString() << std::endl;//Success
    //AltDec AddTest03 = "-2";
    //AltDec AddTest04 = "-1 2/3";
    //AddTest03 += AddTest04;
    //std::cout << "-2.0 + (-1 2/3) = " << AddTest03.ToOptimalString() << std::endl;//Success
    //AltDec SubTest01 = "2";
    //AltDec SubTest02 = "-1 1/3";
    //SubTest01 -= SubTest02;
    //std::cout << "2.0 - (-1 1/3) = " << SubTest01.ToOptimalString() << " (Should be 3 1/3)" << std::endl;//Success
    //AltDec SubTest03 = "-2";
    //AltDec SubTest04 = "-1 2/3";
    //SubTest03 -= SubTest04;
    //std::cout << "-2.0 - (-1 2/3) = " << SubTest03.ToOptimalString() << " (Should be 1/3)" << std::endl;//Failed
    //AltDec AddTest05 = "-2";
    //int AddTest06 = 4;
    //AddTest05 += AddTest06;
    //std::cout << "(IntegerTest) -2.0 + 4 = " << AddTest05.ToOptimalString() << std::endl;//Success
    //AltDec IntegerTest01 = "2.5";
    //int IntegerTest02 = 4;
    //IntegerTest01 *= IntegerTest02;
    //std::cout << "(IntegerTest) 2.5 * 4 = " << IntegerTest01.ToOptimalString() << std::endl;//Success
    //AltDec FracTest01 = "-1 1/2";
    //AltDec FracTest02 = "-1 1/3";
    //FracTest01 += FracTest02;
    //std::cout << "(FracTest#1):" << FracTest01.ToOptimalString() << " (Should be -2 5/6)" << std::endl;
    //FracTest01 = "1 1/2";
    //FracTest02 = "1 1/3";
    //FracTest01 += FracTest02;
    //std::cout << "(FracTest#1):" << FracTest01.ToOptimalString() << " (Should be 2 5/6)" << std::endl;
    //FracTest01 = "2 1/2";
    //FracTest02 = "2 1/2";
    //FracTest01 += FracTest02;
    //std::cout << "(FracTest#1):" << FracTest01.ToOptimalString() << " (Should be 5)" << std::endl;
    //FracTest01 = "2 3/4";
    //FracTest02 = "2 1/2";
    //FracTest01 += FracTest02;
    //std::cout << "(FracTest#1):" << FracTest01.ToOptimalString() << " (Should be 5 1/4)" << std::endl;
    //MediumDecFormulaData.MediumDecFormula = std::string("2.5^2");
    //MediumDec TestVar = 4;
    //boost::timer::auto_cpu_timer time;
    ////TestVar = MediumDec::Sqrt(TestVar,4);//Success
    //TestVar = MediumDec::Sqrt(TestVar, 4);
    //time.stop();
    //std::cout << "(OperationTest): " << TestVar.ToString() <<". Operation took "<< time.elapsed().wall<< std::endl;
    //TestVar = "3";
    //time.start();
    //TestVar = TestVar.Pow(5);//Success
    //time.stop();
    //std::cout << "(OperationTest): " << TestVar.ToString() << ". Operation took " << time.elapsed().wall << std::endl;
    //TestVar = 3;
    //time.start();
    //TestVar = MediumDec::Exp(TestVar);
    //time.stop();
    //std::cout << "(OperationTest): " << TestVar.ToString() << ". Operation took " << time.elapsed().wall << std::endl;
    //boost::timer::auto_cpu_timer time;
    //TestVar = 2;
    //ExpVar = "1.5";
    //TestVar.PowOp(ExpVar);
    //time.stop();
    //std::cout << "(2toPowerOf1.5):" << TestVar.ToString() << " (Should be equal to about 2.8284271247461900976033774484194) function took "<< time.format_string()<< std::endl;
    //TestVar = 2;
    //ExpVar = "1.5";
    //TestVar = TestVar.PowOpV2(ExpVar);
    //std::cout << "(PowTestV2):" << TestVar.ToString() << std::endl;
    //TestVar = TestVar.NthRootOp(ExpVar,MediumDec::OneMillionth);
    //std::cout << "(nthRootTest#1):" << TestVar.ToString() << std::endl;//fails
    //TestVar = 2;
    //ExpVar = "1.5";
    //TestVar = TestVar.NthRootV2Op(ExpVar, MediumDec::OneMillionth);
    //std::cout << "(nthRootTest#2):" << TestVar.ToString() << std::endl;//Failed


    //Comparison Tests
    MediumDec lVal = "-0.5";
    MediumDec rVal = "1.5";
    bool CompCheck = lVal < rVal;
    std::cout << lVal.ToString() << "<" << rVal.ToString() << " = " << CompCheck<<std::endl;
    //CompCheck = lVal == rVal;
    //std::cout << lVal.ToString() << "==" << rVal.ToString() << " = " << CompCheck << std::endl;
    CompCheck = lVal >= rVal;
    std::cout << lVal.ToString() << ">=" << rVal.ToString() << " = " << CompCheck << std::endl;
    CompCheck = lVal <= rVal;
    std::cout << lVal.ToString() << "<=" << rVal.ToString() << " = " << CompCheck << std::endl;
    lVal = 0;
    rVal = "1.5";
    CompCheck = lVal < rVal;
    std::cout << lVal.ToString() << "<" << rVal.ToString() << " = " << CompCheck << std::endl;
    //CompCheck = lVal == rVal;
    //std::cout << lVal.ToString() << "==" << rVal.ToString() << " = " << CompCheck << std::endl;
    CompCheck = lVal >= rVal;
    std::cout << lVal.ToString() << ">=" << rVal.ToString() << " = " << CompCheck << std::endl;
    CompCheck = lVal <= rVal;
    std::cout << lVal.ToString() << "<=" << rVal.ToString() << " = " << CompCheck << std::endl;
    lVal = 2;
    rVal = "1.5";
    CompCheck = lVal < rVal;
    std::cout << lVal.ToString() << "<" << rVal.ToString() << " = " << CompCheck << std::endl;
    //CompCheck = lVal == rVal;
    //std::cout << lVal.ToString() << "==" << rVal.ToString() << " = " << CompCheck << std::endl;
    CompCheck = lVal >= rVal;
    std::cout << lVal.ToString() << ">=" << rVal.ToString() << " = " << CompCheck << std::endl;
    CompCheck = lVal <= rVal;
    std::cout << lVal.ToString() << "<=" << rVal.ToString() << " = " << CompCheck << std::endl;
    //3rd of 27 = 3
    lVal = 27;
    lVal = MediumDec::NthRoot(lVal, 3);
    std::cout << "(nthRoot Test#1)" << lVal.ToString() << std::endl;//failed
    lVal = 27;
    lVal = MediumDec::NthRootV2(lVal, 3);
    std::cout << "(nthRoot Test#2)" << lVal.ToString() << std::endl;//failed
    lVal = 27;
    lVal = MediumDec::NthRootV3(lVal, 3);
    std::cout << "(nthRoot Test#3)" << lVal.ToString() << std::endl;//failed
}
