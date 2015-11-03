/* 	User CLASS
	Contains statistics and methods for player inventory and creation
	
	Created by: Jordan Nielsen
*/

#include "user.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Default constructor setting up basic values */
User::User(){
  setUserType(true);
  setUserName("testUser");
  setPassword("password");
  usedDefaultConstructor = true;
  userStats = new AbilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
}

//TODO: USE THIS ONE WHEN MERGED AND SESSION.H IS AVAILABLE!!
/* User constructor for setting up basic information */
/*User::User(bool isAdmin, string userName, string password, Room currentRoom, Session session, string description) {
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  setRoom(currentRoom);
  setDescription(description);
  this->session = session;
  usedDefaultConstructor = false;
  userStats = new AbilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
  }*/


User::User(bool isAdmin, string userName, string password, shared_ptr<Room> currentRoom, string description) {
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  setRoom(currentRoom);
  setDescription(description);
  //this->session = session;
  //usedDefaultConstructor = false;
  userStats = new AbilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
  }

//Copy Constructor: added by Sarah
User::User(User &user){
  isAdmin = user.getUserType();
  userName = user.getUserName();
  password = user.getPassword();
  currentRoom = user.getRoom();
  description = user.getDescription();

  usedDefaultConstructor = false;

  playerLevel = user.getLevel();

}

/* Ensures deletion of the player's inventory and currentRoom if default constructor used*/
User::~User() {
  delete(userStats);
  delete inventory;
}

void User::setUserName(string s){
  userName = s;
}

string User::getUserName(){
  return userName;
}

void User::setPassword(string s){
  password = s;
}

string User::getPassword(){
  return password;
}

void User::setUserType(bool b){
  isAdmin = b;
}

bool User::getUserType(){
  return isAdmin;
}

void User::setRoom(shared_ptr<Room> newRoom){
  this->currentRoom = newRoom;
}

shared_ptr<Room> User::getRoom(){
  return currentRoom.lock();
}

void User::setDescription(string s){
  description = s;
}

string User::getDescription(){
  return description;
}

//TODO: Add method calls to increase player stats appropriately
void User::levelUp(){
  playerLevel += 1;
  userStats->levelUp();
}

int User::getLevel(){
  return playerLevel;
}

/* Inceases XP and call levelUP if user has passed next 1000XP increment */
void User::increaseXP(int additionalXP){
  playerXP += additionalXP;

  int levelUpCalc = playerXP / playerLevel;

  if(playerLevel == levelUpCalc){
    levelUp();
  }
}

int User::getXP(){
  return playerXP;
}

void User::setLivingStatus(bool b){
  isAlive = b;
}

bool User::getLivingStatus(){
  return isAlive;
}

void User::setMessageDisplayer(function<void(string)> newMessageDisplayer) {
  messageDisplayer = newMessageDisplayer;
}


void User::notifySession(string notification){
  messageDisplayer(notification);
}

/* ABILITY STAT GETTERS */

int User::getCharisma(){
  return userStats->getCharisma();
}

int User::getDefense(){
  return userStats->getDefense();
}

int User::getDexterity(){
  return userStats->getDexterity();
}

int User::getHealth(){
  return userStats->getHealth();
}

int User::getIntelligence(){
  return userStats->getIntelligence();
}

int User::getStrength(){
  return userStats->getStrength();
}

/* ABILTY STAT SETTERS */

void User::setCharisma(int charisma){
  userStats->setCharisma(charisma);
}

void User::setDefense(int defense){
  userStats->setDefense(defense);
}

void User::setDexterity(int dexterity){
  userStats->setDexterity(dexterity);
}

void User::setHealth(int health){
  userStats->setHealth(health);
}

void User::setIntelligence(int intelligence){
  userStats->setIntelligence(intelligence);
}

void User::setStrength(int strength){
  userStats->setStrength(strength);
}

////ROOM INTERACTION METHODS Added by Sarah

string User::moveTo(string dir){
  for (auto & door : getRoom()->getDoorList() ) {
    if(door->findKeyword(dir) || door->getLeadsTo()->findKeyword(dir)){
      getRoom()->announcement(getUserName() + " left the room.");
      getRoom()->transferOutUser(getUserName(), door->getLeadsTo());
      setRoom(door->getLeadsTo());
      getRoom()->announcement(getUserName() + " has entered the room.");
      return "You are now in the " + getRoom()->getName() + ".\n" + getRoom()->getDesc();
    }
  }
  return "Cannot go there"; 
}

string User::lookAt(string objName){
  return getRoom()->lookAt(objName);
}

string User::lookAround(){
  return getRoom()->lookAround();
}

vector<string> User::lookExits(){
  return getRoom()->getDoorDescList();
}

vector<string> User::lookObjList(){
  return getRoom()->getObjList();
}

vector<string> User::lookObjKeywords(string objName){
  return getRoom()->getObjKeywords(objName);
}

////ITEM INTERACTION METHODS Added by Sarah and edited by Jordan
string User::takeItem(string objName){
  for (auto & item : getRoom()->getItems() ) {
    if(item->searchKeyword(objName)){
      getRoom()->removeItem(item->getID());
      inventory->addItem(item);
      getRoom()->announcement(getUserName() + " took a " + objName + ".");
      return "You took a " + objName;
    }
  }
  return "Cannot take that item.";
}

/*INVENTORY INTERACTION METHODS*/
string User::viewInventory(){
  return (inventory->lookAtInventory());
}

string User::useItem(string itemID){
  string result = (inventory->useItem(itemID));
  return result;
}

/*Removes item from inventory and places it back into the room*/
string User::tossItem(string itemID){
  int initialInventorySize = inventory->getSize();
  string result = (inventory->removeItem(itemID));
  int currentInventorySize = inventory->getSize();

  if(initialInventorySize != currentInventorySize){
    result + " and thrown on the floor";
  }
  
  return result;
}

/*BATTLING METHODS  --  ONLY NPC SO FAR!*/
string User::attackNPC(string NPCsID){
  //Call NPC->getHit(getStrength());
  //If return damage is 0, have room remove the NPC with its ID
  string result;

  vector<shared_ptr<NPC>> NPCs = getRoom()->getNPCs();
  for(shared_ptr<NPC> NPC : NPCs){
    if(NPC->getID() == NPCsID){
      int userAttack = userStats->getStrength();
      int NPCAttack = NPC->getHit(userAttack);

      result = getAttacked(NPCAttack) + NPC->getName();
      return result;
    } 
    //THIS SHOULD NEVER OCCUR BUT WE'LL SEE
    else {
      return "Somehow the NPC could not be found";
    }
  }
  
}

string User::getAttacked(int NPCAttack){
  if(NPCAttack == 0){
    return "You have just succeeded in killing";
  }
  else{
    string result;
    int userHealth = userStats->getHealth();
    if(userHealth > NPCAttack){
      userStats->setHealth(userHealth - NPCAttack);
      result = "You have just taken " + to_string(NPCAttack) + 
                      " damage from ";
    }
    else{
      setLivingStatus(false);
      result = "You have just been killed. Awwwwwe";
    }
    return result;
  }
}

// ADMIN ONLY METHODS
