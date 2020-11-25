#include <calculator.h>

Calculator::Calculator(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    unsigned int i = 0;
    this->Bind(wxEVT_MENU, &Calculator::onExit, this, wxID_EXIT);
    wxFont font = wxFont(wxFontInfo(20));
    box = new wxBoxSizer(wxVERTICAL);
    display = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);
    display->SetFont(font);
    box->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);
    grid = new wxGridSizer(5, 4, 3, 3);

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
    box->Add(grid, 1, wxEXPAND);
    SetSizer(box);
    SetMinSize(size);
    Centre();

    for(const auto OPT : CALCULATOR::All){
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
    this->display->SetLabelText(button->GetLabel());
}