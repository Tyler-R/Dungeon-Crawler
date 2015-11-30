
//Test run with g++ -I. -g object_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest
// incompelte. Need to work on adding EXTRA description in objects


#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



int main()
{
	using namespace std;

	YAML::Node allNode = YAML::LoadFile("midgaard.yml");
	YAML::Node objectNodes = allNode["OBJECTS"];
	
	string objectId;
	vector<string> objectKeywords; 
	vector<string> objectLongDesc;
	string objectShortDesc;
	vector <string> extra;

	for(int i = 0; (unsigned)i < objectNodes.size(); i++) {
		extra.clear();
		objectId= " ";
		objectKeywords.clear();
		objectLongDesc.clear();
		objectShortDesc=" ";

		cout <<"--New object Created!--"<< endl;

		YAML::Node extraNode = objectNodes[i]["extra"];
		for (int m = 0; m < extraNode.size(); m++){
			if (extraNode[m]["desc"]){
				YAML::Node extraDescNode = extraNode[m]["desc"];
				for(int k = 0; k < extraDescNode.size(); k++){
					extra.push_back(extraDescNode[k].as<string>());
				}	
			} else {
			extra.clear();
			}			
		}

		objectId = objectNodes[i]["id"].as<string>();


		YAML::Node keywordsNode = objectNodes[i]["keywords"];
		for(int k = 0; k < keywordsNode.size(); k++){
			objectKeywords.push_back(keywordsNode[k].as<string>());
		}

		YAML::Node longdescNode = objectNodes[i]["longdesc"];
		for(int k = 0; k < longdescNode.size(); k++){
			objectLongDesc.push_back(longdescNode[k].as<string>());
		}

		objectShortDesc = objectNodes[i]["shortdesc"].as<string>(); 



		
		cout << "Object Id is " << objectId << endl << endl;

		cout << "Object Keywords: " << endl;
		for (auto & keyword : objectKeywords) {
			cout << "-" << keyword << endl;
		}
		cout << endl;

		cout << "longdescs: " << endl;
		for (auto & longdesc : objectLongDesc) {
			cout << longdesc << endl;
		}
		cout << endl;
		for (auto & extraDesc : extra) {
			cout << extraDesc << endl;
		}
		cout << endl;
		cout << "shortdesc: " << objectShortDesc << endl<<endl;

	}
	return 0;
}

