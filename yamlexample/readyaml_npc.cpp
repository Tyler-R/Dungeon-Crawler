// parameter name = the name of the yaml file
void ClassName::functionName(string name){

	// path to find the yaml file
	string fileName="./PathToYaml/"+name+".yml";
	
	// load file to the allNode, which store all the information
	YAML::Node allNode = YAML::LoadFile(fileName);	

	// sets root node on 'any' category, such as NPCS, RESETS, ROOMS etc in the yaml file.
	YAML::Node rootNode = allNode["NPCS"];
	
	// go through all NPCS blocks on yaml file (only read NPCS)
	for (int i = 0; i < rootNode.size(); i++) {

		// get description
		YAML::Node descriptionNode = rootNode[i]["description"];
		string npcDescription;
		for(int j = 0; j < descriptionNode.size(); j++){
			npcDescription += descriptionNode[j].as<string>()+" ";
		}

		// get npc id
		int npcID=rootNode[i]["id"].as<int>();
		// get npc keyword (string or vector<string>)
		string npcKeyword=charNode[i]["keywords"].as<string>();
		// get long desc
		string npcLongDesc = rootNode[i]["longdesc"].as<string>();
		// get short desc
		string npcShortDesc = rootNode[i]["shortdesc"].as<string>();
		
		// (the name of vector which store npc).push_back all informations read from yaml
		npcVector.push_back(NPC(npcDescription,npcID,npcKeyword,npcLongDesc,npcShortDesc));
		
	}
}