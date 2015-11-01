//
//  item.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-04.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>
#include "item.h"

const int boostDamage = 1;      // increase damage by 1 (weapon)
const int recoverHP = 1;        // recover hp by 1 (potion)
const int increaseMaxHP = 1;    // increase max hp by 1 (armor)

//Constructor (type, id)
// Item::Item(string type, string id) {
//     setID(id);
//     //setAll(type);
// }

//destructor
// Item::~Item() {
// }

// void Item::setAll(string type) {
//     if(type == "armor"){
//         string tempName[] = {"Shield", "Cloak", "Chest", "Wrist", "Helmet"};
//         itemBoost = increaseMaxHP;
//         int randName = rand() % (5);
//         itemName = tempName[randName];
//         itemType = type;
//     }else if(type == "weapon"){
//         string tempName[] = {"Axe", "Mace", "Sword", "Bow", "Gun"};
//         itemBoost = boostDamage;
//         int randName = rand() % (5);
//         itemName = tempName[randName];
//         itemType = type;
//     }else if(type == "potion"){
//         string tempName[] = {"Heal potion", "energy potion", "revive potion", "herbs", "healing tonic"};
//         itemBoost = recoverHP;
//         int randName = rand() % (5);
//         itemName = tempName[randName];
//         itemType = type;
//     }
//     else{
//         cout << "please choose 'weapon', 'armor', 'potion'. \n";
//     }
// }

// Constructor (id)
Item::Item(string id){
    setID(id);
}
// copy
Item::Item(Item *item){
    itemID = item->getID();
    longDesc = item->getLongDesc();
    shortDesc = item->getShortDesc();

    for(auto & key : item->getKeyword()){
        keywords.push_back(key);
    }   
}

// Description functions
void Item::addLongDesc(string s){
    longDesc = s;
}
void Item::addShortDesc(string s){
    shortDesc = s;
}
string Item::getLongDesc()const{
    return longDesc;
}
string Item::getShortDesc()const{
    return shortDesc;
}
// Keyword functions
void Item::addKeyword(string s){
    keywords.push_back(s);
}
void Item::addKeywords(vector<string> s){
    for(auto & tempKey : s ){
        addKeyword(tempKey);
    }
}
bool Item::searchKeyword(string s)const{
    for(auto & tempKey : keywords){
        if(s.compare(tempKey) == 0){
            return true;
        }
    }
    return false;
}
void Item::removeKeyword(string s){
    if(searchKeyword(s) == true){
        for(int i = 0; i < keywords.size(); i++){
            if(s.compare(keywords[i]) == 0){
                keywords.erase(keywords.begin()+i);
            }
        }
    }else{
        cout<<"The Keyword are not exist!!!"<<endl;
    }
}
void Item::removeAllKeyword(){
    keywords.clear();
}
vector<string> Item::getKeyword()const{
    return keywords;
}
void Item::printVector()const{
    for(auto & kw : keywords){
        cout << kw << endl;
    }
}
// ID -- setter, getter
void Item::setID(string id) {
    itemID = id;
}

string Item::getID() const {
    return itemID;
}




// save for later (status)
string Item::getType() const{
    return itemType;
}

string Item::getName() const{
    return itemName;
}

int Item::getBoost() const{
    return itemBoost;
}


void Item::checkItem() const {
    std::cout << "Item check function \n";
    std::cout << "the ID of the item            " << getID();
    std::cout << "\n";
    std::cout << "the type is                   " << getType();
    std::cout << "\n";
    std::cout << "the name is                   " << getName();
    std::cout << "\n";
    std::cout << "depend on the item's type     " << getBoost();
    std::cout << "\n";
    std::cout << "\n";
}