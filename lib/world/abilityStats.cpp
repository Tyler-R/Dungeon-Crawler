#include "abilityStats.h"

AbilityStats::AbilityStats(){
  setStrength(DEF_STRENGTH);
  setDefense(DEF_DEFENSE);
  setIntelligence(DEF_INTELLIGENCE);
  setDexterity(DEF_DEXTERITY);
  setCharisma(DEF_CHARISMA);
}

//Copy Constructor
AbilityStats::AbilityStats(AbilityStats *stats){
  strength = stats->getStrength();
  defense = stats->getDefense();
  intelligence = stats->getIntelligence();
  dexterity = stats->getDexterity();
  charisma = stats->getCharisma();
}

AbilityStats::~AbilityStats(){
}

//GETTERS

int AbilityStats::getStrength(){
  return strength;
}

int AbilityStats::getDefense(){
  return defense;
}

int AbilityStats::getIntelligence(){
  return intelligence;
}

int AbilityStats::getDexterity(){
  return dexterity;
}

int AbilityStats::getCharisma(){
  return charisma;
}

void AbilityStats::levelUp(){
  strength++;
  defense++;
  intelligence++;
  dexterity++;
  charisma++;
}
  
//SETTERS

void AbilityStats::setStrength(int strength){
  this->strength = strength;
}

void AbilityStats::setDefense(int defense){
  this->defense = defense;
}

void AbilityStats::setIntelligence(int intelligence){
  this->intelligence = intelligence;
}

void AbilityStats::setDexterity(int dexterity){
  this->dexterity = dexterity;
}

void AbilityStats::setCharisma(int charisma){
  this->charisma = charisma;
}
