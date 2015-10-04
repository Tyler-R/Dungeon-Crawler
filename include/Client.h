#pragma once
#include <iostream>
#include <functional>

#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Client {
public:
    Client(std::string ServerAddress, int port);
    ~Client();

    void connect();
    std::string getServerResponse() throw(boost::system::system_error);
    void sendMessage(std::string message);

    void handleServerResponse(std::function<void(char*, int)> callback);

    void sendUserInput(std::function<std::string(void)> callback);

private:
    const std::string serverAddress;
    const int port;

    boost::asio::io_service io_service;
    tcp::socket *socket = nullptr;

    static const int RECEIVE_BUFFER_SIZE = 1024;
    static const int SEND_BUFFER_SIZE = 1024;

};
