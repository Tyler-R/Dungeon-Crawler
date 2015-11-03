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
      getRoom()->announcement(getUserName() + " left the room."+ "\n");
      getRoom()->transferOutUser(getUserName(), door->getLeadsTo());
      setRoom(door->getLeadsTo());
      getRoom()->announcement(getUserName() + " has entered the room."+ "\n");
      return "You are now in the " + getRoom()->getName() + ".\n" + getRoom()->getDesc()+ "\n";
    }
  }
  return "Cannot go there!\n"; 
}

string User::lookAt(string objName){
  return getRoom()->lookAt(objName);
}

string User::lookAround(){
  return getRoom()->lookAround();
}

string User::lookExits(){
  return getRoom()->getDoorDescList();
}

string User::lookObjList(){
  return getRoom()->getObjList();
}

string User::lookObjKeywords(string objName){
  string result = "";
  for (auto & keyword : getRoom()->getObjKeywords(objName)){
    result = result + keyword + "\n";
  }
  return result;
}

////ITEM INTERACTION METHODS Added by Sarah and edited by Jordan
string User::takeItem(string objName){
  for (auto & item : getRoom()->getItems() ) {
    if(item->searchKeyword(objName)){
      inventory->addItem(item);
      getRoom()->removeItem(item->getID());
      getRoom()->announcement(getUserName() + " took a " + item->getShortDesc() + "."+ "\n");
      return "You took a " + item->getShortDesc() + "\n";
    }
  }
  return "Cannot take that item.\n";
}

/*INVENTORY INTERACTION METHODS*/
string User::viewInventory(){
  return inventory->lookAtInventory();
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
    string itemName = inventory->getItemName(itemID);
    getRoom()->announcement(getUserName() + " just tossed " + itemName + " on the floor"+ "\n");
  }
  
  return result;
}

/*BATTLING METHODS  --  ONLY NPC SO FAR!*/
string User::attackNPC(string npcName){
  string result;
  for (auto & NPC : getRoom()->getNPCs() ) {
    if(NPC->searchKeyword(npcName)){
      int userAttack = userStats->getStrength();
      int NPCAttack = NPC->getHit(userAttack);
      string NPCShortDesc = NPC->getShortDesc();
      getRoom()->announcement(getUserName() + " just attacked " + NPCShortDesc+ "\n");

      result = getAttacked(NPCAttack, NPCShortDesc) + NPCShortDesc;
      return result;
    } 
    //THIS SHOULD NEVER OCCUR BUT WE'LL SEE
  }
  return "Somehow the NPC could not be found\n";
    
  
}

string User::getAttacked(int NPCAttack, string NPCShortDesc){
  if(NPCAttack == 0){
    getRoom()->announcement(getUserName() + " just killed " + NPCShortDesc+ "\n");
    return "You have just succeeded in killing\n";
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
      getRoom()->announcement(getUserName() + " was just killed by " + NPCShortDesc+ "\n");
      setLivingStatus(false);
      result = "You have just been killed. Awwwwwe\n";
    }
    return result;
  }
}

// ADMIN ONLY METHODS
