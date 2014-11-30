#ifndef _CORE_GAMEPARTICIPANT_CLASS_H_
#define _CORE_GAMEPARTICIPANT_CLASS_H_

#include "GameMessage.hpp"

namespace AICup {
    namespace Core {

        class GameParticipant
        {
        public:
            virtual ~GameParticipant() {}
            virtual void Deliver(const GameMessage& msg) = 0;
        };
    }
}
#endif //_CORE_GAMEPARTICIPANT_CLASS_H_
