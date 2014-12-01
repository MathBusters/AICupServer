#ifndef _CORE_GAMEMESSAGE_CLASS_H_
#define _CORE_GAMEMESSAGE_CLASS_H_

#include <cstdlib>
#include <deque>

namespace AICup {
    namespace Core {

        class GameMessage
        {
        public:
            enum { HeaderLength = 4 };
            enum { MaxBodyLength = 512 };

            GameMessage();

            const char* Data() const;

            char* Data();

            size_t Length() const;

            const char* Body() const;

            char* Body();

            size_t BodyLength() const;

            void BodyLength(size_t newLength);

            bool DecodeHeader();

            void EncodeHeader();

        private:
            char _data[HeaderLength + MaxBodyLength];
            size_t _bodyLength;
        };

        typedef std::deque<GameMessage> GameMessageQueue;
    }
}
#endif //_CORE_GAMEMESSAGE_CLASS_H_
