#pragma once

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define __WXMSW__
#include <wx/treectrl.h>
#include <wx/aui/aui.h>
#include <wx/richtext/richtextctrl.h>

#define WXUSINGDLL
#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#ifndef WX_PRECOMP
#include <wx/dlimpexp.h>
#include <wx/compiler.h>
#include <wx/wx.h>
#endif

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#pragma comment(lib, "wxbase31ud_net.lib")
#pragma comment(lib, "wxbase31ud_xml.lib")
#pragma comment(lib, "wxexpatd.lib")
#pragma comment(lib, "wxjpegd.lib")
#pragma comment(lib, "wxmsw31ud_adv.lib")
#pragma comment(lib, "wxmsw31ud_aui.lib")
#pragma comment(lib, "wxmsw31ud_core.lib")
#pragma comment(lib, "wxmsw31ud_gl.lib")
#pragma comment(lib, "wxmsw31ud_html.lib")
#pragma comment(lib, "wxmsw31ud_media.lib")
#pragma comment(lib, "wxmsw31ud_qa.lib")
#pragma comment(lib, "wxmsw31ud_richtext.lib")
#pragma comment(lib, "wxmsw31ud_xrc.lib")
#pragma comment(lib, "wxpngd.lib")
#pragma comment(lib, "wxregexud.lib")
#pragma comment(lib, "wxtiffd.lib")
#pragma comment(lib, "wxzlibd.lib")
#else // _DEBUG
#pragma comment(lib, "wxbase31u.lib")
#pragma comment(lib, "wxbase31u_net.lib")
#pragma comment(lib, "wxbase31u_xml.lib")
#pragma comment(lib, "wxexpat.lib")
#pragma comment(lib, "wxjpeg.lib")
#pragma comment(lib, "wxmsw31u_adv.lib")
#pragma comment(lib, "wxmsw31u_aui.lib")
#pragma comment(lib, "wxmsw31u_core.lib")
#pragma comment(lib, "wxmsw31u_gl.lib")
#pragma comment(lib, "wxmsw31u_html.lib")
#pragma comment(lib, "wxmsw31u_media.lib")
#pragma comment(lib, "wxmsw31u_qa.lib")
#pragma comment(lib, "wxmsw31u_richtext.lib")
#pragma comment(lib, "wxmsw31u_xrc.lib")
#pragma comment(lib, "wxpng.lib")
#pragma comment(lib, "wxregexu.lib")
#pragma comment(lib, "wxtiff.lib")
#pragma comment(lib, "wxzlib.lib")
#endif //_DEBUG
#pragma comment (lib,"comctl32.lib")
#pragma comment (lib,"Rpcrt4.lib")

#if defined WIN32 | defined _WIN32
#define PLATFORM_WINDOWS
#endif // WIN32\_WIN32

#if defined DEBUG | defined _DEBUG
#define CONFIG_DEBUG
#else // DEBUG\_DEBUG
#define CONFIG_RELEASE
#endif // !DEBUG\!_DEBUG

class XbcApp : public wxApp
{
public:
    virtual bool OnInit();
    void XbcStartup();

};


#endif // MAIN_H_