#include "configuration/configuration.h"

Configuration::Configuration() {
}

Configuration::~Configuration( ) {

}

void Configuration::load() {
	using namespace std;

	string key;
	string value;
	ifstream file( filepath );

	if( file.is_open( ) ) {
		while( getline( file, key, ' ' ) && getline( file, value, '\n' ) ) {
			configurationValues.emplace(key, value);
		}
	} else {
		cout << "could not open file" << endl;
	}

	file.close();
}

void Configuration::setFilePath( std::string newFilepath ) {
	filepath = newFilepath;	
}


std::string Configuration::getValue( std::string key ) {
	return configurationValues[key];
}


void Configuration::setValue( std::string key, std::string value ) {
	saveToDisk(value, key);
}

void Configuration::saveToDisk( std::string key, std::string value ) {
	using namespace std;
	ofstream file( filepath );

	if(file.is_open( ) ) {
		for(auto &configurationPair : configurationValues) {
			file << configurationPair.first << " " << configurationPair.second << "\n";
		}
	} else {
		cout << "could not save to file" << endl;
	}

	file.close();
} 