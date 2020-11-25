#include <calculator.h>

Calculator::Calculator(wxSize size) : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, size)
{
    this->Bind(wxEVT_MENU, &Calculator::OnExit, this, wxID_EXIT);

    box = new wxBoxSizer(wxVERTICAL);
    display = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);
    box->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
    grid = new wxGridSizer(5, 4, 3, 3);

    grid->Add(new wxButton(this, wxID_ANY, wxT("Cls")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("Bck")), 0, wxEXPAND);
    grid->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("Close")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("7")), 0, wxEXPAND); 
    grid->Add(new wxButton(this, -1, wxT("8")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("9")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("/")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("4")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("5")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("6")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("*")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("1")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("2")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("3")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("-")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("0")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT(".")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("=")), 0, wxEXPAND);
    grid->Add(new wxButton(this, -1, wxT("+")), 0, wxEXPAND);
    box->Add(grid, 1, wxEXPAND);
    SetSizer(box);
    SetMinSize(size);
    Centre();
}

void Calculator::OnExit(wxCommandEvent &event)
{
    Close(true);
}