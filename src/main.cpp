#include <main.h>
#include <calculator.h>
#include <exception>

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    try
    {
        Calculator::CalculatorWindow *calculator = new Calculator::CalculatorWindow(wxSize(400, 500));
        calculator->Show(true);
        SetTopWindow(calculator);
    }
    catch (const std::exception &e)
    {
        wxMessageDialog errDialog(NULL, e.what(), "Error", wxOK);
        errDialog.ShowModal();
    }
    return true;
}