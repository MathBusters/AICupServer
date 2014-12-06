#ifndef _CORE_GAMESESSION_CLASS_H_
#define _CORE_GAMESESSION_CLASS_H_

#include <boost/asio.hpp>

#include "GameMessage.hpp"

namespace AICup {
    namespace Core {

        class GameBattlefield;

        class GameSession
        {
        public:
            GameSession(boost::asio::io_service &io_service, GameBattlefield &battlefield);

            virtual ~GameSession();

            boost::asio::ip::tcp::socket& Socket();

            void Start();

            virtual void Join() = 0;
            virtual void Leave() = 0;
            virtual void Action() = 0;
            virtual boost::shared_ptr<GameSession> SharedFromThis() = 0;

            void Deliver(const GameMessage &msg);

            void ReadHeaderHandler(const boost::system::error_code &error);

            void ReadBodyHandler(const boost::system::error_code &error);

            void WriteHandler(const boost::system::error_code &error);

        protected: //private
            boost::asio::ip::tcp::socket _socket;
            GameBattlefield &_battlefield;
            GameMessage _readMsg;
            GameMessageQueue _writeMsgs;
        };
    }
}
#endif //_CORE_GAMESESSION_CLASS_H_
