#include <iostream>
#include <memory>

#include "Client.h"



int main() {
	std::cout << "Welcome to our game" << std::endl;

	auto port = 8080;
	auto serverAddress = "127.0.0.1";

	Client client(serverAddress, port);
	client.connect();


	auto exampleCallback = [](char* buffer, int length) {
		auto message = (std::string) buffer;
		message = message.substr(0, length);

		std::cout << message << std::endl;
		std::cout.flush();
	};

	client.setHandleServerCallback(exampleCallback);

	client.readInput();
	client.handleServerResponse();

	client.start();

	std::cout << "The game is over." << std::endl;

}
