#include "Session.h"

Session::Session(tcp::socket socket) : socket(std::move(socket)) {

}

Session::~Session() {
}

void Session::listenForCommands() {
    auto self(shared_from_this());
    Command *command = new Command();

    socket.async_read_some(boost::asio::buffer(command->buffer, MAX_COMMAND_LENGTH),
        [this, self, command](boost::system::error_code errorCode, std::size_t length) {
            if(!errorCode) {
                // handle command
                command->length = length;
                addCommandToQueue(*command);
                messageReceivedCallback();
            } else {
                //handle client disconnecting
                std::cout << "client disconnected" << std::endl;
                return;
            }

            listenForCommands();
        }
    );
}

void Session::addCommandToQueue(Command command) {
    commandBacklog.push(command);
}

std::string Session::getNextCommand() {
    if(commandBacklog.size() > 0) {
        auto command = commandBacklog.front();
        commandBacklog.pop();

        std::string data = command.buffer;
        data = data.substr(0, command.length);

        return data;
    } else {
        return "";
    }
}

bool Session::isAlive() {
    return alive;
}

bool Session::isLoggedIn() {
    return loggedIn;
}

void Session::kill() {
    alive = false;
}

void Session::offerOptionToRegisterOrLogin() {
    messageReceivedCallback = [this]() {
        std::string message = getNextCommand();

        int choice = atoi(message.c_str());

        if(choice == 1) {
            login();
        } else if(choice == 2) {
            registerNewPlayer();
        } else {
            sendMessage("that is not an option. try again.\n");
            offerOptionToRegisterOrLogin();
        }
    };

    sendMessage("Enter 1 to login or 2 to register\n");


}

void Session::login() {
    std::cout << "player trying to login" << std::endl;
    sendMessage("enter your username: ");
    messageReceivedCallback = [this]() {
        sendMessage("enter your password: ");
        this->messageReceivedCallback = [this]() {
            std::string username = getNextCommand();
            std::string password = getNextCommand();

            Authentication authentication(username, password);
            if(authentication.login()) {
                loggedIn = true;
                sendMessage("You are logged in as " + username + "\n");
                messageReceivedCallback = [](){
                    //do nothing
                };
            } else {
                sendMessage("Incorrect username or password. Try again.\n");
                login();
            }
        };
    };
}

void Session::registerNewPlayer() {
    sendMessage("Enter your new username: ");
    messageReceivedCallback = [this]() {
        sendMessage("Enter your new password: ");
        this->messageReceivedCallback = [this]() {
            std::string username = getNextCommand();
            std::string password = getNextCommand();

            Authentication authentication(username, password);
            if(authentication.signUp()) {
                sendMessage(username + " was created"  + "\n");
                login();

            } else {
                sendMessage("username already exists. Try again.\n");
                registerNewPlayer();
            }
        };
    };
}

void Session::sendMessage(std::string message) {

    boost::system::error_code error;
    size_t bitesWritten = boost::asio::write(socket, boost::asio::buffer(message), boost::asio::transfer_all(), error);

    if(error) {
        kill();
        throw boost::system::system_error(error);
    }
}
