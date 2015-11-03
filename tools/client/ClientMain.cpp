#include <iostream>
#include <memory>
#include <thread>

#include "Client.h"
#include "UserInterface.h"

std::shared_ptr<UserInterface> display = std::make_shared<UserInterface>();

std::shared_ptr<Client> client;

const int DELAY_BETWEEN_USER_INPUT_POLLS = 50000;

void draw() {
	while(true) {
		do {
			display->userCommand();

			display->displayCommandInInputBox(display->getUserCommand());

			usleep(DELAY_BETWEEN_USER_INPUT_POLLS);
		} while(display->getUserCommand().find("\n") ==  std::string::npos );

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
