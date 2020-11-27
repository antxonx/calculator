#ifndef CALCULATOR_HH
#define CALCULATOR_HH
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/grid.h>
#include <wx/font.h>
#include <cstring>
#include <calcmath/arith.hh>
namespace Calculator
{
    const wxString DISPLAY_ZERO = "0";
    const wxString DISPLAY_DECIMAL = ".";
    const unsigned int DISPLAY_FONT_SIZE = 20;
    const unsigned int DISPLAY_BURFFER_SIZE = 50;
    typedef enum
    {
        OP_NONE,
        OP_ADD,
        OP_SUB,
        OP_TIMES,
        OP_DIV
    } OPER;
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
        CALC_NEGATIVE
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
        CALC_NEGATIVE};

    class CalculatorWindow : public wxFrame
    {
    public:
        CalculatorWindow(wxSize);

    private:
        void onExit(wxCommandEvent &);
        void onClick(wxCommandEvent &);
        void clearScreen();
        bool isDisplayZero();
        bool isDisplayOneDigit();
        void operate();
        wxBoxSizer *box;
        wxGridSizer *grid;
        wxTextCtrl *display;
        bool decimalPoint;
        bool negative;
        bool newValue;
        OPER oper;
        double stored;
    };

} // namespace Calculator
#endif