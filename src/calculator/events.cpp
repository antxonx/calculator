/**
 * Handle envents
 */
#include <calculator.hh>

using namespace Calculator;

void CalculatorWindow::onExit(wxCommandEvent &_)
{
    _.GetId();
    this->Close(true);
}

void CalculatorWindow::onClick(wxCommandEvent &event)
{
    wxString newValue;
    wxButton *button = wxDynamicCast(event.GetEventObject(), wxButton);
    wxString actualValue = this->display->GetValue();
    //Which button
    switch (button->GetId())
    {
    case CALC_CLS:
        //clear screen and reset
        this->clearScreen();
        this->stored = 0.0;
        this->oper = OP_NONE;
        break;
    case CALC_BACK:
        if (this->isDisplayOneDigit())
        {
            //clear screen if one digit
            this->clearScreen();
        }
        else
        {
            //else just remove las character
            char deleted = actualValue.Last();
            //Change decimalPoint state if needed
            if (deleted == DISPLAY_DECIMAL)
            {
                this->decimalPoint = false;
            }
            newValue = actualValue.substr(0, actualValue.length() - 1);
            this->display->ChangeValue(newValue);
            if (this->isDisplayZero())
            {
                this->clearScreen();
            }
        }
        break;
    case CALC_POINT:
        //add decimal point if not added before
        if (!this->decimalPoint)
        {
            newValue = this->display->GetValue() + DISPLAY_DECIMAL;
            this->display->ChangeValue(newValue);
            this->decimalPoint = true;
        }
        break;
    case CALC_DIV:
        //operate and set operation
        this->operate();
        this->newValue = true;
        this->oper = OP_DIV;
        break;
    case CALC_TIMES:
        //operate and set operation
        this->operate();
        this->newValue = true;
        this->oper = OP_TIMES;
        break;
    case CALC_MINUS:
        //operate and set operation
        this->operate();
        this->newValue = true;
        this->oper = OP_SUB;
        break;
    case CALC_PLUS:
        //operate and set operation
        this->operate();
        this->newValue = true;
        this->oper = OP_ADD;
        break;
    case CALC_EQUAL:
        //operate and reset operation
        if (!this->oper == OP_NONE)
        {
            this->operate();
        }
        this->oper = OP_NONE;
        break;
    case CALC_NEGATIVE://if not zero
        if (!this->isDisplayZero())
        {
            //change negative symbol
            if (this->negative)
            {
                newValue = actualValue.substr(1, actualValue.length());
            }
            else
            {
                newValue = "-" + this->display->GetValue();
            }
            this->negative = !this->negative;
            this->display->ChangeValue(newValue);
        }
        break;
    case CALC_SQUARE_ROOT:
        //operate and set operation
        this->oper = OP_SQ_ROOT;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    break;   
    case CALC_SQUARE_EXP:
        //operate and set operation
        this->oper = OP_SQ_EXP;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    break;
    case CALC_LOG:
        //operate and set operation
        this->oper = OP_LOG;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_ANTILOG:
        //operate and set operation
        this->oper = OP_ANTILOG;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_SIN:
        //operate and set operation
        this->oper = OP_SIN;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_COS:
        //operate and set operation
        this->oper = OP_COS;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_TAN:
        //operate and set operation
        this->oper = OP_TAN;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_ARCSIN:
        //operate and set operation
        this->oper = OP_ARCSIN;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_ARCTAN:
        //operate and set operation
        this->oper = OP_ARCTAN;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_ARCCOS:
        //operate and set operation
        this->oper = OP_ARCCOS;
        this->operate();
        this->oper = OP_NONE;
        this->newValue = true;
        break;
    case CALC_DEG_RAD:
        this->degrees = !this->degrees;
        if(this->degrees) {
            this->degRad->SetLabelText(DISPLAY_DEG);
        } else {
            this->degRad->SetLabelText(DISPLAY_RAD);
        }
        break;
    default:
        //number buttom
        if (this->newValue)
        {
            //rewrite screen after operation
            this->clearScreen();
        }
        if (this->isDisplayZero())
        {
            //no left trailing zeros
            this->display->ChangeValue(button->GetLabelText());
        }
        else
        {
            //add number to the right
            newValue = this->display->GetValue() + button->GetLabelText();
            this->display->ChangeValue(newValue);
        }
        this->newValue = false;
        break;
    }
}