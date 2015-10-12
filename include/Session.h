#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <queue>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    static const int MAX_COMMAND_LENGTH = 1024;
    static const int MAX_COMMANDS = 5;

    typedef struct {
        int length = 0;
        char buffer[MAX_COMMAND_LENGTH];
    } Command;

    Session(tcp::socket socket);
    ~Session();

    void listenForCommands();

    std::string getNextCommand();

    void sendMessage(std::string message);

    bool isAlive = true;
private:
    tcp::socket socket;

    void addCommandToQueue(Command command);

    std::queue<Command> commandBacklog;
};
