#include "Session.h"

Session::Session( tcp::socket socket, int maxCommands, shared_ptr<World> world) : socket( std::move( socket ) ), maxCommands( maxCommands ){
    // commandParser = std::make_shared< CommandParser >( );
    myWorld = world;
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
                std::cout << "received: ";
                for(auto &c : command->buffer) {
                    std::cout << c;
                }

                std::cout << " - length " << command->length << std::endl;

                addCommandToQueue(*command);
                messageReceivedCallback();

                delete command;

            } else {
                //handle client disconnecting
                std::cout << "client disconnected" << std::endl;

                if( isLoggedIn() ) {
                    // remove user from room they are currently in
                    user->getRoom()->removeUser( user->getUserName() );
                }




                return;
            }

            listenForCommands();
        }
    );
}

void Session::addCommandToQueue(Command command) {
    if(commandBacklog.size() >= maxCommands) {
        sendMessage("ERROR: too many command entered");
    } else {
        commandBacklog.push(command);
    }
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
            exit(1);
            offerOptionToRegisterOrLogin();
        }
    };

    sendMessage("Enter 1 to login or 2 to register\n");
}

void Session::askForUsername(std::string message, std::function<void(void)> onSuccess) {
    messageReceivedCallback = onSuccess;
    sendMessage(message);
}

void Session::askForPassword(std::string message, std::function<void(void)> onSuccess) {
    messageReceivedCallback = onSuccess;
    sendMessage(message);
}

void Session::attemptLogin() {
    std::string username = getNextCommand();
    std::string password = getNextCommand();

    Authentication authentication(username, password);
    if(authentication.login()) {
        messageReceivedCallback = [](){
            //do nothing
        };

        loggedIn = true;
        sendMessage("You are logged in as " + username + "\n");
        user = make_shared< User >( false, username, password, myWorld->getRoom(0), "This is PlayerOne." );

        std::function< void( std::string ) > sendMessageCallback = std::bind(&Session::sendMessage, this, std::placeholders::_1);
        user->setMessageDisplayer( sendMessageCallback );

        std::function< void ( std::function< void( void ) > ) > listenForBeginCombat = std::bind( &Session::listenForBeginCombat, this, std::placeholders::_1 );
        user->setBeginCombatListener(listenForBeginCombat);

        myWorld->getRoom( 0 )->addUser( user );

        commandParser = std::make_shared< CommandParser >( user, myWorld->getSpellsLib() );

    } else {
        sendMessage("Incorrect username or password. Try again.\n");
        login();
    }
}

void Session::listenForBeginCombat(std::function<void(void)> messsageReceived) {
    messageReceivedCallback = [this, messsageReceived]() {
        std::string message = getNextCommand();

        if(message.length() > 0 && message.at(0) == 'y') {
            user->setInCombat(true);
        } 

        messsageReceived();

        messageReceivedCallback = []() {
            
        };
    };
}

void Session::login() {
    assert(!loggedIn);

    // ask for username and password and then attempt to login.
    askForUsername("Enter your username: " ,[this]() {
        askForPassword("Enter your password: ", [this](){
            attemptLogin();
        });
    });
}

void Session::attemptToRegisterPlayer() {
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
}

void Session::registerNewPlayer() {

    askForUsername("Enter your new username: ", [this]() {
        askForPassword("Enter your new password: ", [this]() {
            attemptToRegisterPlayer();
        });
    });
}

void Session::sendMessage(std::string message) {



    boost::system::error_code error;
    size_t bitesWritten = boost::asio::write(socket, boost::asio::buffer(message), boost::asio::transfer_all(), error);

    std::cout << "sending message: " << message << " - with length = " << bitesWritten << " - " << " with size = " << message.size() << std::endl;
    if(error) {
        kill();
        throw boost::system::system_error(error);
    }
}

std::string Session::executeCommand(std::string command) {
    return commandParser->processCommand(command);
}
