#include "GameSession.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace AICup;
using namespace AICup::Core;

GameMessage::GameMessage() : _bodyLength(0)
{
}

const char* GameMessage::Data() const
{

    return _data;
}

char* GameMessage::Data()
{

    return _data;
}

size_t GameMessage::Length() const
{

    return HeaderLength + _bodyLength;
}

const char*  GameMessage::Body() const
{

    return _data + HeaderLength;
}

char* GameMessage::Body()
{

    return _data + HeaderLength;
}

size_t GameMessage::BodyLength() const
{

    return _bodyLength;
}

void GameMessage::BodyLength(size_t newLength)
{
    _bodyLength = newLength;
    if (_bodyLength > MaxBodyLength) {
        _bodyLength = MaxBodyLength;
    }
}

bool GameMessage::DecodeHeader()
{
    using namespace std; // For strncat and atoi.
    char header[HeaderLength + 1] = "";
    strncat(header, _data, HeaderLength);
    _bodyLength = atoi(header);
    if (_bodyLength > MaxBodyLength) {
        _bodyLength = 0;

        return false;
    }

    return true;
}

void GameMessage::EncodeHeader()
{
    using namespace std; // For sprintf and memcpy.
    char header[HeaderLength + 1] = "";
    sprintf(header, "%4d", _bodyLength);
    memcpy(_data, header, HeaderLength);
}
