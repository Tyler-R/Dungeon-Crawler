#include "Client.h"

Client::Client(std::string serverAddress, int port) : serverAddress(serverAddress), port(port), input(io_service, ::dup(STDIN_FILENO)) {

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

void Client::sendUserInput(std::string message) {

    // std::string message = sendCallback();

    boost::asio::async_write(*socket, boost::asio::buffer(message.c_str(), message.size()),
        [this](boost::system::error_code errorCode, std::size_t length) {
            if(!errorCode) {
                // sendUserInput();
            } else {
                //handle client disconnecting
                std::cout << "server disconnected" << std::endl;
                return;
            }
        }
    );

}

void Client::handleServerResponse() {
    char *receiveBuffer = new char[RECEIVE_BUFFER_SIZE];

    socket->async_read_some(boost::asio::buffer(receiveBuffer, RECEIVE_BUFFER_SIZE),
        [this, receiveBuffer](boost::system::error_code errorCode, std::size_t length) {
            if(!errorCode) {
                // handle command
                serverResponseCallback(receiveBuffer, length);
            } else {
                std::cout << "server disconnected" << std::endl;
                return;
            }

            handleServerResponse();
        }
    );
}

void Client::setHandleServerCallback(std::function<void(char*, int)> callback) {
    serverResponseCallback = callback;
}

void Client::setSendCallback(std::function<std::string(void)> callback) {
    sendCallback = callback;
}

void Client::start() {
    io_service.run();
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

void Client::readInput() {


    async_read_until(input, buffer, '\n',
        boost::bind(&Client::handleReadInput, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));

	// Read a line of input entered by the user.
	//  boost::asio::async_read(input, boost::asio::buffer(&userInput, sizeof(userInput)),
	//  	boost::bind(&Client::handleReadInput, shared_from_this(),
    //         boost::asio::placeholders::error,
    //         boost::asio::placeholders::bytes_transferred));
}

void Client::handleReadInput(const boost::system::error_code& error, const size_t bytes_transferred) {
    if(error) {
        std::cout << boost::system::system_error(error).what() << std::endl;
        return;
    }
    std::istream stringCreator(&buffer);
    char bufferData[1024];

    stringCreator.getline(bufferData, bytes_transferred);

    std::string message(bufferData);

    buffer.consume(bytes_transferred);

    sendUserInput(message);
    readInput();
}

Client::~Client() {
    if(socket) {
        delete socket;
    }


}
