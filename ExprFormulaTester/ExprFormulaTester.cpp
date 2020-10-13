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

int main()
{
    MediumDec targetVal = "5.5";
    MediumDec rightVal = "1.25";
    MediumDec resDiff = targetVal - rightVal;
    std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal + rightVal;
    std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal * rightVal;
    std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal / rightVal;
    std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << resDiff.ToString() << std::endl;
    resDiff = targetVal - 3;
    std::cout << targetVal.ToString() << " - 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal + 3;
    std::cout << targetVal.ToString() << " + 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal * 3;
    std::cout << targetVal.ToString() << " * 3 = " << resDiff.ToString() << std::endl;
    resDiff = targetVal / 3;
    std::cout << targetVal.ToString() << " / 3 = " << resDiff.ToString() << std::endl;
    bool boolCheck = targetVal < rightVal;
    std::cout << targetVal.ToString() << " < " << rightVal.ToString() << " = " << boolCheck << std::endl;
    boolCheck = targetVal <= rightVal;
    std::cout << targetVal.ToString() << " <= " << rightVal.ToString() << " = " << boolCheck << std::endl;
    boolCheck = targetVal > rightVal;
    std::cout << targetVal.ToString() << " > " << rightVal.ToString() << " = " << boolCheck << std::endl;
    boolCheck = targetVal >= rightVal;
    std::cout << targetVal.ToString() << " >= " << rightVal.ToString() << " = " << boolCheck << std::endl;
    targetVal = 3;
    MediumDec rootTest;
    double floatingVal;
    for(int expValue=0;expValue<19;++expValue)
    {
        rootTest = MediumDec::Pow(targetVal, expValue);
        floatingVal = BlazesFloatingCode::Pow(3.0, expValue);//built-in pow(3.0, expValue) fails so using alternative
        resDiff = (MediumDec)floatingVal;
        resDiff -= rootTest;
        std::cout << "3 ^ "<<expValue<<" Result:"<< rootTest.ToString()<<" FloatingResult: "<< floatingVal <<" DifFromFloating:" << resDiff.ToString() << std::endl;
    }
    targetVal = 5;
    floatingVal = BlazesFloatingCode::NthRootV3(5.0, 4);
    rootTest = BlazesRusDebug::NthRootV1(targetVal, 4);
    std::cout << "(V1)4th root of " << targetVal.ToString() << "= " << rootTest.ToString() << std::endl;
    rootTest = BlazesRusDebug::NthRootV5(targetVal, 4);
    std::cout << "(V5)4th root of " << targetVal.ToString() << "= " << rootTest.ToString()<<std::endl;
    rootTest = BlazesRusDebug::NthRootV4(targetVal, 4);
    std::cout << "(V4)4th root of " << targetVal.ToString() << "= " << rootTest.ToString()<<std::endl;
    rootTest = BlazesRusDebug::NthRootTest(targetVal, 4);
    std::cout << "4th root of " << targetVal.ToString() <<"= " << rootTest.ToString() << " FloatingResult:" << floatingVal << std::endl;
    rightVal = "0.25";
    rootTest = BlazesRusDebug::PowTest(targetVal, rightVal);
    floatingVal = pow(5.0, 0.25);
    std::cout << targetVal.ToString() << "^" << rightVal.ToString() << " = " << rootTest.ToString() <<" FloatingResult:"<< floatingVal << std::endl;
    //rootTest02 = MediumDec::FractionalPow(targetVal, 1, 4);
    //std::cout << "Fractional Power Result:" << rootTest << " compared to built-in calculation of:" << pow(5.0, 0.25) << std::endl;
}
