#ifndef _CORE_GAMEBATTLEFIELD_CLASS_H_
#define _CORE_GAMEBATTLEFIELD_CLASS_H_

#include <set>
#include <boost/asio.hpp>

#include "GameParticipant.hpp"

namespace AICup {

    namespace Core {
        typedef boost::shared_ptr<GameParticipant> GameParticipantPtr;

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
    //  enum { max_recent_msgs = 100 };
            GameMessageQueue _recentMsgs;
        };
    }
}
#endif //_CORE_GAMEBATTLEFIELD_CLASS_H_
