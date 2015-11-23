#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "room.h"
#include <memory>

using namespace std;

class roomLibrary{
	private:
		vector<shared_ptr<Room>> roomList;
		shared_ptr<Room> create(string name,string id, string description);
		void addRoom(shared_ptr<Room>);		
		void parseYaml();
	public:
		roomLibrary();
		shared_ptr<Room> getRoom(string id);
		vector<shared_ptr<Room>> getRoomList();


};