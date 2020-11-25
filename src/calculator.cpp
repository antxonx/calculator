#include <calculator.h>

using namespace Calculator;

CalculatorWindow::CalculatorWindow(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    //Font size
    wxFont font = wxFont(wxFontInfo(20));
    //Container
    box = new wxBoxSizer(wxVERTICAL);
    //Display element
    display = new wxTextCtrl(this, wxID_ANY, DISPLAY_ZERO, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);
    display->SetFont(font);
    //Add displey to container
    box->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);
    //Grid element for buttons
    grid = new wxGridSizer(5, 4, 3, 3);
    //Buttons definitions
    grid->Add(new wxStaticText(this, wxID_ANY, wxT("")), 0, wxEXPAND);
    grid->Add(new wxStaticText(this, wxID_ANY, wxT("")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_CLS, wxT("CLS")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_BACK, wxT("<-")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_7, wxT("7")), 0, wxEXPAND); 
    grid->Add(new wxButton(this, CALC_8, wxT("8")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_9, wxT("9")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_DIV, wxT("/")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_4, wxT("4")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_5, wxT("5")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_6, wxT("6")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_TIMES, wxT("*")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_1, wxT("1")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_2, wxT("2")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_3, wxT("3")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_MINUS, wxT("-")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_0, Calculator::DISPLAY_ZERO), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_POINT, wxT(".")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_EQUAL, wxT("=")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALC_PLUS, wxT("+")), 0, wxEXPAND);
    //Add buttons grid to container
    box->Add(grid, 1, wxEXPAND);
    SetSizer(box);
    SetMinSize(size);
    Centre();
    //Handle events
    this->Bind(wxEVT_MENU, &CalculatorWindow::onExit, this, wxID_EXIT);
    for(const Calculator::OPTIONS OPT : All){
        this->Bind(wxEVT_BUTTON, &CalculatorWindow::onClick, this, OPT);
    }
}

void CalculatorWindow::onExit(wxCommandEvent &event)
{
    Close(true);
}

void CalculatorWindow::onClick(wxCommandEvent &event) 
{
    wxString actualDisplay, newDigit;
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
        /* code */
        break;
    case CALC_EQUAL:
        /* code */
        break;
    case CALC_PLUS:
        /* code */
        break;
    default:
        actualDisplay = this->display->GetLabel();
        newDigit = button->GetLabel();
        this->display->SetLabelText(actualDisplay + newDigit);
        break;
    }
}