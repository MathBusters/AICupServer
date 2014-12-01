#include "GameServer.hpp"

#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace AICup;
using namespace AICup::Core;

GameServer::GameServer(boost::asio::io_service &io_service,
                       const tcp::endpoint &endpoint,
                       GameBattlefield &battlefield)
    : _io_service(io_service),
      _acceptor(io_service, endpoint),
      _battlefield(battlefield)
{
    StartAccept();
}

void GameServer::StartAccept()
{
    GameSessionPtr newSession(new GameSession(_io_service, _battlefield));
    _acceptor.async_accept(newSession->Socket(),
                           boost::bind(&GameServer::AcceptHandler, this, newSession,
                           boost::asio::placeholders::error));
}

void GameServer::AcceptHandler(GameSessionPtr session,
                   const boost::system::error_code &error)
{
    if (!error) {
        session->Start();
    }

    StartAccept();
}
