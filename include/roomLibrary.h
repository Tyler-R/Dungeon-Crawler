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
		shared_ptr<Room> createRoom(string name,string id, string description, string extDescription, vector<string> keywords); //NEEDS KEYWORDS
		void addRoom(shared_ptr<Room> room); 		
		void parseYaml();

		vector<shared_ptr<Door*>> doorList; 
		shared_ptr<Door*> createDoor(string id,string direction, string description, vector<string> keywords); // Implement


	public:
		roomLibrary();
		shared_ptr<Room> getRoom(string id);
		vector<shared_ptr<Room>> getRoomList();


};