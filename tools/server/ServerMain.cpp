#include <iostream>
#include <memory> 

#include "Server.h"

int main() {
	std::cout << "hello server world" << std::endl;

	std::shared_ptr<Configuration> configuration = std::make_shared<Configuration>();
	configuration->load();

	auto port = atoi( configuration->getValue( "port" ).c_str( ) ) ;

	std::cout << "port =- " << port << std::endl;

	Server server(port, configuration);
	server.start();
}
