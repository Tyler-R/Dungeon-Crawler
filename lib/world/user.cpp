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
User::User() : Entity( 10 ) {
  setUserType(true);
  setUserName("testUser");
  setPassword("password");
  userStats = new AbilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
}

User::User(bool isAdmin, string userName, string password, shared_ptr<Room> currentRoom, string description) 
    : Entity( 10 )
{
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  setRoom(currentRoom);
  setDescription(description);
  userStats = new AbilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
}

//Copy Constructor: added by Sarah
User::User(User &user) : Entity( 10 ) {
  isAdmin = user.getUserType();
  userName = user.getUserName();
  password = user.getPassword();
  currentRoom = user.getRoom();
  description = user.getDescription();
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
  getRoom()->broadcastMessage(this, getUserName() + " just levelled up! Hooray!");
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
      getRoom()->broadcastMessage(this, getUserName() + " left the room."+ "\n");
      getRoom()->transferOutUser(getUserName(), door->getLeadsTo());
      setRoom(door->getLeadsTo());
      getRoom()->broadcastMessage(this, getUserName() + " has entered the room."+ "\n");
      return "You are now in the " + getRoom()->getName() + ".\n" + getRoom()->getDesc()+ "\n";
    }
  }
  return "Cannot go there!\n"; 
}

string User::lookAt(string itemKeyword){
  return getRoom()->lookAt(itemKeyword);
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

string User::lookObjKeywords(string itemKeyword){
  string result = "";
  for (auto & keyword : getRoom()->getObjKeywords(itemKeyword)){
    result = result + keyword + "\n";
  }
  return result;
}

////ITEM INTERACTION METHODS Added by Sarah and edited by Jordan
string User::takeItem(string itemKeyword){
  for (auto & item : getRoom()->getItems() ) {
    if(item->searchKeyword(itemKeyword)){
      inventory->addItem(item);
      getRoom()->removeItem(item->getID());
      getRoom()->broadcastMessage(this, getUserName() + " took a " + item->getShortDesc() + "."+ "\n");
      return "You took a " + item->getShortDesc() + "\n";
    }
  }
  return "Cannot take that item.\n";
}

/*INVENTORY INTERACTION METHODS*/
string User::viewInventory(){
  return inventory->lookAtInventory();
}

string User::useItem(string itemKeyword){
  string result = (inventory->useItem(itemKeyword));
  return result;
}

/*Removes item from inventory and places it back into the room*/
string User::tossItem(string itemKeyword){
  int initialInventorySize = inventory->getSize();
  string result = (inventory->removeItem(itemKeyword));
  int currentInventorySize = inventory->getSize();

  if(initialInventorySize != currentInventorySize){
    result = result + " and thrown on the floor" + "\n";
    string itemName = inventory->getItemName(itemKeyword);
    getRoom()->broadcastMessage(this, getUserName() + " just tossed " + itemName + " on the floor."+ "\n");
  }
  
  return result;
}

string User::getInvItemLongDesc(string itemKeyword){
  return inventory->getItemDescription(itemKeyword);
}


// THESE ARE NOW IMPLEMENTED IN THE COMMANDPARSER validateAttackNPCArgv() method
/*BATTLING METHODS  --  ONLY NPC SO FAR!*/
string User::attackNPC(string npcName){ // DEPRECATED
  string result;
  for (auto & NPC : getRoom()->getNPCs() ) {
    if(NPC->searchKeyword(npcName)){
      int userAttack = userStats->getStrength();

      NPC->damage( userAttack );

      int NPCAttack = 0;
      if(NPC->isAlive()) {
        NPCAttack = NPC->getDamage();
      } else {
        NPCAttack = NPC->DEAD_DAMAGE;
      }
      
      string NPCShortDesc = NPC->getShortDesc();
      getRoom()->broadcastMessage(this, getUserName() + " just attacked " + NPCShortDesc+ "\n");

      result = getAttacked(NPCAttack, NPCShortDesc) + NPCShortDesc;
      return result;
    } 
    //THIS SHOULD NEVER OCCUR BUT WE'LL SEE
  }
  return "Somehow the NPC could not be found\n";
    
  
}

string User::getAttacked(int NPCAttack, string NPCShortDesc){ // DEPRECATED
  if(NPCAttack == 0){
    getRoom()->broadcastMessage(this, getUserName() + " just killed " + NPCShortDesc+ "\n");
    increaseXP(KILLED_NPC_EXPERIENCE);
    return "You have just succeeded in killing\n";
  }
  else{
    string result;
    int userHealth = getHealth();
    if(userHealth > NPCAttack){
      damage(NPCAttack);
      result = "You have just taken " + to_string(NPCAttack) + 
                      " damage from ";
    }
    else{
      getRoom()->broadcastMessage(this, getUserName() + " was just killed by " + NPCShortDesc+ "\n");
      result = "You have just been killed. Awwwwwe\n";
    }
    return result;
  }
}

// ADMIN ONLY METHODS
