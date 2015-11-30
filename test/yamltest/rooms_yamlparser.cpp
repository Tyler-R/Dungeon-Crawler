
//Test run with g++ -I. -g npc_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// void ClassName::functionName(string name){

int main()
{
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("gameYaml/midgaard.yaml");
	YAML::Node roomsNodes = allNode["ROOMS"];

	string roomsDescription;
	string doorsDesc; 
	string doorsDir;
	string doorsKeywords;
	string doorsTo;
	string room_extdesc; 
	string room_extkey;
	string roomId;
	string roomName;

	for(int i = 0; (unsigned)i < roomsNodes.size(); i++) {
		roomsDescription = " ";
		roomId = " ";
		roomName = " ";

		//parsing room's main description
		YAML::Node descriptionNode = roomsNodes[i]["desc"];
		for(int j = 0; j < descriptionNode.size(); j++){
			roomsDescription += descriptionNode[j].as<string>();
		}

		//parsing room name and room id
		roomName = roomsNodes[i]["name"].as<string>();
		roomId = roomsNodes[i]["id"].as<string>();
		
		YAML::Node extdescNode = roomsNodes[i]["extended_descriptions"];
		for(int a = 0; a < extdescNode.size(); a++){
			room_extdesc = " "; 
			room_extkey = " ";


			YAML::Node ext_descNode = extdescNode[a]["desc"];
			for(int j = 0; j < ext_descNode.size(); j++){
				room_extdesc += ext_descNode[j].as<string>();
			}

			YAML::Node ext_keyNode = extdescNode[a]["keywords"];
			for(int k = 0; k < ext_keyNode.size(); k++){
				room_extkey += ext_keyNode[k].as<string>();
			}

			cout << room_extdesc << endl;
			cout << room_extkey << endl;
		}



		cout <<"-----New Room Created!------"<< endl;
		cout << "Room name is " << roomName << endl << endl;
		cout << roomName << "'s' id is: " << roomId << endl << endl;
		cout << roomName << "'s description is: " << roomsDescription << endl<< endl;

		YAML::Node doorsNode = roomsNodes[i]["doors"];
		for(int k = 0; k < doorsNode.size(); k++){
			doorsDesc = " ";
			doorsDir = " ";
			doorsKeywords = "";
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
				doorsKeywords = doorskeywordNode[m].as<string>();
				// cout << doorsKeywords << endl << endl;
			}
			YAML::Node doorstoNode = doorsNode[k]["to"];
			doorsTo = doorstoNode.as<string>();

			cout << "----Doors in the room " << roomName << " -----" << endl;
			cout << "description: " << doorsDesc << endl << endl;
			cout << "direction: " << doorsDir << endl << endl;
			cout << "to: " << doorsTo << endl << endl;
		}	

	}

	return 0;
}
