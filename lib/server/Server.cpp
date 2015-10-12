#include "Server.h"


Server::Server(int port) : port(port), acceptor(ioService, tcp::endpoint(tcp::v4(), port)), socket(ioService) {
    using namespace std;

    cout << "waiting on port: " << port << endl;

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
    std::cout << "checking for session input" << std::endl;
    for(auto session : sessions) {
        // handle commands that will manipulate the world
        // send data back to clients
        // wait untill next tick
        try {
            if(session->isAlive) {
                auto nextCommand = session->getNextCommand();
                std::cout << nextCommand << std::endl;
                session->sendMessage(nextCommand);
            }
        } catch(std::exception &e) {
            session->isAlive = false;
        }
    }

    try{
        std::cout << "sleeping for 1 second" << std::endl;
        boost::asio::deadline_timer timer(ioService, boost::posix_time::seconds(1));
        timer.async_wait(boost::bind(&Server::handleCommands, this));
        ioService.run();
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

Server::~Server() {


}
