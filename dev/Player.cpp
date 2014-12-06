#include "Player.hpp"

#include "../core/GameBattlefield.hpp"

using namespace AICup;
using namespace AICup::Core;
using namespace AICup::Dev;

//Ниже реализуются базовые функции любой сетевой игры,
//при необходимости вы можете дополнить их своими функциями


Player::Player(boost::asio::io_service &io_service, GameBattlefield &battlefield) : GameSession(io_service, battlefield)
{
}

Player::~Player() {}

void Player::Join()
{
    _battlefield.Join(shared_from_this());
}

void Player::Leave()
{
     _battlefield.Leave(shared_from_this());
}

void Player::Action()
{
     _battlefield.Deliver(_readMsg, shared_from_this());
}

boost::shared_ptr<GameSession> Player::SharedFromThis()
{

    return shared_from_this();
}
