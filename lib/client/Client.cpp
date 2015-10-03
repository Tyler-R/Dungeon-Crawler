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
