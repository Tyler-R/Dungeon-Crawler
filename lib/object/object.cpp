//
//  object.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include "object.h"


// Constructor: create object using class item
Object::Object(string id) {
    Item tempItem;
    
    setID(id);
    setType(tempItem.getType());
    setDamage(tempItem.getDamage());
    setPositive(tempItem.getPositive());
    
}

// destructor
//Object::~Object() {
//    delete objectID;
//    delete objectType;
//    delete objectDamage;
//    delete objectPositive;
//}

void Object::setID(string id) {
    objectID = id;
}

void Object::setType(string s) {
    objectType = s;
}

void Object::setDamage(int i) {
    objectDamage = i;
}

void Object::setPositive(bool b) {
    objectPositive = b;
}

string Object::getID() const{
    return objectID;
}

string Object::getType() const{
    return objectType;
}

int Object::getDamage() const{
    return objectDamage;
}

bool Object::getPositive() const{
    return objectPositive;
}

// helper function -- check attributes
void Object::checkObject() const{
    std::cout << "          Object check function \n";
    std::cout << "the ID is                     " << getID();
    std::cout << "\n";
    std::cout << "the type is                   " << getType();
    std::cout << "\n";
    std::cout << "good(1) or bad(0)             " << getPositive();
    std::cout << "\n";
    std::cout << "good(+) or bad(-)             " << getDamage();
    std::cout << "\n";
    std::cout << "\n";
}
