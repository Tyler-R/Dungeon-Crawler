#include <iostream>
#include <memory>

#include "Client.h"



int main() {


	std::cout << "hello client world" << std::endl;

	auto port = 8080;
	auto serverAddress = "127.0.0.1";

	boost::shared_ptr<Client> client(new Client(std::move(serverAddress), std::move(port)));

	// Client client(serverAddress, port);
	client->connect();

	// client.readSome();


	auto exampleCallback = [](char* buffer, int length) {
		auto message = (std::string) buffer;
		message = message.substr(0, length);

		std::cout << message << std::endl;
		std::cout.flush();
	};

	auto writeCallback = []() -> std::string {
		std::string message = "";

		std::cout << "enter your message: ";
		std::getline(std::cin, message);

		return message;
	};

	client->setHandleServerCallback(exampleCallback);
	client->setSendCallback(writeCallback);


	// client->sendUserInput();
	client->readInput();
	client->handleServerResponse();

	std::cout << "pie" << std::endl;

	client->start();

	std::cout << "AND THEN MORE HAPPENS!!!" << std::endl;



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
