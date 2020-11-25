#include <calculator.h>

using namespace Calculator;

CalculatorWindow::CalculatorWindow(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    const int DISPLAY_id = 100;
    this->negative = false;
    this->decimalPoint = false;
    //Font size
    wxFont font = wxFont(wxFontInfo(20));
    //Container
    box = new wxBoxSizer(wxVERTICAL);
    //Display element
    display = new wxTextCtrl(this, DISPLAY_id, DISPLAY_ZERO, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);
    display->SetFont(font);
    //Add displey to container
    box->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);
    //Grid element for buttons
    grid = new wxGridSizer(5, 4, 3, 3);
    //Buttons definitions
    grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_CLS, "CLS"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_BACK, "<-"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_7, "7"), 0, wxEXPAND); 
    grid->Add(new wxButton(this, CALC_8, "8"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_9, "9"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_DIV, "/"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_4, "4"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_5, "5"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_6, "6"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_TIMES, "*"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_1, "1"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_2, "2"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_3, "3"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_MINUS, "-"), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_0, Calculator::DISPLAY_ZERO), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_POINT, "."), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_EQUAL, "="), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_PLUS, "+"), 0, wxEXPAND);
    //Add buttons grid to container
    box->Add(grid, 1, wxEXPAND);
    this->SetSizer(box);
    this->SetMinSize(size);
    this->Centre();
    //Handle events
    this->Bind(wxEVT_MENU, &CalculatorWindow::onExit, this, wxID_EXIT);
    //this->Bind(wxEVT_TEXT, &CalculatorWindow::onInput, this, DISPLAY_id);
    for(const Calculator::OPTIONS OPT : All){
        this->Bind(wxEVT_BUTTON, &CalculatorWindow::onClick, this, OPT);
    }
}

void CalculatorWindow::onExit(wxCommandEvent &event)
{
    this->Close(true);
}

void CalculatorWindow::onInput(wxCommandEvent &event)
{
    
}

void CalculatorWindow::onClick(wxCommandEvent &event) 
{
    wxString newValue;
    wxButton *button = wxDynamicCast(event.GetEventObject(), wxButton);
    switch (button->GetId())
    {
    case CALC_CLS:
        /* code */
        break;
    case CALC_BACK:
        /* code */
        break;
    case CALC_DIV:
        /* code */
        break;
    case CALC_TIMES:
        /* code */
        break;
    case CALC_MINUS:
        /* code */
        break;
    case CALC_POINT:
        if(!this->decimalPoint) {
            newValue = this->display->GetValue() + ".";
            this->display->ChangeValue(newValue);
            this->decimalPoint = true;
        }
        break;
    case CALC_EQUAL:
        /* code */
        break;
    case CALC_PLUS:
        /* code */
        break;
    default:
        newValue = this->display->GetValue() + button->GetLabelText();
        this->display->ChangeValue(newValue);
        break;
    }
}