#include "GameBattlefield.hpp"

#include <algorithm>

#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace AICup;
using namespace AICup::Core;

GameBattlefield::GameBattlefield(std::string name) : _name(name) {}


void GameBattlefield::Join(GameParticipantPtr participant)
{
    _participants.insert(participant);
    for_each(_recentMsgs.begin(), _recentMsgs.end(),
             boost::bind(&GameParticipant::Deliver, participant, _1));
}

void GameBattlefield::Leave(GameParticipantPtr participant)
{
    _participants.erase(participant);
}

void GameBattlefield::Deliver(const GameMessage &msg, GameParticipantPtr participant)
{
    /*
    for_each(_participants.begin(), _participants.end(),
             boost::bind(&GameParticipant::Deliver, _1, boost::ref(msg)));
    */
}


std::string GameBattlefield::GetName() const
{

    return _name;
}
