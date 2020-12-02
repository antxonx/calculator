#ifndef CALC_MATH_TRIGONOMETRIC_HH
#define CALC_MATH_TRIGONOMETRIC_HH
#define CALC_PI 3.14159265358979323846

namespace Calculator 
{
    extern "C" double sin(double);
    extern "C" double cos(double);
    extern "C" double tan(double);
    extern "C" double arcsin(double);
    extern "C" double arctan(double);
    extern "C" double arccos(double);
    extern "C" double degreesToRadians(double);
    extern "C" double radiansToDegrees(double);
}

#endif