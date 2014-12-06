#include "GameSession.hpp"

#include <iostream>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace AICup;
using namespace AICup::Core;

GameSession::GameSession(boost::asio::io_service &io_service, GameBattlefield &battlefield)
    : _socket(io_service),
      _battlefield(battlefield)
{
}

GameSession::~GameSession() {}

tcp::socket& GameSession::Socket()
{

    return _socket;
}

void GameSession::Start()
{
    Join();
//    _battlefield.Join(shared_from_this());
    boost::asio::async_read(_socket,
                            boost::asio::buffer(_readMsg.Data(), GameMessage::HeaderLength),
/*                            boost::bind(&GameSession::ReadHeaderHandler, shared_from_this(),*/
                            boost::bind(&GameSession::ReadHeaderHandler, SharedFromThis(),
                                        boost::asio::placeholders::error));
}

void GameSession::Deliver(const GameMessage &msg)
{
    bool writeInProgress = !_writeMsgs.empty();
    _writeMsgs.push_back(msg);
    if (!writeInProgress)
    {
        boost::asio::async_write(_socket,
                                 boost::asio::buffer(_writeMsgs.front().Data(),
                                                     _writeMsgs.front().Length()),
/*                                 boost::bind(&GameSession::WriteHandler, shared_from_this(), */
                                 boost::bind(&GameSession::WriteHandler, SharedFromThis(),
                                             boost::asio::placeholders::error));
    }
}

void GameSession::ReadHeaderHandler(const boost::system::error_code &error)
{
    if (!error && _readMsg.DecodeHeader())
    {
        boost::asio::async_read(_socket,
                                boost::asio::buffer(_readMsg.Body(), _readMsg.BodyLength()),
/*                                boost::bind(&GameSession::ReadBodyHandler, shared_from_this(), */
                                boost::bind(&GameSession::ReadBodyHandler, SharedFromThis(),
                                            boost::asio::placeholders::error));
    }
    else
    {
        Leave();
        //_battlefield.Leave(shared_from_this());
    }
}

void GameSession::ReadBodyHandler(const boost::system::error_code &error)
{
    if (!error)
    {
        Action();
        //_battlefield.Deliver(_readMsg, shared_from_this());
        boost::asio::async_read(_socket,
                                boost::asio::buffer(_readMsg.Data(), GameMessage::HeaderLength),
/*                                boost::bind(&GameSession::ReadHeaderHandler, shared_from_this(),*/
                                boost::bind(&GameSession::ReadHeaderHandler, SharedFromThis(),
                                            boost::asio::placeholders::error));

    }
    else
    {
        Leave();
        //_battlefield.Leave(shared_from_this());
    }

}

void GameSession::WriteHandler(const boost::system::error_code &error)
{
    if (!error)
    {
        _writeMsgs.pop_front();
        if (!_writeMsgs.empty())
        {
            boost::asio::async_write(_socket,
                                     boost::asio::buffer(_writeMsgs.front().Data(),
                                                         _writeMsgs.front().Length()),
/*                                     boost::bind(&GameSession::WriteHandler, shared_from_this(),*/
                                     boost::bind(&GameSession::WriteHandler, SharedFromThis(),
                                                 boost::asio::placeholders::error));
        }
    }
    else
    {
        Leave();
        //_battlefield.Leave(shared_from_this());
    }
}

