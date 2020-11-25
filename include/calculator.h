#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/grid.h>

class Calculator : public wxFrame
{
public:
    Calculator(wxSize);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxBoxSizer *box;
    wxGridSizer *grid;
    wxTextCtrl *display;
};