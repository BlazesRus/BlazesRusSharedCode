// ExprFormulaTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "AltNum\MediumDec.hpp"
//#include <boost/timer/timer.hpp>
using MediumDec = BlazesRusCode::MediumDec;

#include "AltNum\AltNumDebug.hpp"
#include "AltNum\FloatingOperations.hpp"
#include "Formulas\MediumDecFormula.hpp"
using MediumDecFormula = BlazesRusCode::MediumDecFormula;
//#include "Databases\IntFormula.hpp"
//using IntFormula = BlazesRusCode::IntFormula;
//#include "Databases\DoubleFormula.hpp"
//using DoubleFormula = BlazesRusCode::DoubleFormula;

int main()
{
#ifdef BlazesRus_PerformMediumFormulaTests
    MediumDec targetVal;// = "5.5";
    MediumDec rightVal;// = "1.25";
    MediumDec altResult; //= targetVal - rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << std::endl;
    //altResult = targetVal + rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << std::endl;

    //altResult = targetVal*rightVal;
    //double floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:"<<floatingVal<< std::endl;
    //altResult = targetVal/rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - 3;
    //std::cout << targetVal.ToString() << " - 3 = " << altResult.ToString() << std::endl;
    //altResult = targetVal + 3;
    //std::cout << targetVal.ToString() << " + 3 = " << altResult.ToString() << std::endl;
    //altResult = targetVal * 3;
    //std::cout << targetVal.ToString() << " * 3 = " << altResult.ToString() << std::endl;
    //altResult = targetVal / 3;
    //std::cout << targetVal.ToString() << " / 3 = " << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult -= rightVal;
    //std::cout << targetVal.ToString() << " -= :" << rightVal.ToString() << " = " << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult += rightVal;
    //std::cout << targetVal.ToString() << " += :" << rightVal.ToString() << " = " << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult *= rightVal;
    //std::cout << targetVal.ToString() << " *= :" << rightVal.ToString() << " = " << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult /= rightVal;
    //std::cout << targetVal.ToString() << " /= :" << rightVal.ToString() << " = " << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult -= 3;
    //std::cout << targetVal.ToString() << " -= 3 :" << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult += 3;
    //std::cout << targetVal.ToString() << " += 3 :" << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult *= 3;
    //std::cout << targetVal.ToString() << " *= 3 :" << altResult.ToString() << std::endl;
    //altResult = targetVal; altResult /= 3;
    //std::cout << targetVal.ToString() << " /= 3 : " << altResult.ToString() << std::endl;
    //bool boolCheck = targetVal < rightVal;
    //std::cout << targetVal.ToString() << " < " << rightVal.ToString() << " = " << boolCheck << std::endl;
    //boolCheck = targetVal <= rightVal;
    //std::cout << targetVal.ToString() << " <= " << rightVal.ToString() << " = " << boolCheck << std::endl;
    //boolCheck = targetVal > rightVal;
    //std::cout << targetVal.ToString() << " > " << rightVal.ToString() << " = " << boolCheck << std::endl;
    //boolCheck = targetVal >= rightVal;
    //std::cout << targetVal.ToString() << " >= " << rightVal.ToString() << " = " << boolCheck << std::endl;
    ////-----------------------------------------------------------------------------------------------------------
    ////All multiplication & Division tests now successful
    //targetVal = "0.5";
    //rightVal = "0.25";
    //altResult = targetVal * rightVal;
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal / rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //targetVal = "1.5";
    //altResult = targetVal * rightVal;
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal / rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //targetVal = "0.5";
    //rightVal = "2.5";
    //altResult = targetVal * rightVal;
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal / rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //rightVal = "2.0";
    //altResult = targetVal * rightVal;
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal / rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //targetVal = "4.0";
    //rightVal = "2.0";
    //altResult = targetVal * rightVal;
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal / rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //rightVal = "0.5";
    //altResult = targetVal * rightVal;
    //floatingVal = (double)targetVal * (double)rightVal;
    //std::cout << targetVal.ToString() << " * " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal / rightVal;
    //floatingVal = (double)targetVal / (double)rightVal;
    //std::cout << targetVal.ToString() << " / " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //std::cout << "------Additional Addition/Subtraction Tests(For Negative numbers etc)--------------------" << std::endl;

    //targetVal = "-0.5";
    //rightVal = "-0.25";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //rightVal = "0.25";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //targetVal = "-1.5";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //targetVal = "-0.5";
    //rightVal = "-2.5";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //rightVal = "2.5";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;


    //rightVal = "-2.0";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;


    //targetVal = "-4.0";
    //rightVal = "-2.0";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //rightVal = "0.5";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //rightVal = "-0.5";
    //altResult = targetVal + rightVal;
    //floatingVal = (double)targetVal + (double)rightVal;
    //std::cout << targetVal.ToString() << " + " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;
    //altResult = targetVal - rightVal;
    //floatingVal = (double)targetVal - (double)rightVal;
    //std::cout << targetVal.ToString() << " - " << rightVal.ToString() << " = " << altResult.ToString() << " FloatResult:" << floatingVal << std::endl;

    //std::cout << "---------------Log Tests------------------------------" << std::endl;
    //targetVal = MediumDec::FiveThousandth;
    //floatingVal = 0.005;
    //double floatingRes;
    //do 
    //{
    //    floatingRes = log(floatingVal);
    //    std::cout << "Builtin-Ln(" << floatingVal << ") = " << floatingRes;
    //    floatingRes = BlazesFloatingCode::LnRefV2(floatingVal);
    //    std::cout << " Ln(value) =" << floatingRes << std::endl;

    //    altResult = MediumDec::LnRef(targetVal);
    //    std::cout << "(MediumDec)Ln(" << targetVal.ToString() << ")= " << altResult.ToString() << std::endl;
    //    altResult = MediumDec::LnRefV2(targetVal);
    //    std::cout << "(MediumDec)LnV2(" << targetVal.ToString() << ")= " << altResult.ToString() << std::endl;
    //    targetVal += MediumDec::FiveThousandth; floatingVal += 0.005;
    //} while (targetVal < MediumDec::One);
    std::cout << "---------------Testing Formula Code-------------------" << std::endl;
    //std::cout << "-------------------------Formula Code Tests---------------------------------" << std::endl;
    //IntFormula IntFormTest = "(5+5)^2";
    //tsl::ordered_map<std::string, int> IntValueDefinitions;
    //std::cout << IntFormTest.ToString() << " = " << IntFormTest.EvalValues(IntValueDefinitions) << std::endl;
    //IntValueDefinitions.insert_or_assign("x", 2);
    //IntFormTest = "5+10x";
    //std::cout << IntFormTest.ToString() << " = " << IntFormTest.EvalValues(IntValueDefinitions) << std::endl;

    tsl::ordered_map<std::string, MediumDec> ValueDefinitions;
    ValueDefinitions.insert_or_assign("x", MediumDec::Two);
    MediumDecFormula AltFormTest = "x+x";//"(x+1)^(5+4)";

    try
    {
        std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << std::endl;
        AltFormTest.ReplaceVariablesWithValues(ValueDefinitions);
        std::cout << " = " << AltFormTest.ToString() << std::endl;
        AltFormTest.EvaluateOperations();
        std::cout << " = " << AltFormTest.ToString() << std::endl;

        //AltFormTest = "9.0 thBaseLog 4";
        //std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << std::endl;
        //AltFormTest.ReplaceVariablesWithValues(ValueDefinitions);
        //std::cout << " = " << AltFormTest.ToString() << std::endl;
        //AltFormTest.EvaluateOperations();
        //std::cout << " = " << AltFormTest.ToString() << std::endl;

        AltFormTest = "(x+1)^(5+4/0.5-2)";
        std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << std::endl;
        AltFormTest.ReplaceVariablesWithValues(ValueDefinitions);
        std::cout << " = " << AltFormTest.ToString() << std::endl;
        AltFormTest.EvaluateOperations();
        std::cout << " = " << AltFormTest.ToString() << std::endl;

        AltFormTest = "(x+1)^(5+4*0.5-2)";
        std::cout << "(MediumDecFormula) " << AltFormTest.ToString() << std::endl;
        AltFormTest.ReplaceVariablesWithValues(ValueDefinitions);
        std::cout << " = " << AltFormTest.ToString() << std::endl;
        AltFormTest.EvaluateOperations();
        std::cout << " = " << AltFormTest.ToString() << std::endl;
    }
    catch (const std::runtime_error& re)
    {
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        // specific handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown exception" << std::endl;
    }
#endif
}
