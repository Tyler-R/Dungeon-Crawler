#include <iostream>
#include "Client.h"

int main() {
	std::cout << "hello client world" << std::endl;

	auto port = 8080;
	auto serverAddress = "127.0.0.1";

	Client client(serverAddress, port);
	client.connect();

	auto exampleCallback = [](char* buffer, int length) {
		auto message = (std::string) buffer;
		message = message.substr(0, length);

		std::cout << message << std::endl;
		std::cout << "callback called" << std::endl;
	};

	client.handleServerResponse(exampleCallback);

	auto writeCallback = []() -> std::string {
		std::string message = "";

		std::cout << "enter your message: ";
		std::getline(std::cin, message);

		return message;
	};

	client.sendUserInput(writeCallback);
	// for(;;) {
	// 	try {
	// 		std::string message = "";
	// 		std::cout << "enter your message: ";
	// 		getline(std::cin, message);
	//
	// 		client.sendMessage(message);
	// 	} catch (std::exception &e) {
	// 		std::cout << e.what() << std::endl;
	// 		break;
	// 	}
	// }

}
