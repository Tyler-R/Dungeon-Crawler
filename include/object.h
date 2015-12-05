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

	// constructor
	Object(string id);

	// destructor
	// ~Object();
	
	// functions
	void setID(string id);
	
	string getID() const;
	string getType() const;
	int getDamage() const;
	bool getPositive() const;
    
    // helper function
    void checkObject() const;   // print out all attributes of object
};
#endif