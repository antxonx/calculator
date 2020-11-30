/**
 * Create layout and build interface
 */
#include <calculator.hh>

using namespace Calculator;

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
    this->box->Add(this->display, wxSizerFlags(1).Expand().Border(wxDirection::wxALL, 10));
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
    button = new wxButton(this, CALC_LOG, "Log");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //this->grid->Add(new wxStaticText(this, wxID_ANY, wxEmptyString), 0, wxEXPAND);
    button = new wxButton(this, CALC_SQUARE_EXP, L"x\u00B2");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_SQUARE_ROOT, L"\u221A");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_DIV, L"\u00F7");
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
    button = new wxButton(this, CALC_TIMES, L"\u2A2F");
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
    button = new wxButton(this, CALC_MINUS, L"\u2212");
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
    button = new wxButton(this, CALC_PLUS, L"\u002B");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-5
    //6->
    button = new wxButton(this, CALC_NEGATIVE, L"\u207A\u2044\u208B");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_0, Calculator::DISPLAY_ZERO);
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_POINT, ".");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    button = new wxButton(this, CALC_EQUAL, L"\u003D");
    button->SetFont(font);
    this->grid->Add(button, 0, wxEXPAND);
    //<-6
    //Add buttons grid to container
    this->box->Add(this->grid,wxSizerFlags(1).Expand().Border(wxDirection::wxALL, 10));
    this->SetSizer(this->box);
    this->SetMinSize(this->size);
    this->Centre();
    this->display->SetCanFocus(false);
    //Handle events
    this->Bind(wxEVT_MENU, &CalculatorWindow::onExit, this, wxID_EXIT);
    for (const Calculator::OPTIONS OPT : All)
    {
        this->Bind(wxEVT_BUTTON, &CalculatorWindow::onClick, this, OPT);
    }
}