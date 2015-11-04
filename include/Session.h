#pragma once
#include <iostream>
#include <memory>
#include <functional>
#include <utility>
#include <queue>

#include <boost/asio.hpp>

#include "Authentication.h"
#include "world.h"
#include "CommandParser.h"


using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    static const int MAX_COMMAND_LENGTH = 1024;

    typedef struct {
        int length = 0;
        char buffer[MAX_COMMAND_LENGTH];
    } Command;

    Session(tcp::socket socket, int maxCommands, shared_ptr<World> world);
    ~Session();

    void listenForCommands();

    std::string getNextCommand();

    std::string executeCommand(std::string command);

    void sendMessage(std::string message);

    void offerOptionToRegisterOrLogin();

    bool isLoggedIn();
    bool isAlive();

    // sets isAlive to false
    void kill();
private:
    tcp::socket socket;
    int maxCommands = 0;

    void addCommandToQueue(Command command);

    void login();

    void askForUsername(std::string message, std::function<void(void)> onSuccess);
    void askForPassword(std::string message, std::function<void(void)> onSuccess);

    void attemptLogin();

    void registerNewPlayer();

    void attemptToRegisterPlayer();

    std::queue<Command> commandBacklog;

    std::function<void(void)> messageReceivedCallback;

    bool loggedIn = false;
    bool alive = true;

    shared_ptr<World> myWorld;
    std::shared_ptr<CommandParser> commandParser;
    shared_ptr<User> usr;

};
