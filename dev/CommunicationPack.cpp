#include "CommunicationPack.hpp"

using namespace AICup;
using namespace AICup::Core;
using namespace AICup::Dev;


CommunicationPack::CommunicationPack() : JsonSerializableAbstract()
{
}

void CommunicationPack::Serialize(Json::Value& root)
{
    // serialize primitives
    root["CommunicationInt"] = _communicationInt;
    root["CommunicationDouble"] = _communicationDouble;
    root["CommunicationsString"] = _communicationString;
    root["CommunicationBool"] = _communicationtBool;
}

void CommunicationPack::Deserialize(Json::Value& root)
{
    // deserialize primitives
    _communicationInt = root.get("CommunicationInt",0).asInt();
    _communicationDouble = root.get("CommunicationDouble", 0.0).asDouble();
    _communicationString = root.get("CommunicationsString", "").asString();
    _communicationtBool = root.get("CommunicationBool", false).asBool();
}
