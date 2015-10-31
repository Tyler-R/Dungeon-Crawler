/*Header file for user.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include "room.h"
#include "abilityStats.h"
//#include "session.h"
#include <string>
#include <vector>

using namespace std;

class User {
  public:
    User();

    //TODO: USE THIS ONE WHEN MERGED AND SESSION.H IS AVAILABLE!!
    /*User constructor for setting up basic information*/
    // User(bool isAdmin, string userName, string password, Room currentRoom,Session session, string description);

     User(bool isAdmin, string userName, string password, Room currentRoom, string description);

    ~User();

    void setUserName(string userName);
    string getUserName();

    string getPassword();

    void setUserType(bool isAdmin);
    bool getUserType();
		
    void setRoom(Room currentRoom);
    Room getRoom();

    void setDescription(string description);
    string getDescription();

    void levelUp();
    int getLevel();

    void increaseXP(int additionalXP);
    int getXP();

    void setLivingStatus(bool isAlive);
    bool getLivingStatus();


    // void notifySession(string notification);

    /*
    int getCharisma();
    int getDefense();
    int getDexterity();
    int getHealth();
    int getIntelligence();
    int getStrength();
    */
		
 private:
    const int START_LEVEL = 1;
    
    string userName;
    string password;
    string description;
    Room currentRoom;


    // Session session;


    //AbilityStats userStats;


    // Inventory inventory;

		
    bool usedDefaultConstructor;

    int playerLevel;
    int playerXP;

    bool isAdmin;
    bool isAlive;

    void setPassword(string password);

    /*
    void setCharisma(int charisma);
    void setDefense(int defense);
    void setDexterity(int dexterity);
    void setHealth(int health);
    void setIntelligence(int intelligence);
    void setStrength(int strength);

    */
};
