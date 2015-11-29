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

    //Copy Constructor
    AbilityStats(AbilityStats *stats);

    ~AbilityStats();

    int getStrength();
    int getDefense();
    int getIntelligence();
    int getDexterity();
    int getCharisma();

    void levelUp();

    void setStrength(int strength);
    void setDefense(int defense);
    void setIntelligence(int intelligence);
    void setDexterity(int dexterity);
    void setCharisma(int charisma);

  private:
    int strength;
    int defense;
    int intelligence;
    int dexterity;
    int charisma;

    //Default values
    static const int DEF_STRENGTH = 5;
    static const int DEF_DEFENSE = 5;
    static const int DEF_INTELLIGENCE = 5;
    static const int DEF_DEXTERITY = 5;
    static const int DEF_CHARISMA = 5;
};
