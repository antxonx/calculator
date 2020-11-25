#include <calculator.h>

Calculator::Calculator(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    //Font size
    wxFont font = wxFont(wxFontInfo(20));
    //Container
    box = new wxBoxSizer(wxVERTICAL);
    //Display element
    display = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);
    display->SetFont(font);
    //Add displey to container
    box->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);
    //Grid element for buttons
    grid = new wxGridSizer(5, 4, 3, 3);
    //Buttons definitions
    grid->Add(new wxStaticText(this, wxID_ANY, wxT("")), 0, wxEXPAND);
    grid->Add(new wxStaticText(this, wxID_ANY, wxT("")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_CLS, wxT("CLS")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_BACK, wxT("<-")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_7, wxT("7")), 0, wxEXPAND); 
    grid->Add(new wxButton(this, CALCULATOR::CALC_8, wxT("8")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_9, wxT("9")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_DIV, wxT("/")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_4, wxT("4")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_5, wxT("5")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_6, wxT("6")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_TIMES, wxT("*")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_1, wxT("1")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_2, wxT("2")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_3, wxT("3")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_MINUS, wxT("-")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_0, wxT("0")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_POINT, wxT(".")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_EQUAL, wxT("=")), 0, wxEXPAND);
    grid->Add(new wxButton(this, CALCULATOR::CALC_PLUS, wxT("+")), 0, wxEXPAND);
    //Add buttons grid to container
    box->Add(grid, 1, wxEXPAND);
    SetSizer(box);
    SetMinSize(size);
    Centre();
    //Handle events
    this->Bind(wxEVT_MENU, &Calculator::onExit, this, wxID_EXIT);
    for(const CALCULATOR::OPTIONS OPT : CALCULATOR::All){
        this->Bind(wxEVT_BUTTON, &Calculator::onClick, this, OPT);
    }
}

void Calculator::onExit(wxCommandEvent &event)
{
    Close(true);
}

void Calculator::onClick(wxCommandEvent &event) 
{
    wxButton *button = wxDynamicCast(event.GetEventObject(), wxButton);
    switch (button->GetId())
    {
    case CALCULATOR::CALC_CLS:
        /* code */
        break;
    case CALCULATOR::CALC_BACK:
        /* code */
        break;
    case CALCULATOR::CALC_DIV:
        /* code */
        break;
    case CALCULATOR::CALC_TIMES:
        /* code */
        break;
    case CALCULATOR::CALC_MINUS:
        /* code */
        break;
    case CALCULATOR::CALC_POINT:
        /* code */
        break;
    case CALCULATOR::CALC_EQUAL:
        /* code */
        break;
    case CALCULATOR::CALC_PLUS:
        /* code */
        break;
    default:
        this->display->SetLabelText(this->display->GetLabel() + button->GetLabel());
        break;
    }
}