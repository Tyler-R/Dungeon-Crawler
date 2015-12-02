#pragma once
#include <string>
#include <map>
#include <iostream>
#include <fstream>

class Configuration {
public:
	Configuration( );
	~Configuration( );

	void load();
	void setFilePath( std::string filepath );


	std::string getValue( std::string key );
	void setValue( std::string key, std::string value );
private:
	std::string filepath = "res/configuration.txt";

	std::map< std::string, std::string > configurationValues;

	void saveToDisk( std::string key, std::string value );
};