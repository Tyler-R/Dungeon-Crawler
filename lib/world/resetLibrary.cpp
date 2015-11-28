
#include "resetLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


shared_ptr<RESET> itemLibrary::create(string action,string comment,string resetId,string limit, string room, string slot){
	shared_ptr<RESET> reset (new RESET(resetId));
	reset->addId(resetId);
	return reset;
}

void resetLibrary::addReset(shared_ptr<RESET> reset){
	itemList.push_back(reset);
}

shared_ptr<RESET> resetLibrary::get(string id){
	for (auto & reset :resetList){
		if (reset->getID() == resetId){
			return reset;
		}
	}
	return NULL;
}

void resetLibrary::parseYaml(){
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("gameYaml/smurf.yaml");
	YAML::Node resetNodes = allNode["RESETS"];

	string action;
	string comment; 
	string resetId;
	string limit;
	string room;
	string slot;

	for(int i = 0; (unsigned)i < resetNodes.size(); i++) {
		action = " ";
		comment = " ";
		resetId = " ";
		limit = " ";
		room = " ";
		slot = " ";

		action = resetNodes[i]["action"].as<string>();
		resetId = resetNodes[i]["id"].as<string>();


		YAML::Node commentNode = resetNodes[i]["comment"];
		if(commentNode != NULL){
			comment = commentNode.as<string>();
		}
		else {
			comment = "NULL";
		}
		
		YAML::Node limitNode = resetNodes[i]["limit"];
		if(limitNode != NULL){
			limit = limitNode.as<string>();
		}
		else {
			limit = "NULL";
		}

		YAML::Node roomNode = resetNodes[i]["room"];
		if(roomNode != NULL){
			room = roomNode.as<string>();
		}
		else {
			room = "NULL";
		}


		YAML::Node slotNode = resetNodes[i]["slot"];
		if(slotNode != NULL){
			slot = slotNode.as<string>();
		}
		else {
			slot = "NULL";
		}

		cout <<"-----Parsing action------"<< endl;
		cout << "Actions name is " << action << endl << endl;
		cout << "Comment is " << comment << endl << endl;
		cout << "id name is " << resetId << endl << endl;
		cout << "limit is " << limit << endl << endl;
		cout << "room is " << room << endl << endl;
		cout << "slot is " << slot << endl << endl;
		

    	addReset(create(action, comment, resetID, limit, room, slot));

	}
}
