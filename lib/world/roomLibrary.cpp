//Created by Sarah Kim Dao and Jason Zhang
#include "roomLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>


using namespace std;
roomLibrary::roomLibrary(){
	cout << "--Creating Room Library ... ";
	parseYaml();
	cout << "Done!" << endl;
}

shared_ptr<Room> roomLibrary::createRoom(string name,string id, string description, string extDescription, vector<string> keywords){
	shared_ptr<Room> room (new Room());
	room->setName(name);
	room->setId(id);
	room->setDesc(description);
	room->addKeywords(keywords);
	room->setExtDesc(extDescription);

	return room;
}

void roomLibrary::addRoom(shared_ptr<Room> room){
	roomList.push_back(room);
}

shared_ptr<Room> roomLibrary::getRoom(string id){
	for (auto & room :roomList){
		if (room->getId() == id){
			return room;
		}
	}
	return nullptr;
}
	
vector<shared_ptr<Room>> roomLibrary::getRoomList(){
	return roomList;
}

shared_ptr<Door*> roomLibrary::createDoor(string id,string direction, string description, vector<string> keywords){
	// Implement
} 


void roomLibrary::parseYaml(){
	char filePath[PATH_MAX + 1]; 
    char *res = realpath("gameYaml/midgaard.yaml", filePath);

	YAML::Node allNode = YAML::LoadFile(filePath);
	YAML::Node roomsNodes = allNode["ROOMS"];

	string roomsDescription;
	string doorsDesc; 
	string doorsDir;
	vector<string> doorsKeywords;
	string doorsTo;
	string roomId;
	string roomName;
	string roomExtDesc; //leave out for now
	vector<string>roomKeywords;

	for(int i = 0; (unsigned)i < roomsNodes.size(); i++) {
		roomsDescription = " ";
		roomId = " ";
		roomName = " ";

		//parsing room's main description
		YAML::Node descriptionNode = roomsNodes[i]["desc"];
		for(int j = 0; j < descriptionNode.size(); j++){
			roomsDescription += descriptionNode[j].as<string>();
			roomsDescription += "\n";
		}

		//parsing room name and room id
		roomName = roomsNodes[i]["name"].as<string>();
		roomId = roomsNodes[i]["id"].as<string>();	

		YAML::Node extdescNode = roomsNodes[i]["extended_descriptions"];
		for(int a = 0; a < extdescNode.size(); a++){
			roomExtDesc = " "; 
			roomKeywords.clear();


			YAML::Node ext_descNode = extdescNode[a]["desc"];
			for(int j = 0; j < ext_descNode.size(); j++){
				roomExtDesc += ext_descNode[j].as<string>();
				roomExtDesc += "\n";
			}
			YAML::Node ext_keyNode = extdescNode[a]["keywords"];
			for(int k = 0; k < ext_keyNode.size(); k++){
				roomKeywords.push_back(ext_keyNode[k].as<string>());
			}

		}


		addRoom(createRoom(roomName,roomId,roomsDescription, roomExtDesc,roomKeywords));

		YAML::Node doorsNode = roomsNodes[i]["doors"];
		for(int k = 0; k < doorsNode.size(); k++){
			doorsDesc = " ";
			doorsDir = " ";
			doorsKeywords.clear();
			doorsTo = "";

			//parsing Doors. and it's description, direction, keywords and to
			YAML::Node doorsdescNode = doorsNode[k]["desc"];
			for(int l = 0; l < doorsdescNode.size(); l++){
				doorsDesc = doorsdescNode[l].as<string>();
				}

			YAML::Node doorsdirNode = doorsNode[k]["dir"];
			doorsDir = doorsdirNode.as<string>();

			YAML::Node doorskeywordNode = doorsNode[k]["keywords"];
			for (int m = 0; m < doorskeywordNode.size(); m++){
				doorsKeywords.push_back(doorskeywordNode[m].as<string>());
				//cout << doorsKeywords << endl << endl;
			}
			YAML::Node doorstoNode = doorsNode[k]["to"];
			doorsTo = doorstoNode.as<string>();

			roomList.back()->addDoor(doorsTo, doorsDir, doorsDesc, roomList.back());

			//need some way to add in the LeadsTo

			// cout << "----Doors in the room " << roomName << " -----" << endl;
			// cout << "description: " << doorsDesc << endl << endl;
			// cout << "direction: " << doorsDir << endl << endl;
			// cout << "to: " << doorsTo << endl << endl;
		}
	}

	//Iterates through every room, checks their doors, and sets their leadsTo to a valid room.  
	//Need to do something about the nested loops.
	for (auto & room :roomList){
		for (auto & door: room->getDoorList()){
		 	for (auto & leadsTo:roomList){
		 		if (leadsTo->getId() == door->getId()){
		 			door->setLeadsTo(leadsTo);
		 		}
		 	}
		}
	}

}
