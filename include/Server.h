#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>


#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "Session.h"
#include "world.h"
#include "configuration/configuration.h"

using boost::asio::ip::tcp;

class Server {
public:
    Server( int port, std::shared_ptr<Configuration> config );
    ~Server( );

    void start( );

private:
    int port;

    boost::asio::io_service ioService;
    tcp::socket socket;
    tcp::acceptor acceptor;

    std::vector<std::shared_ptr<Session>> sessions;

    std::shared_ptr<World> world;

    std::shared_ptr<Configuration> configuration;

    int serverRefreshRate = 0;

    void listenForConnections( );

    void handleCommands( );

    void loadWorld( );

};
