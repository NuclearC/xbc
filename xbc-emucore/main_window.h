#pragma once
#include "..\xbc\main.h"
#include "gs_window.h"
#include "dbg_window.h"
#include "log_window.h"
#include "xbox.h"

namespace xbc
{
    namespace emucore
    {


        class MainWindow : public wxMDIParentFrame
        {
        private:
            DebugWindow * dbgWnd;
            LogWindow * logWnd;
            GOutputWindow * gOutWnd;
            wxFileDialog* ofd;
            wxAuiManager m_mgr;

            xbox::Xbox * xb;
        public:
            MainWindow();
            ~MainWindow();

            void OnBootGame(wxCommandEvent& event);
            void OnAbout(wxCommandEvent& event);
            void OnExit(wxCommandEvent& event);
            void OnQuit(wxCloseEvent& event);

            void OnStart(wxCommandEvent& event);
            void OnStop(wxCommandEvent& event);

            wxDECLARE_EVENT_TABLE();
        };
    } // namespace emucore
} // namespace xbc