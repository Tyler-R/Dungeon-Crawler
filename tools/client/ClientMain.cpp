#include <iostream>
#include <memory>
#include <thread>

#include "Client.h"
#include "UserInterface.h"

std::shared_ptr<UserInterface> display = std::make_shared<UserInterface>();

std::shared_ptr<Client> client;

void draw() {
	while(true) {
		display->userCommand();
		client->sendUserInput(display->getUserCommand());
		display->displayUserCommand();
	}
}

int main() {

	std::thread displayLoop(draw);

	auto port = 8080;
	auto serverAddress = "127.0.0.1";

	client = std::make_shared<Client>(serverAddress, port);
	client->connect();


	auto exampleCallback = [](const char* buffer, int length) {
		auto message = (std::string) buffer;
		message = message.substr(0, length);

		display->displayServerResponse(buffer);
	};

	client->setHandleServerCallback(exampleCallback);

	client->handleServerResponse();

	client->start();

	displayLoop.join();

}
