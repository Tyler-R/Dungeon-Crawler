/*Header file for user.cpp
Created By: Jordan Nielsen
*/
#pragma once
#include "room.h"
#include "abilityStats.h"
#include "inventory.h"
//#include "Session.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <functional>

using namespace std;

class Room; //Forward declaration is needed since User class and Room class refer to each other

class User {
  public:
    User();

    //TODO: USE THIS ONE WHEN MERGED AND SESSION.H IS AVAILABLE!!
    /*User constructor for setting up basic information*/
    // User(bool isAdmin, string userName, string password, Room currentRoom,Session session, string description);

    User(bool isAdmin, string userName, string password, shared_ptr<Room> currentRoom, string description);
     User(User &user); //Copy constructor added by Sarah
    ~User();

    void setUserName(string s);
    string getUserName();

    string getPassword();

    void setUserType(bool b);
    bool getUserType();
		
    void setRoom(shared_ptr<Room> newRoom);
    shared_ptr<Room> getRoom();

    void setDescription(string s);
    string getDescription();

    void levelUp();
    int getLevel();

    void increaseXP(int additionalXP);
    int getXP();

    void setLivingStatus(bool b);
    bool getLivingStatus();

    //void notifySession(string notification);

    //ROOM INTERACTION METHODS added by Sarah
    string moveTo(string dir);
    string lookAt(string objName);
    string lookAround();
    vector<string> lookExits();
    vector<string> lookObjList();
    vector<string> lookObjKeywords(string objName);
    string takeItem(string objName);

    void setMessageDisplayer(std::function<void(string)> newMessageDisplayer);
    void notifySession(string notification);

    /*INVENTORY INTERACTION METHODS added by Jordan*/
    string viewInventory();
    string useItem(string itemName);

    int getCharisma();
    int getDefense();
    int getDexterity();
    int getHealth();
    int getIntelligence();
    int getStrength();
		
 private:
    const int START_LEVEL = 1;
    
    string userName;
    string password;
    string description;
    weak_ptr<Room> currentRoom;

    std::function<void(string)> messageDisplayer;


    //Session session;


    AbilityStats* userStats;


    Inventory* inventory;

		
    bool usedDefaultConstructor;

    int playerLevel;
    int playerXP;

    bool isAdmin;
    bool isAlive;

    void setPassword(string s);

    void setCharisma(int charisma);
    void setDefense(int defense);
    void setDexterity(int dexterity);
    void setHealth(int health);
    void setIntelligence(int intelligence);
    void setStrength(int strength);
};
