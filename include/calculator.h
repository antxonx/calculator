#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/grid.h>
#include <wx/font.h>
namespace Calculator
{
    const wxString DISPLAY_ZERO = "0";
    const wxString DISPLAY_DECIMAL = ".";
    const unsigned int DISPLAY_FONT_SIZE = 20;
    enum OPTIONS
    {
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
   

    class CalculatorWindow : public wxFrame
    {
    public:
        CalculatorWindow(wxSize);

    private:
        void onExit(wxCommandEvent &);
        void onClick(wxCommandEvent &);
        wxBoxSizer *box;
        wxGridSizer *grid;
        wxTextCtrl *display;
        bool decimalPoint;
        bool negative;
    };

} // namespace Calculator