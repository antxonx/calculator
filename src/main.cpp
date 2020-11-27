#include <main.hh>
#include <calculator.hh>
#include <exception>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#define GetCurrentDir getcwd

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    try
    {
        char buff[FILENAME_MAX];
        GetCurrentDir( buff, FILENAME_MAX );
        std::string current_working_dir(buff);
        Calculator::CalculatorWindow *calculator = new Calculator::CalculatorWindow(wxSize(400, 500));
        calculator->Show(true);
        calculator->SetIcon(wxIcon(current_working_dir + "/assets/favicon.ico"));
        SetTopWindow(calculator);
    }
    catch (const std::exception &e)
    {
        wxMessageDialog errDialog(NULL, e.what(), "Error", wxOK);
        errDialog.ShowModal();
    }
    return true;
}