#pragma once
#include "..\xbc\main.h"
#include "wx\richtext\richtextctrl.h"
namespace xbc
{
    namespace emucore
    {
        class LogWindow : public wxWindow
        {
        private:
            wxRichTextCtrl * logText;
        public:
            LogWindow(wxMDIParentFrame * parent);

            wxDECLARE_EVENT_TABLE();
        };
    } // namespace emucore
} // namespace xbc