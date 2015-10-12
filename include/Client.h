#pragma once
#include <iostream>
#include <functional>
#include <string>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

using boost::asio::ip::tcp;

class Client {
public:
    Client(std::string ServerAddress, int port);
    ~Client();

    void connect();
    std::string getServerResponse() throw(boost::system::system_error);
    void sendMessage(std::string message);

    void handleServerResponse();

    void sendUserInput(std::string message);

    void setSendCallback(std::function<std::string(void)> callback);
    void setHandleServerCallback(std::function<void(char*, int)> callback);

    void handleReadInput(const boost::system::error_code& error, const size_t bytes_transferred);
    void readInput();

    void start();

private:
    const std::string serverAddress;
    const int port;

    boost::asio::io_service io_service;
    tcp::socket *socket = nullptr;

    static const int RECEIVE_BUFFER_SIZE = 1024;
    static const int SEND_BUFFER_SIZE = 1024;

    std::function<std::string(void)> sendCallback;
    std::function<void(char*, int)> serverResponseCallback;

    char userInput;

    std::string userCommand;

    boost::asio::posix::stream_descriptor input;
    boost::asio::streambuf buffer;

};
