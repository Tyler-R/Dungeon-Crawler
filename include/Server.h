#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
class Server {
public:
    Server(int port);
    ~Server();

    void listenForConnection();

    void print();
    void sendMessage();
private:
    int port;

    boost::asio::io_service io;
};
