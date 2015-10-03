#include "Server.h"


Server::Server() {
    using namespace std;
    cout << "waiting for 5 seconds" << endl;

    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
    timer.async_wait(Server::print);

    io.run();

    cout << "hello world" << endl;


    cout << "hello world this is the real server" << endl;

}

void Server::print(const boost::system::error_code&) {
    std::cout << "threaded world" << std::endl;
}

Server::~Server() {


}
