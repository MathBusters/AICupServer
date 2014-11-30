#include "BattleLog.hpp"

using namespace std;
using namespace AICup;
using namespace AICup::Core;

BattleLog::BattleLog()
{
    _round = 0;
    _log.open("battle_log.log");
}

void BattleLog::Start()
{
    _log << "Battle Started" << endl;
}

void BattleLog::Draw()
{
    _log << "Battle Finished: Draw." << endl;
}

void BattleLog::Win(std::string ai)
{
    _log << "###    ###" << endl;
    _log << "Battle Finished: " << ai << " AI Win!" << endl;
}

void BattleLog::Round()
{
    _log << "### Round: " << ++_round << " ###" << endl;
}

void BattleLog::Shot(std::string ai, int power, double angle, int wind, int coordinate, int epsilon)
{
    _log << "AI " << ai << " shoot: (power angle wind coordinate epsilon)" << endl;
    _log << power << "    " << angle << "    " << wind << "    " << coordinate << "    " << epsilon << endl;
}
