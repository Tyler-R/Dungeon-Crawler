#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Server {
public:
    Server();
    ~Server();

    static void print(const boost::system::error_code&);
    void sendMessage();
private:

};
