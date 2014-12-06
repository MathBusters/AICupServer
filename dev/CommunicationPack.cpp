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
    root["CommunicationInt"] = CommunicationInt;
    root["CommunicationDouble"] = CommunicationDouble;
    root["CommunicationsString"] = CommunicationString;
    root["CommunicationBool"] = CommunicationtBool;
}

void CommunicationPack::Deserialize(Json::Value& root)
{
    // deserialize primitives
    CommunicationInt = root.get("CommunicationInt", 0).asInt();
    CommunicationDouble = root.get("CommunicationDouble", 0.0).asDouble();
    CommunicationString = root.get("CommunicationsString", "").asString();
    CommunicationtBool = root.get("CommunicationBool", false).asBool();
}
