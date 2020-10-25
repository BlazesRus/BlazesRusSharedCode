// ExprFormulaTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//#include "AltNum\AltDec.hpp"
#include "AltNum\MediumDec.hpp"
//#include "Databases\MediumDecFormula.hpp"
//#include <boost/timer/timer.hpp>
using MediumDec = BlazesRusCode::MediumDec;

#include "AltNum\AltNumDebug.hpp"
#include "AltNum\FloatingOperations.hpp"
#include "Databases\IntFormula.h"
#include "Databases\MediumDecFormula.hpp"
using MediumDecFormula = BlazesRusCode::MediumDecFormulaData::MediumDecFormula;

int main()
{
    MediumDec targetVal = "5.5";
    MediumDec rightVal = "1.25";
    MediumDec resDiff = targetVal - rightVal;
    std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal + rightVal;
    std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;

    resDiff = targetVal*rightVal;
    double floatingVal = (double)targetVal * (double)rightVal;
    std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:"<<floatingVal<< std::endl;
    resDiff = targetVal/rightVal;
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = targetVal - 3;
    std::cout << targetVal.ToString() << " - 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal + 3;
    std::cout << targetVal.ToString() << " + 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal * 3;
    std::cout << targetVal.ToString() << " * 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal / 3;
    std::cout << targetVal.ToString() << " / 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff -= rightVal;
    std::cout << targetVal.ToString() << " -= :" << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff += rightVal;
    std::cout << targetVal.ToString() << " += :" << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff *= rightVal;
    std::cout << targetVal.ToString() << " *= :" << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff /= rightVal;
    std::cout << targetVal.ToString() << " /= :" << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff -= 3;
    std::cout << targetVal.ToString() << " -= 3 :" << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff += 3;
    std::cout << targetVal.ToString() << " += 3 :" << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff *= 3;
    std::cout << targetVal.ToString() << " *= 3 :" << resDiff.ToString() << std::endl;
    resDiff = targetVal; resDiff /= 3;
    std::cout << targetVal.ToString() << " /= 3 : " << resDiff.ToString() << std::endl;
    bool boolCheck = targetVal < rightVal;
    std::cout << targetVal.ToString() << " < " << rightVal.ToString() << " = " << boolCheck << std::endl;
    boolCheck = targetVal <= rightVal;
    std::cout << targetVal.ToString() << " <= " << rightVal.ToString() << " = " << boolCheck << std::endl;
    boolCheck = targetVal > rightVal;
    std::cout << targetVal.ToString() << " > " << rightVal.ToString() << " = " << boolCheck << std::endl;
    boolCheck = targetVal >= rightVal;
    std::cout << targetVal.ToString() << " >= " << rightVal.ToString() << " = " << boolCheck << std::endl;
    //-----------------------------------------------------------------------------------------------------------
    //All multiplication & Division tests now successful
    /*
    targetVal = "0.5";
    rightVal = "0.25";
    //resDiff = BlazesRusDebug::MultOp(targetVal, rightVal);
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = BlazesRusDebug::DivOp(targetVal, rightVal);
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;

    targetVal = "1.5";
    //resDiff = BlazesRusDebug::MultOp(targetVal, rightVal);
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = BlazesRusDebug::DivOp(targetVal, rightVal);
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;

    targetVal = "0.5";
    rightVal = "2.5";
    //resDiff = BlazesRusDebug::MultOp(targetVal, rightVal);
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = BlazesRusDebug::DivOp(targetVal, rightVal);
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;//Success

    rightVal = "2.0";
    //resDiff = BlazesRusDebug::MultOp(targetVal, rightVal);
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = BlazesRusDebug::DivOp(targetVal, rightVal);
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;//Success

    targetVal = "4.0";
    rightVal = "2.0";
    //resDiff = BlazesRusDebug::MultOp(targetVal, rightVal);
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = BlazesRusDebug::DivOp(targetVal, rightVal);
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;//Success

    rightVal = "0.5";
    //resDiff = BlazesRusDebug::MultOp(targetVal, rightVal);
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    resDiff = BlazesRusDebug::DivOp(targetVal, rightVal);
    floatingVal = (double)targetVal / (double)rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << " FloatResult:" << floatingVal << std::endl;
    */
    //-----------------------------------------------------------------------------------------------------------
    targetVal = 3;
    MediumDec rootTest;
    floatingVal;
    //for(int expValue=0;expValue<19;++expValue)//Successful calculations of power of (Integer) with zero inaccuracy for these test iterations in loop
    //{
    //    rootTest = MediumDec::Pow(targetVal, expValue);
    //    floatingVal = BlazesFloatingCode::Pow(3.0, expValue);//built-in pow(3.0, expValue) fails so using alternative
    //    resDiff = (MediumDec)floatingVal;
    //    resDiff -= rootTest;
    //    std::cout << "3 ^ "<<expValue<<" Result:"<< rootTest.ToString()<<" FloatingResult: "<< floatingVal <<" DifFromFloating:" << resDiff.ToString() << std::endl;
    //}
    //targetVal = "5.25";
    //rootTest = BlazesRusDebug::Exp(targetVal);//Exp(5.2) Accuracy only off by 0.000000230... compared to high precision calculator (though more accurate then displayed double floating point based calculation)
    //floatingVal = exp(5.25);
    //std::cout << "Exp(" << targetVal.ToString() << ") = " << rootTest.ToString() << " FloatingResult:" << floatingVal << std::endl;

    targetVal = 5;
    /*
    //-----------------Both V3 and geekforgeeks variations of code successful at same level of accuracy(matching the rounded double operation)
    floatingVal = BlazesFloatingCode::NthRootV3(5.0, 4);
    
    //rootTest = BlazesRusDebug::NthRootV1(targetVal, 4);
    //std::cout << "(V1)4th root of " << targetVal.ToString() << "= " << rootTest.ToString() << std::endl;
    rootTest = BlazesRusDebug::NthRootV5(targetVal, 4);
    std::cout << "(V5)4th root of " << targetVal.ToString() << "= " << rootTest.ToString()<<std::endl;
    //rootTest = BlazesRusDebug::NthRootV4(targetVal, 4);
    //std::cout << "(V4)4th root of " << targetVal.ToString() << "= " << rootTest.ToString()<<std::endl;
 
    rootTest = MediumDec::NthRoot(targetVal, 4);
    std::cout << "4th root of " << targetVal.ToString() <<"= " << rootTest.ToString()  << std::endl;
    std::cout << "Floating 4th root of" << (double)targetVal << "= " << floatingVal<< std::endl;
    */
    //----------------------------------------------------------------------
    rootTest = BlazesRusDebug::LnV2(targetVal);
    std::cout << "Ln(" << targetVal.ToString() << ") = " << rootTest.ToString() << " FloatingResult:" << log((double)targetVal) << std::endl;
    rightVal = "0.25";
    floatingVal = pow(5.0, 0.25);
    rootTest = MediumDec::Pow(targetVal, rightVal);
    std::cout << targetVal.ToString() << "^" << rightVal.ToString() << " = " << rootTest.ToString() << " FloatingResult:" << floatingVal << std::endl;
    //---------------Log Tests------------------------------
    targetVal = "1.5";
    rightVal = 5;
    rootTest = BlazesRusDebug::LnV2(targetVal);
    std::cout << "Ln(" << targetVal.ToString() << ") = " << rootTest.ToString() << " FloatingResult:" << log(1.5) << std::endl;
    //---------------Testing Formula Code-------------------
    IntFormula IntFormTest("(5+5)^2");
    std::map<std::string, int> IntValueDefinitions;
    std::cout << IntFormTest.ToString() << " = " << IntFormTest.EvalValues(IntValueDefinitions) << std::endl;
    IntValueDefinitions.insert_or_assign("x", 2);
    IntFormTest = "5+10x";
    std::cout << IntFormTest.ToString() << " = " << IntFormTest.EvalValues(IntValueDefinitions) << std::endl;
    MediumDecFormula AltFormTest = MediumDecFormula("5.5^(1.5+x)+6x");
    std::map<std::string, MediumDec&> ValueDefinitions;
    MediumDec XReference = MediumDec::One;
    ValueDefinitions.insert_or_assign("x", XReference);
    rootTest = AltFormTest.EvalValueRefs(ValueDefinitions);
    std::cout << AltFormTest.ToString() << " = " << rootTest.ToString()<< std::endl;
    std::map<std::string, MediumDec> ValueDefinitions02;
    ValueDefinitions02.insert_or_assign("x", "0.5");
    //------------------------------------------------------------------------------------------------
    //rootTest = MediumDec::Log(targetVal, rightVal);
    //floatingVal = log(5.0) / log(5.0);
    //std::cout << "log base_"<< rightVal.ToString() << "_of" << targetVal.ToString() << " = " << rootTest.ToString() << " FloatingResult:" << floatingVal << std::endl;
}
