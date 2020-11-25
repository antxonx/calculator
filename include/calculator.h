#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/grid.h>
#include <wx/font.h>
namespace CALCULATOR{
    enum OPTIONS {
        CALC_0,
        CALC_1,
        CALC_2,
        CALC_3,
        CALC_4,
        CALC_5,
        CALC_6,
        CALC_7,
        CALC_8,
        CALC_9,
        CALC_CLS,
        CALC_BACK,
        CALC_EQUAL,
        CALC_PLUS,
        CALC_MINUS,
        CALC_TIMES,
        CALC_DIV,
        CALC_POINT,
    };
    const OPTIONS All[] = {
        CALC_0,
        CALC_1,
        CALC_2,
        CALC_3,
        CALC_4,
        CALC_5,
        CALC_6,
        CALC_7,
        CALC_8,
        CALC_9,
        CALC_CLS,
        CALC_BACK,
        CALC_EQUAL,
        CALC_PLUS,
        CALC_MINUS,
        CALC_TIMES,
        CALC_DIV,
        CALC_POINT,
    };
}

class Calculator : public wxFrame
{
public:
    Calculator(wxSize);

private:
    void onExit(wxCommandEvent &);
    void onClick(wxCommandEvent &);
    wxBoxSizer *box;
    wxGridSizer *grid;
    wxTextCtrl *display;
};