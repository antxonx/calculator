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

void CalculatorWindow::build()
{
    wxButton *button;
    //Font size
    wxFont font = wxFont(wxFontInfo(DISPLAY_FONT_SIZE + 10));
    //Container
    this->box = new wxBoxSizer(wxVERTICAL);
    //Display element
    this->display = new wxTextCtrl(this, DISPLAY_ID, DISPLAY_ZERO, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY);
    this->display->SetFont(font);
    //Add displey to container
    this->box->Add(this->display, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);
    //Grid element for buttons
    this->grid = new wxGridSizer(6, 4, 3, 3);
    //Buttons definitions
    //1->
    this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    button = new wxButton(this, CALC_CLS, "C");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_BACK, L"\u232B");
    button->SetFont(wxFont(wxFontInfo(DISPLAY_FONT_SIZE)));
    this->grid->Add(button, 0, wxEXPAND);
    //<-1
    //2->
    this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    button = new wxButton(this, CALC_SQUARE_EXP, L"x\u00B2");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_SQUARE_ROOT, L"\u221A");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_DIV, "/");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-2
    //3->
    button = new wxButton(this, CALC_7, "7");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_8, "8");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_9, "9");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_TIMES, "*");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-3
    //4->
    button = new wxButton(this, CALC_4, "4");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_5, "5");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_6, "6");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_MINUS, "-");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-4
    //5->
    button = new wxButton(this, CALC_1, "1");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_2, "2");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_3, "3");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_PLUS, "+");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-5
    //6->
    button = new wxButton(this, CALC_NEGATIVE, "+/-");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_0, Calculator::DISPLAY_ZERO);
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_POINT, ".");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_EQUAL, "=");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-6
    //Add buttons grid to container
    this->box->Add(this->grid, 1, wxEXPAND);
    this->SetSizer(this->box);
    this->SetMinSize(this->size);
    this->Centre();
    //Handle events
    this->Bind(wxEVT_MENU, &CalculatorWindow::onExit, this, wxID_EXIT);
    for (const Calculator::OPTIONS OPT : All)
    {
        this->Bind(wxEVT_BUTTON, &CalculatorWindow::onClick, this, OPT);
    }
}

void CalculatorWindow::onExit(wxCommandEvent &_)
{
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
        this->newValue = true;
        break;
    break;   
    case CALC_SQUARE_EXP:
        //operate and set operation
        this->oper = OP_SQ_EXP;
        this->operate();
        this->newValue = true;
        break;
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

void CalculatorWindow::operate()
{
    double screenValue;
    char output[DISPLAY_BURFFER_SIZE], preoutput[DISPLAY_BURFFER_SIZE];
    int i;
    this->decimalPoint = false;
    //get display as double
    this->display->GetValue().ToDouble(&screenValue);
    //asm lib
    switch (this->oper)
    {
    case OP_ADD:
        this->stored = add(this->stored, screenValue);
        break;
    case OP_SUB:
        this->stored = sub(this->stored, screenValue);
        break;
    case OP_TIMES:
        this->stored = mul(this->stored, screenValue);
        break;
    case OP_DIV:
        this->stored = div(this->stored, screenValue);
        break;
    case OP_SQ_ROOT:
        this->stored = sqrt(screenValue);
        break;
    case OP_SQ_EXP:
        this->stored = sqexp(screenValue);
        break;            
    default:
        this->stored = screenValue;
        break;
    }
    //stringify the result
    strncpy(preoutput, wxString::Format("%f", this->stored).mb_str().data(), DISPLAY_BURFFER_SIZE);
    //remove trailing right zeros
    for (i = DISPLAY_BURFFER_SIZE - 1; i >= 0; i--)
    {
        this->decimalPoint = (preoutput[i] != '0' && preoutput[i] != 0 && preoutput[i] != '.');
        if (preoutput[i] == '.' || this->decimalPoint)
        {
            break;
        }
    }
    //if there is a decimal value we add one character, else we don't take the decimal point
    if (this->decimalPoint)
    {
        i++;
    }
    //clear output
    strncpy(output, preoutput, i);
    //end of string
    output[i] = 0;
    //set negative if needed
    this->negative = (output[0] == '-');
    //update screen
    this->display->ChangeValue(output);
}