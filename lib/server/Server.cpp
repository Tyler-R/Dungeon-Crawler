#include "Server.h"


Server::Server(int port) : port(port) {
    using namespace std;
    using boost::asio::ip::tcp;

    cout << port << endl;

    try {

        boost::asio::io_service ioService;

        cout << "waiting for 2 seconds" << endl;
        cout << "waiting on port = " << port << endl;

        tcp::acceptor acceptor(ioService, tcp::endpoint(tcp::v4(), port));

        for(;;) {
            tcp::socket socket(ioService);
            acceptor.accept(socket);

            boost::system::error_code ignored_error;

            std::string message = "welcome to my server\n";

            boost::asio::write(socket, boost::asio::buffer(message), boost::asio::transfer_all(), ignored_error);

        }

        boost::asio::deadline_timer timer(ioService, boost::posix_time::seconds(2));
        timer.async_wait(boost::bind(&Server::print, this));

        io.run();

        cout << "hello world" << endl;


        cout << "hello world this is the real server" << endl;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}

void Server::print() {
    std::cout << "threaded world" << std::endl;
}

void Server::listenForConnection() {

}

Server::~Server() {


}
