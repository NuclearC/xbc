#include "dbg_window.h"

namespace xbc
{
    namespace emucore
    {
        wxBEGIN_EVENT_TABLE(DebugWindow, wxWindow)
            wxEND_EVENT_TABLE()
        DebugWindow::DebugWindow(wxMDIParentFrame * parent) : wxWindow(parent, 11, wxDefaultPosition, wxSize(100, 100))
        {
            btnStart = new wxButton(this, 12, "&Start", wxPoint(6, 6), wxSize(75, 23));
            btnStop = new wxButton(this, 13, "&Stop", wxPoint(81, 6), wxSize(75, 23));
            btnPause = new wxButton(this, 14, "&Pause", wxPoint(156, 6), wxSize(75, 23));
            btnResume = new wxButton(this, 15, "&Resume", wxPoint(231, 6), wxSize(75, 23));
        }

    } // namespace emucore
} // namespace xbc