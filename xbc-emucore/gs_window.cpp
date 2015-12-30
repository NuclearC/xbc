#include "gs_window.h"

namespace xbc
{
    namespace emucore
    {
#if defined PLATFORM_WINDOWS
        void GOutputWindow::Create()
        {
            hInstance = GetModuleHandle(NULL);

            wcex.cbSize = sizeof(WNDCLASSEX);
            wcex.style = CS_HREDRAW | CS_VREDRAW;
            wcex.lpfnWndProc = WndProc;
            wcex.cbClsExtra = 0;
            wcex.cbWndExtra = 0;
            wcex.hInstance = hInstance;
            wcex.hIcon = NULL;
            wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
            wcex.lpszMenuName = NULL;
            wcex.lpszClassName = L"GSWindowClass";
            wcex.hIconSm = NULL;

            if (!RegisterClassEx(&wcex))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed!"),
                    _T("Xbc"),
                    NULL);

                _CrtDbgBreak();
            }

            RECT wr = { 0, 0, windowSize.x, windowSize.y };    // set the size, but not the position
            AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);    // adjust the size

           
            RECT   rectScreen;
            int    ConsolePosX;
            int    ConsolePosY;

            GetWindowRect(GetDesktopWindow(), &rectScreen);
            ConsolePosX = (rectScreen.right - (wr.right - wr.left)) / 2;
            ConsolePosY = (rectScreen.bottom - (wr.bottom - wr.top)) / 2;

            hWnd = CreateWindow(
                L"GSWindowClass",
                L"Graphics Output Null Window",
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT,
                wr.right - wr.left,    // width of the window
                wr.bottom - wr.top,    // height of the window
                NULL,
                NULL,
                hInstance,
                NULL
                );

            if (hWnd == NULL)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed!"),
                    _T("Xbc"),
                    NULL);

                _CrtDbgBreak();
            }

        }

        void GOutputWindow::Show()
        {
            ShowWindow(hWnd,
                SW_SHOWNORMAL);
            UpdateWindow(hWnd);
        }

        LRESULT CALLBACK GOutputWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
        {
            switch (message)
            {
            case WM_PAINT:
                
                break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
                break;
            }

            return 0;
        }
#else
        
#endif
        
    } // namespace emucore
} // namespace xbc