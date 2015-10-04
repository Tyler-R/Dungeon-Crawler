#include <iostream>
#include "Client.h"

int main() {
	std::cout << "hello client world" << std::endl;

	auto port = 8080;
	auto serverAddress = "127.0.0.1";

	Client client(serverAddress, port);
	client.connect();

	for(;;) {
		try {
			std::string message = "";
			std::cout << "enter your message: \n";
			getline(std::cin, message);

			client.sendMessage(message);

			// std::cout << client.getServerResponse();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			break;
		}
	}

}
