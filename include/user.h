/*Header file for user.cpp
Created By: Jordan Nielsen
*/
#pragma once
#include "room.h"
#include "abilityStats.h"
#include "inventory.h"
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

    /*User constructor for setting up basic information*/

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
    string lookAt(string itemKeyword);
    string lookAround();
    string lookExits();
    string lookObjList();
    string lookObjKeywords(string itemKeyword);
    string takeItem(string itemKeyword);

    void setMessageDisplayer(std::function<void(string)> newMessageDisplayer);
    void notifySession(string notification);

    /*INVENTORY INTERACTION METHODS added by Jordan*/
    string viewInventory();
    string useItem(string itemKeyword);
    string tossItem(string itemKeyword);
    string getInvItemLongDesc(string itemKeyword);

    /*ABILITYSTAT INTERACTION METHODS added by Jordan*/
    int getCharisma();
    int getDefense();
    int getDexterity();
    int getHealth();
    int getIntelligence();
    int getStrength();

    /*BATTLING METHODS  --  ONLY NPC SO FAR  added by Jordan*/
    string attackNPC(string npcName);
    string getAttacked(int NPCAttack, string NPCShortDesc);
		
 private:
    const int START_LEVEL = 1;
    const int KILLED_NPC_EXPERIENCE = 100;
    
    string userName;
    string password;
    string description;
    weak_ptr<Room> currentRoom;

    std::function<void(string)> messageDisplayer;

    AbilityStats* userStats;
    Inventory* inventory;

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
