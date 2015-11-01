/*Header file for abilityStats.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbilityStats {
  public:
    AbilityStats();
	  
    ~AbilityStats();

    void setHealth(int health);
    int getHealth();

    void setStrength(int attack);
    int getStrength();

    void setDefense(int defense);
    int getDefense();

    void setIntelligence(int intelligence);
    int getIntelligence();

    void setDexterity(int dexterity);
    int getDexterity();

    void setCharisma(int charisma);
    int getCharisma();

  private:
    const int maxHealth = 10;
    int health;
    int strength;
    int defense;
    int intelligence;
    int dexterity;
    int charisma;
};
