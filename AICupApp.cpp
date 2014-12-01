#include <iostream>
#include <string.h>
#include <map>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include "AICupApp.hpp"

#include "./core/GameServer.hpp"

#include "./dev/Game.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace AICup;
using namespace AICup::Core;
using namespace AICup::Dev;

//typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

AICupApp::AICupApp(int port) : _port(port)
{
}

AICupApp::~AICupApp()
{

}

int AICupApp::Run()
{
    try {
        boost::asio::io_service io_service;

        tcp::endpoint endpoint(tcp::v4(), _port);
//        boost::shared_ptr<GameServer> server(new GameServer(io_service, endpoint));
        Game game;
        GameServer server(io_service, endpoint, game);
        cout << "GameServer (" << game.GetName() << ") Started." << endl;

        io_service.run();

        cout << "NetService Started." << endl;
    }
    catch (std::exception& e)
    {
       cerr << "Exception: " << e.what() << endl;
    }

    cout << "NetService Stopped." << endl;
    cout << "GameServer Stopped." << endl;

    return 0;
}
