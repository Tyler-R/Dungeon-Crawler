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
			auto serverResponse = client.getServerResponse();
			std::cout.write(serverResponse.c_str(), serverResponse.size());
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			break;
		}
	}

}
