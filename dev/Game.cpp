#include "Game.hpp"

#include <algorithm>

#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace AICup;
using namespace AICup::Core;

//Вставьте здесь название своей игры
Game::Game() : GameBattlefield("Game Implementation") {}

//Ниже реализуются базовые функции любой сетевой игры,
//при необходимости вы можете дополнить их своими функциями

/*
void Game::Join(GameParticipantPtr participant)
{
    _participants.insert(participant);
    for_each(_recentMsgs.begin(), _recentMsgs.end(),
                  boost::bind(&GameParticipant::Deliver, participant, _1));
}

void Game::Leave(GameParticipantPtr participant)
{
    _participants.erase(participant);
}

void Game::Deliver(const GameMessage &msg)
{
    for_each(_participants.begin(), _participants.end(),
                  boost::bind(&GameParticipant::Deliver, _1, boost::ref(msg)));
}
*/