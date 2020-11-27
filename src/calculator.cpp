#include <calculator.hh>

using namespace Calculator;

CalculatorWindow::CalculatorWindow(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    wxButton *button;
    const int DISPLAY_id = 100;
    this->negative = false;
    this->decimalPoint = false;
    this->newValue = false;
    this->oper = OP_NONE;
    this->stored = 0.0;
    //Font size
    wxFont font = wxFont(wxFontInfo(DISPLAY_FONT_SIZE + 10));
    //Container
    this->box = new wxBoxSizer(wxVERTICAL);
    //Display element
    this->display = new wxTextCtrl(this, DISPLAY_id, DISPLAY_ZERO, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY);
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
    button = new wxButton(this, CALC_BACK, "<-");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-1
    //2->
    this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
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
    this->SetMinSize(size);
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
    switch (button->GetId())
    {
    case CALC_CLS:
        this->clearScreen();
        this->stored = 0.0;
        this->oper = OP_NONE;
        break;
    case CALC_BACK:
        if (this->isDisplayOneDigit())
        {
            this->clearScreen();
        }
        else
        {
            char deleted = actualValue.Last();
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
        if (!this->decimalPoint)
        {
            newValue = this->display->GetValue() + DISPLAY_DECIMAL;
            this->display->ChangeValue(newValue);
            this->decimalPoint = true;
        }
        break;
    case CALC_DIV:
        this->operate();
        this->newValue = true;
        this->oper = OP_DIV;
        break;
    case CALC_TIMES:
        this->operate();
        this->newValue = true;
        this->oper = OP_TIMES;
        break;
    case CALC_MINUS:
        this->operate();
        this->newValue = true;
        this->oper = OP_SUB;
        break;
    case CALC_PLUS:
        this->operate();
        this->newValue = true;
        this->oper = OP_ADD;
        break;
    case CALC_EQUAL:
        if (!this->oper == OP_NONE)
        {
            this->operate();
        }
        this->oper = OP_NONE;
        break;
    case CALC_NEGATIVE:
        if (!this->isDisplayZero())
        {
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
    default:
        if (this->newValue)
        {
            this->clearScreen();
        }
        if (this->isDisplayZero())
        {
            this->display->ChangeValue(button->GetLabelText());
        }
        else
        {
            newValue = this->display->GetValue() + button->GetLabelText();
            this->display->ChangeValue(newValue);
        }
        this->newValue = false;
        break;
    }
}

void CalculatorWindow::clearScreen()
{
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
    this->display->GetValue().ToDouble(&screenValue);
    switch (this->oper)
    {
    case OP_ADD:
        this->stored = add(this->stored, screenValue);
        break;
    case OP_SUB:
        this->stored = this->stored - screenValue;
        break;
    case OP_TIMES:
        this->stored = this->stored * screenValue;
        break;
    case OP_DIV:
        this->stored = this->stored / screenValue;
        break;
    default:
        this->stored = screenValue;
        break;
    }
    strncpy(preoutput, wxString::Format("%f", this->stored).mb_str().data(), DISPLAY_BURFFER_SIZE);
    for (i = DISPLAY_BURFFER_SIZE - 1; i >= 0; i--)
    {
        this->decimalPoint = (preoutput[i] != '0' && preoutput[i] != 0 && preoutput[i] != '.');
        if (preoutput[i] == '.' || this->decimalPoint)
        {
            break;
        }
    }
    if (this->decimalPoint)
    {
        i++;
    }
    strncpy(output, preoutput, i);
    output[i] = 0;
    this->negative = (output[0] == '-');
    this->display->ChangeValue(output);
}