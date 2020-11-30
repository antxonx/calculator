/**
 * Constructor and utilities
 */
#include <calculator.hh>

using namespace Calculator;

CalculatorWindow::CalculatorWindow(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    this->negative = false;
    this->decimalPoint = false;
    this->newValue = false;
    this->oper = OP_NONE;
    this->stored = 0.0;
    this->size = size;
    this->build();
}

void CalculatorWindow::clearScreen()
{
    //change display value to zero
    this->display->ChangeValue(DISPLAY_ZERO);
    this->decimalPoint = false;
    this->negative = false;
}

bool CalculatorWindow::isDisplayZero()
{
    if (this->isDisplayOneDigit())
    {
        if (this->negative)
        {
            //avoid "-0"
            return (this->display->GetValue().IsSameAs("-" + DISPLAY_ZERO));
        }
        else
        {
            return (this->display->GetValue().IsSameAs(DISPLAY_ZERO));
        }
    }
    else
    {
        return false;
    }
}

bool CalculatorWindow::isDisplayOneDigit()
{
    if (this->negative)
    {
        return (this->display->GetValue().length() < 3);
    }
    else
    {
        return (this->display->GetValue().length() < 2);
    }
}