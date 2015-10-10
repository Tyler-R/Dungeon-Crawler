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
    setType(tempItem.GetType());
    setDamage(tempItem.GetDamage());
    setPositive(tempItem.GetPositive());
}

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
