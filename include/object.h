//
//  object.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef object_h_
#define object_h_

#include "item.h"
using namespace std;

class Object{

private:
	// attributes
	string objectID;
	string objectType;
	int objectDamage;
	bool objectPositive;

	// functions
	void setType(string s);
	void setDamage(int i);
	void setPositive(bool b);

public:

	Object(string id);

	// functions
	void setID(string id);
	
	string getID() const;
	string getType() const;
	int getDamage() const;
	bool getPositive() const;
}