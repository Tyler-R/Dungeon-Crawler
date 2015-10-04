#include "Client.h"

Client::Client(std::string serverAddress, int port) : serverAddress(serverAddress), port(port){

    std::cout << "I AM THE CLIENT!!" << std::endl;

}

void Client::connect() {
    try {
        auto connectionPort = std::to_string(port);

        tcp::resolver resolver(io_service);

        tcp::resolver::query query(serverAddress, connectionPort);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        tcp::resolver::iterator end;

        socket = new tcp::socket(io_service);
        boost::system::error_code error = boost::asio::error::host_not_found;

        while (error && endpoint_iterator != end) {
            socket->close();
            socket->connect(*endpoint_iterator++, error);
        }

        if (error) {
            throw boost::system::system_error(error);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Client::sendMessage(std::string message) {
    boost::system::error_code error;
    size_t bitesWritten = boost::asio::write(*socket, boost::asio::buffer(message), boost::asio::transfer_all(), error);

    if(error) {
        throw boost::system::system_error(error);
    }

}

void Client::sendUserInput(std::function<std::string(void)> callback) {

    std::string message = callback();

    boost::asio::async_write(*socket, boost::asio::buffer(message.c_str(), message.size()),
        [this, callback](boost::system::error_code errorCode, std::size_t length) {
            if(!errorCode) {
                sendUserInput(callback);
            } else {
                //handle client disconnecting
                std::cout << "server disconnected" << std::endl;
                return;
            }
        }
    );

    io_service.run();
}

void Client::handleServerResponse(std::function<void(char*, int)> callback) {
    char *receiveBuffer = new char[RECEIVE_BUFFER_SIZE];

    socket->async_read_some(boost::asio::buffer(receiveBuffer, RECEIVE_BUFFER_SIZE),
        [this, callback, receiveBuffer](boost::system::error_code errorCode, std::size_t length) {
            if(!errorCode) {
                // handle command
                callback(receiveBuffer, length);
            } else {
                std::cout << "server disconnected" << std::endl;
                return;
            }

            handleServerResponse(callback);
        }
    );
}

std::string Client::getServerResponse() throw(boost::system::system_error) {
    boost::array<char, RECEIVE_BUFFER_SIZE> buf;
    boost::system::error_code error;

    // read data from server
    size_t len = socket->read_some(boost::asio::buffer(buf), error);

    // connection closed either normally or through an error
    if (error) {
        throw boost::system::system_error(error);
    }

    auto data = ((std::string)buf.data());
    data = data.substr(0, len);

    return data;
}

Client::~Client() {
    if(socket) {
        delete socket;
    }


}
