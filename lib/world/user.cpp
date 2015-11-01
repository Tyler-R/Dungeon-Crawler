/* 	User CLASS
	Contains statistics and methods for player inventory and creation
	
	Created by: Jordan Nielsen
*/

#include "user.h"
#include <iostream>
#include <string>
#include <vector>
//#include "Session.h"

using namespace std;

/* Default constructor setting up basic values */
User::User(){
  setUserType(true);
  setUserName("testUser");
  setPassword("password");
  usedDefaultConstructor = true;
  //userStats = new AbilityStats();
  playerLevel = START_LEVEL;
 
  //inventory = new Inventory();
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
 
  //inventory = new Inventory();
  }*/

User::User(bool isAdmin, string userName, string password, shared_ptr<Room> currentRoom, string description) {
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  setRoom(currentRoom);
  setDescription(description);
  //this->session = session;
  //usedDefaultConstructor = false;
  // userStats = new AbilityStats();
  //playerLevel = START_LEVEL;
 
  //inventory = new Inventory();
  }

//Copy Constructor: added by Sarah
User::User(User &user){
  isAdmin = user.getUserType();
  userName = user.getUserType();
  password = user.getPassword();
  currentRoom = user.getRoom();
  description = user.getDescription();

  usedDefaultConstructor = false;

  playerLevel = user.getLevel();

}

/* Ensures deletion of the player's inventory and currentRoom if default constructor used*/
User::~User() {
  // delete inventory;
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

/*void User::notifySession(string notification){
  session.sendMessage(notification);
  }*/

/* ABILITY STAT GETTERS */

/*
int User::getCharisma(){
  return userStats.getCharisma();
}

int User::getDefense(){
  return userStats.getDefense();
}

int User::getDexterity(){
  return userStats.getDexterity();
}

int User::getHealth(){
  return userStats.getHealth();
}

int User::getIntelligence(){
  return userStats.getIntelligence();
}

int User::getStrength(){
  return userStats.getStrength();
}
*/

/* ABILTY STAT SETTERS */

/*
void User::setCharisma(int charmisma){
  userStats.setCharisma(charisima);
}

void User::setDefense(int defense){
  userStats.setDefense(defense);
}

void User::setDexterity(int dexterity){
  userStats.setDexterity(dexterity);
}

void User::setHealth(int health){
  userStats.setHealth(health);
}

void User::setIntelligence(int intelligence){
  userStats.setIntelligence(intelligence);
}

void User::setStrength(int strength){
  userStats.setStrength(strength);
}
*/

////ROOM INTERACTION METHODS Added by Sarah

string User::moveTo(string dir){
  for (auto & door : getRoom()->getDoorList() ) {
    if(door->findKeyword(dir) || door->getLeadsTo()->findKeyword(dir)){
      setRoom(door->getLeadsTo());
      return getRoom()->getDesc();
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
