#ifndef _CORE_GAMESERVER_CLASS_H_
#define _CORE_GAMESERVER_CLASS_H_

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include "GameBattlefield.hpp"

#include "../dev/Player.hpp"

namespace AICup {
    namespace Core {
        typedef boost::shared_ptr<Dev::Player> GameSessionPtr;

        class GameServer
        {
        public:
            GameServer(boost::asio::io_service &io_service,
                       const boost::asio::ip::tcp::endpoint &endpoint,
                       GameBattlefield &battlefield);

            void StartAccept();

            void AcceptHandler(GameSessionPtr session, const boost::system::error_code &error);
        private:
            boost::asio::io_service &_io_service;
            boost::asio::ip::tcp::acceptor _acceptor;
            GameBattlefield &_battlefield;
        };
    }
}
#endif //_CORE_GAMESERVER_CLASS_H_
