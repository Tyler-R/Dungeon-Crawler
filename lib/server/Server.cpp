#include "Server.h"


Server::Server(int port) : port(port), acceptor(ioService, tcp::endpoint(tcp::v4(), port)), socket(ioService) {
}

Server::~Server() {
}

void Server::start() {
    listenForConnections();
    handleCommands();
}


void Server::listenForConnections() {
    std::cout << "waiting on port = " << port << std::endl;

    acceptor.async_accept(socket,
        [this](boost::system::error_code errorCode) {
            if(!errorCode) {
                sessions.emplace_back(std::make_shared<Session>(std::move(socket)));
                sessions.back()->listenForCommands();
            }

            listenForConnections();
        }
    );
}

void Server::handleCommands() {
    for(auto session : sessions) {
        // handle commands that will manipulate the world
        // send data back to clients
        // wait untill next tick
        try {
            if(session->isAlive) {
                auto nextCommand = session->getNextCommand();
                session->sendMessage(nextCommand);
            }
        } catch(std::exception &e) {
            session->isAlive = false;
        }
    }

    try{
        boost::asio::deadline_timer timer(ioService, boost::posix_time::millisec(16));
        timer.async_wait(boost::bind(&Server::handleCommands, this));
        ioService.run();
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
