#ifndef _CORE_GAMEBATTLEFIELD_CLASS_H_
#define _CORE_GAMEBATTLEFIELD_CLASS_H_

#include <set>
#include <boost/asio.hpp>

#include "../dev/Player.hpp"

namespace AICup {

    namespace Core {
        typedef boost::shared_ptr<Dev::Player> GameParticipantPtr;

        class GameBattlefield
        {
        public:
            GameBattlefield(std::string name  = "Abstract");

            virtual void Join(GameParticipantPtr participant);

            virtual void Leave(GameParticipantPtr participant);

            virtual void Deliver(const GameMessage &msg, GameParticipantPtr participant);

            std::string GetName() const;

        protected:
            std::string _name;

        private:
            std::set<GameParticipantPtr> _participants;
            GameMessageQueue _recentMsgs;
        };
    }
}
#endif //_CORE_GAMEBATTLEFIELD_CLASS_H_
