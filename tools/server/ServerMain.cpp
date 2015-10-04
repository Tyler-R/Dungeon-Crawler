#include <iostream>
#include "Server.h"
int main() {
	std::cout << "hello server world" << std::endl;

	auto port = 8080;

	Server server(port);
	server.start();
}
