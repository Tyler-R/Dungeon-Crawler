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
  userStats = new abilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
}

/* User constructor for setting up basic information */
User::User(bool isAdmin, string userName, string password, Room currentRoom) {
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  setRoom(currentRoom);
  usedDefaultConstructor = false;
  userStats = new abilityStats();
  playerLevel = START_LEVEL;
  inventory = new Inventory();
}

/* Ensures deletion of the player's inventory and currentRoom if default constructor used*/
User::~User() {
  delete inventory;
}

void User::setUserName(string userName){
  this->userName = userName;
}

string User::getUserName(){
  return userName;
}

void User::setPassword(string password){
  this->password = password;
}

string User::getPassword(){
  return password;
}

void User::setUserType(bool isAdmin){
  this->isAdmin = isAdmin;
}

bool User::getUserType(){
  return isAdmin;
}

void User::setRoom(Room currentRoom){
  this->currentRoom = currentRoom;
}

Room User::getRoom(){
  return currentRoom;
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

  if(playerLevel = levelUpCalc){
    levelUp();
  }
}

int User::getPlayerXP(){
  return playerXP;
}

void User::setLivingStatus(bool isAlive){
  this->isAlive = isAlive;
}

bool User::getLivingStatus(){
  return isAlive;
}

/* ABILITY STAT GETTERS */

int User::getCharisma(){
  return userStats.getCharisma();
}

int User::getDefense(){
  return userStats.getDefense();
}

int User::getDexterity(){
  return userStats.getDexterity;
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

/* ABILTY STAT SETTERS */

void User::setCharisma(int charmisma){
  userStats.setCharisma(charsima);
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
