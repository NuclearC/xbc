#pragma once
#include "main_window.h"

namespace xbc
{
    namespace emucore
    {
        class IXBCEmulator
        {
        public:
            IXBCEmulator();
            ~IXBCEmulator();

            void Application_Run();

        };
    } // namespace emucore
} // namespace xbc