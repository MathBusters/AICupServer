#include <iostream>

#include "Communication.hpp"

using namespace AICup;
using namespace AICup::Dev;

void Communication::Serialize(Json::Value& root)
{
    // serialize primitives
    root["CommunicationInt"] = _communicationInt;
    root["CommunicationFloat"] = _communicationFloat;
    root["CommunicationsString"] = _communicationString;
    root["CommunicationBool"] = _communicationtBool;
}

void Communication::Deserialize(Json::Value& root)
{
    // deserialize primitives
    _communicationInt = root.get("CommunicationInt",0).asInt();
    _communicationFloat = root.get("CommunicationFloat", 0.0).asDouble();
    _communicationString = root.get("CommunicationsString", "").asString();
    _communicationtBool = root.get("CommunicationBool", false).asBool();
}
