/* * * * * * * * * * * * * * * * * * * * * * * * *
* XBC Xbox One Experimental Emulator            *
* Version 0.01a                                 *
* Copyright (C) 2015-2016 Armen Berujanyan      *
* * * * * * * * * * * * * * * * * * * * * * * * */
#include "main.h"

#include "..\xbc-emucore\emulator.h"

#pragma comment (lib,"xbc-emucore.lib")

wxIMPLEMENT_APP(XbcApp);

void XbcApp::XbcStartup()
{
    xbc::emucore::IXBCEmulator* emu = new xbc::emucore::IXBCEmulator();
    emu->Application_Run();
}

bool XbcApp::OnInit()
{
    XbcStartup();
    return true;
}
