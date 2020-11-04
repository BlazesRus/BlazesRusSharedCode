// ExprFormulaTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "AltNum\MediumDec.hpp"
//#include <boost/timer/timer.hpp>
using MediumDec = BlazesRusCode::MediumDec;

#include "AltNum\AltNumDebug.hpp"
#include "AltNum\FloatingOperations.hpp"
#include "Databases\MediumDecFormula.hpp"
using MediumDecFormula = BlazesRusCode::MediumDecFormula;
//#include "Databases\ExprFormula.h"
//using ExprFormula = BlazesRusCode::ExprFormula;
//#include "Databases\IntFormula.hpp"
//using IntFormula = BlazesRusCode::IntFormula;
//#include "Databases\DoubleFormula.hpp"
//using DoubleFormula = BlazesRusCode::DoubleFormula;

//#include <parallel_hashmap/phmap.h>
//using ParallelIntValMap = phmap::node_hash_map<int, MediumDec>;
//using ParallelStringValMap = phmap::node_hash_map<std::string, MediumDec>;
//using ParallelStringIntMap = phmap::node_hash_map<std::string, int>;

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
    targetVal = "0.005";
    floatingVal = 0.005;
    std::cout << "---------------Log Tests------------------------------" << std::endl;
    double floatingRes;
    for (targetVal = MediumDec::FiveThousandth; targetVal<MediumDec::One; targetVal += MediumDec::FiveThousandth)
    {
        floatingRes = log(floatingVal);
        std::cout << "Builtin-Ln(" << floatingVal << ") = " << floatingRes;
        floatingRes = BlazesFloatingCode::LnRef(floatingVal);
        std::cout << " Ln(value) =" << floatingRes << std::endl;
        floatingVal += 0.005;
        rootTest = MediumDec::Ln(targetVal);
        std::cout << "(MediumDec)Ln(" << targetVal.ToString()<<")= " <<rootTest.ToString() << std::endl;
    }

    std::cout << "---------------Testing Formula Code-------------------" << std::endl;
    //std::cout << "-------------------------Formula Code Tests---------------------------------" << std::endl;
    //IntFormula IntFormTest = "(5+5)^2";
    //tsl::ordered_map<std::string, int> IntValueDefinitions;
    //std::cout << IntFormTest.ToString() << " = " << IntFormTest.EvalValues(IntValueDefinitions) << std::endl;
    //IntValueDefinitions.insert_or_assign("x", 2);
    //IntFormTest = "5+10x";
    //std::cout << IntFormTest.ToString() << " = " << IntFormTest.EvalValues(IntValueDefinitions) << std::endl;

    MediumDecFormula AltFormTest = "5.5^(1.5+x)+6x";

    //tsl::ordered_map<std::string, MediumDec&> RefDefinitions;
    //MediumDec XReference = MediumDec::One;
    //RefDefinitions.insert_or_assign("x", XReference);
    //rootTest = AltFormTest.EvalValueRefs(RefDefinitions);
    //std::cout << AltFormTest.ToString() << " = " << rootTest.ToString()<< std::endl;

    //tsl::ordered_map<std::string, MediumDec> ValueDefinitions;
    //ValueDefinitions.insert_or_assign("x", MediumDec::One);
    //rootTest = AltFormTest.EvalValues(ValueDefinitions);
    std::cout << "(MediumDecFormula) "<< AltFormTest.ToString() <<std::endl;
    //std::cout << " = " << rootTest.ToString() << std::endl;
    //AltFormTest = "5+5";
    //std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << " = " << rootTest.ToString() << std::endl;
    //AltFormTest = "5+(5/4)";
    //std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << " = " << rootTest.ToString() << std::endl;
    //AltFormTest = "(4/3)/2";
    //std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << " = " << rootTest.ToString() << std::endl;


    //DoubleFormula DoubleFormTest = "5.5+(5.5+2)";
    //std::cout << "(DoubleFormula) " << DoubleFormTest.ToString() << std::endl;
}
