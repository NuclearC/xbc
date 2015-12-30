#pragma once
#include "..\xbc\main.h"

namespace xbc
{
    namespace emucore
    {
        class DebugWindow : public wxWindow
        {
        private:
            wxButton * btnStart;
            wxButton * btnPause;
            wxButton * btnResume;
            wxButton * btnStop;
        public:
            DebugWindow(wxMDIParentFrame * parent);

            wxDECLARE_EVENT_TABLE();
        };
    } // namespace emucore
} // namespace xbc