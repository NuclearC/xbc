#include "main_window.h"


namespace xbc
{
    namespace emucore
    {
        wxBEGIN_EVENT_TABLE(MainWindow, wxMDIParentFrame)
            EVT_MENU(11, MainWindow::OnBootGame)
            EVT_MENU(wxID_EXIT, MainWindow::OnExit)
            EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
            EVT_MENU(20, MainWindow::OnStart)
            EVT_MENU(21, MainWindow::OnStop)
            wxEND_EVENT_TABLE()
        MainWindow::MainWindow() : wxMDIParentFrame(NULL, 0, "XBC 0.01a", wxDefaultPosition, wxSize(640, 480))
        {
            m_mgr.SetManagedWindow(this);

            wxMenu *menuFile = new wxMenu;
            menuFile->Append(11, "&Boot Game\tCtrl+O",
                "Open game executable");
            menuFile->AppendSeparator();
            menuFile->Append(wxID_EXIT);

            wxMenu *menuDebug = new wxMenu;
            menuDebug->Append(20, "&Start");
            menuDebug->Append(21, "&Stop");
            menuDebug->Append(22, "&Pause");
            menuDebug->Append(23, "&Resume");
            menuDebug->AppendSeparator();
            menuDebug->Append(24, "&Restart");


            wxMenu *menuHelp = new wxMenu;
            menuHelp->Append(wxID_ABOUT);

            wxMenuBar *menuBar = new wxMenuBar;
            menuBar->Append(menuFile, "&File");
            menuBar->Append(menuDebug, "&Debug");
            menuBar->Append(menuHelp, "&Help");


            SetMenuBar(menuBar);
            CreateStatusBar();
            SetStatusText("Status: Ready");


            dbgWnd = new DebugWindow(this);
            logWnd = new LogWindow(this);

            m_mgr.AddPane(dbgWnd, wxLEFT, "Debug Window");
            m_mgr.AddPane(logWnd, wxBOTTOM, "Log Window");

            m_mgr.Update();
        }

        MainWindow::~MainWindow()
        {
            m_mgr.UnInit();
        }

        void MainWindow::OnBootGame(wxCommandEvent & event)
        {
            ofd = new wxFileDialog(this, _("Boot Game"), "", "",
                "Xbox Executables|*.exe", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

            if (ofd->ShowModal() == wxID_CANCEL)
                return;

           

            xb = new xbox::Xbox();

            gOutWnd = new GOutputWindow();
            gOutWnd->windowSize = wxSize(1280, 720);
            gOutWnd->Create();
            gOutWnd->Show();

            xb->LoadFile(ofd->GetFilename().c_str().AsChar());
            xb->Start();

            MSG msg = { 0 };

            while (TRUE)
            {
                if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);

                    if (msg.message == WM_QUIT)
                        break;

                    xb->Step();
                }
            }

            xb->Release();
        }

        void MainWindow::OnAbout(wxCommandEvent & event)
        {
        }

        void MainWindow::OnExit(wxCommandEvent & event)
        {
            Destroy();
        }

        void MainWindow::OnQuit(wxCloseEvent & event)
        {
            
        }

        void MainWindow::OnStart(wxCommandEvent & event)
        {
        }

        void MainWindow::OnStop(wxCommandEvent & event)
        {
            xb->Release();

            delete xb;
        }



    } // namespace emucore
} // namespace xbc