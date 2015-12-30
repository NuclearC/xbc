#pragma once
#include "..\xbc\main.h"
#include "memory.h"
namespace xbc
{
    namespace emucore
    {
        namespace xbox
        {
            class Xbox
            {
            private:
                std::vector<byte> file_content;

                Memory* memSlot1;
                Memory* memSlot2;
                Memory* memSlot3;
                Memory* memSlot4;
            public:
                Xbox();
                ~Xbox();

                void Start();
                void LoadFile(std::string file);
                void Step();
                void Release();
            };
        } // namespace Xbox
    } // namespace emucore
} // namespace xbc

