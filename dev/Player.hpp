#ifndef _DEV_PLAYER_CLASS_H_
#define _DEV_PLAYER_CLASS_H_

#include <boost/enable_shared_from_this.hpp>

#include "../core/GameSession.hpp"

namespace AICup {

    namespace Dev {

        class Player : public Core::GameSession,
                       public boost::enable_shared_from_this<Player>
        {
        public:
            Player(boost::asio::io_service &io_service, Core::GameBattlefield &battlefield);
            ~Player();

            void Join();
            void Leave();
            void Action();
            boost::shared_ptr<GameSession> SharedFromThis();

            boost::shared_ptr<Player> enemy;

        private:

        };

    }
}
#endif //_DEV_PLAYER_CLASS_H_
