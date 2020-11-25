#include <main.h>
#include <calculator.h>

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Calculator::CalculatorWindow *calculator = new Calculator::CalculatorWindow(wxSize(400, 400));
    calculator->Show(true);
    SetTopWindow(calculator);
    return true;
}