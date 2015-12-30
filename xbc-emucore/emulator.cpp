#include "emulator.h"


namespace xbc
{
    namespace emucore
    {
        IXBCEmulator::IXBCEmulator()
        {
        }

        IXBCEmulator::~IXBCEmulator()
        {
        }

        void IXBCEmulator::Application_Run()
        {
            MainWindow * mainWnd = new MainWindow();
            mainWnd->Show(true);
        }
    } // namespace emucore
} // namespace xbc
