#ifndef CALC_MATH_ARITH_HH
#define CALC_MATH_ARITH_HH

namespace Calculator
{
    extern "C" double add(double operand1, double operand2);
    extern "C" double sub(double operand1, double operand2);
    extern "C" double mul(double operand1, double operand2);
    extern "C" double div(double operand1, double operand2);
} // namespace Calculator

#endif