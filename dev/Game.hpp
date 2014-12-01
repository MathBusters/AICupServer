#ifndef _DEV_GAME_CLASS_H_
#define _DEV_GAME_CLASS_H_

#include <set>
#include <boost/asio.hpp>

#include "../core/GameBattlefield.hpp"

namespace AICup {

        class Game : public Core::GameBattlefield
        {
        public:
            Game();

            void Join(Core::GameParticipantPtr participant);

            void Leave(Core::GameParticipantPtr participant);

            void Deliver(const Core::GameMessage &msg, GameParticipantPtr participant);

        private:
            std::set<Core::GameParticipantPtr> _participants;
    //  enum { max_recent_msgs = 100 };
            Core::GameMessageQueue _recentMsgs;
        };
}
#endif //_DEV_GAME_CLASS_H_
