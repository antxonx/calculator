#include <main.h>
#include <calculator.h>

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Calculator *calculator = new Calculator(wxSize(400, 400));
    calculator->Show(true);
    SetTopWindow(calculator);
    return true;
}