#include <iostream>
#include <memory>
#include <thread>
#include <fstream>


#include "Client.h"
#include "UserInterface.h"

std::shared_ptr<UserInterface> display;

std::shared_ptr<Client> client;

const int DELAY_BETWEEN_USER_INPUT_POLLS = 80000;

void draw() {
	while(true) {
		do {
			display->userCommand();
			// client->sendUserInput(display->getUserCommand());

			display->displayCommandInInputBox(display->getUserCommand());

			display->draw();

			usleep(DELAY_BETWEEN_USER_INPUT_POLLS);
		} while(display->getUserCommand().find("\n") ==  std::string::npos );

		std::string command = display->getUserCommand();

		command.erase(std::remove(command.begin(), command.end(), '\n'), command.end());

		client->sendUserInput(command);
		display->displayUserCommand();
	}
}

int main() {

	int port;

	std::cout << "enter the port to connect to the server (likely 8080): ";
	std::cin >> port;

	display = std::make_shared<UserInterface>();

	auto serverAddress = "127.0.0.1";

	client = std::make_shared<Client>(serverAddress, port);
	client->connect();


	auto exampleCallback = [](const char* buffer, int length) {
		auto message = (std::string) buffer;
		message = message.substr(0, length);

		display->displayServerResponse(message.c_str());

		std::ofstream outfile;
		outfile.open("log.txt", std::ios_base::app);
		outfile << std::string(buffer) << "\n\n" << length << "\n\n"; 

		delete buffer;
	};

	client->setHandleServerCallback(exampleCallback);

	client->handleServerResponse();

	std::thread displayLoop(draw);

	client->start();

	displayLoop.join();

}
