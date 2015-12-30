#pragma once
#include "..\xbc\main.h"

namespace xbc
{
    namespace emucore
    {
#if defined PLATFORM_WINDOWS
        class GOutputWindow
        {
        private:
            HINSTANCE hInstance;
            WNDCLASSEX wcex;
            static LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        public:
            wxSize windowSize;
            HWND hWnd;

            void Create();
            void Show();

        };
#else
        class GOutputWindow : public wxFrame
        {
        public:
            GOutputWindow();
        }
#endif
    } // namespace emucore
} // namespace xbc