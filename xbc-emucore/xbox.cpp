#include "xbox.h"


namespace xbc
{
    namespace emucore
    {
        namespace xbox
        {
            Xbox::Xbox()
            {
            }

            Xbox::~Xbox()
            {
            }

            void Xbox::Start()
            {
                // initialize 4GB memory
                memSlot1 = new Memory(1073741824);
                memSlot2 = new Memory(1073741824);
                memSlot3 = new Memory(1073741824);
                memSlot4 = new Memory(1073741824);
            }

            void Xbox::LoadFile(std::string file)
            {
            }

            void Xbox::Step()
            {
            }

            void Xbox::Release()
            {
            }
        } // namespace Xbox
    } // namespace emucore
} // namespace xbc

