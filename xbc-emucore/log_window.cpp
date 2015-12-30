#include "log_window.h"

namespace xbc
{
    namespace emucore
    {
        wxBEGIN_EVENT_TABLE(LogWindow, wxWindow)
            wxEND_EVENT_TABLE()
            LogWindow::LogWindow(wxMDIParentFrame * parent) : wxWindow(parent, 11, wxDefaultPosition, wxSize(100, 100))
        {
            logText = new wxRichTextCtrl(this, -1, "");
            logText->SetBackgroundColour(wxColour("White"));
            logText->SetForegroundColour(wxColour("Black"));
            logText->SetEditable(false);
            wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
            // create text ctrl with minimal size 100x60
            topsizer->Add(
                logText,
                1,            // make vertically stretchable
                wxEXPAND |    // make horizontally stretchable
                wxALL,        //   and make border all around
                0);         // set border width to 10
            SetSizerAndFit(topsizer); // use the sizer for layout and size window
                                      // accordingly and prevent it from being resized
                                      // to smaller size
        }

    } // namespace emucore
} // namespace xbc