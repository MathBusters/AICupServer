#ifndef _CORE_GAMESESSION_CLASS_H_
#define _CORE_GAMESESSION_CLASS_H_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "GameParticipant.hpp"
#include "GameBattlefield.hpp"
#include "GameMessage.hpp"

namespace AICup {
    namespace Core {
        class GameSession
            : public GameParticipant,
            public boost::enable_shared_from_this<GameSession>
        {
        public:
            GameSession(boost::asio::io_service &io_service, GameBattlefield &battlefield);

            boost::asio::ip::tcp::socket& Socket();

            void Start();

            void Deliver(const GameMessage &msg);

            void ReadHeaderHandler(const boost::system::error_code &error);

            void ReadBodyHandler(const boost::system::error_code &error);

            void WriteHandler(const boost::system::error_code &error);

        private:
            boost::asio::ip::tcp::socket _socket;
            GameBattlefield &_battlefield;
            GameMessage _readMsg;
            GameMessageQueue _writeMsgs;
        };
    }
}
#endif //_CORE_GAMESESSION_CLASS_H_
