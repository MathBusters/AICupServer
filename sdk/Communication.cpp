#include <iostream>
#include <string>
#include <cstring>

#include "Communication.hpp"

using namespace std;

using namespace AICup;
using namespace AICup::SDK;

bool Communication::Serialize(JsonSerializableAbstract* pack, Core::GameMessage& output)
{
    if (pack == NULL) {

        return false;
    }

    string str;
    Json::Value serializeRoot;
    pack->Serialize(serializeRoot);

    Json::StyledWriter writer;
    str = writer.write(serializeRoot);

    output.BodyLength(str.size());
    memcpy(output.Body(), str.c_str(), output.BodyLength());
    output.EncodeHeader();

    return true;
}

bool Communication::Deserialize(JsonSerializableAbstract* pack, Core::GameMessage& input)
{
    if (pack == NULL) {

        return false;
    }

    Json::Value deserializeRoot;
    Json::Reader reader;

    if (!reader.parse(input.Body(), deserializeRoot)) {

        return false;
    }
    pack->Deserialize(deserializeRoot);

    return true;
}
