#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("smurf.yaml");
	YAML::Node resetNodes = allNode["RESETS"];

	string action;
	string comment; 
	string resetId;
	string limit;
	string room;
	string slot;
	string lock;

	for(int i = 0; (unsigned)i < resetNodes.size(); i++) {
		action = " ";
		comment = " ";
		resetId = " ";
		limit = " ";
		room = " ";
		slot = " ";
		lock = " ";

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


		YAML::Node lockNode = resetNodes[i]["lock"];
		if(lockNode != NULL){
			lock = lockNode.as<string>();
		}
		else {
			lock = "NULL";
		}

		cout <<"-----Parsing action------"<< endl;
		cout << "Actions name is " << action << endl << endl;
		cout << "Comment is " << comment << endl << endl;
		cout << "id name is " << resetId << endl << endl;
		cout << "limit is " << limit << endl << endl;
		cout << "room is " << room << endl << endl;
		cout << "slot is " << slot << endl << endl;
	}

	return 0;
}
