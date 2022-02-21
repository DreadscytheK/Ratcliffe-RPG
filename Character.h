///Kenny R. - Fantasy RPG Game - Ms. Cullum
#ifndef CHARACTER
#define CHARACTER
#include <iostream>
#include <vector>

using namespace std;

//Creates the character class
class Character
{

public:
    Character();
    Character(int h, int f, int m);

    int operater(int result, int n, int op);

    bool Fight(string graph_choice, int monster_health, string monster_name, int p, int &h_lost);

    //Getters and setters
    int getHealth();
    void setHealth(int h);

    int getFame();
    void setFame(int f);

    int getMoney();
    void setMoney(int m);

    int getSpirit();
    void setSpirit(int s);

    int getMaxHealth();
    void setMaxHealth(int h);

    int getMaxFame();
    void setMaxFame(int f);

    int getMaxMoney();
    void setMaxMoney(int m);

    int getMaxSpirit();
    void setMaxSpirit(int s);

    int getDay();
    void setDay(int d);

    string getChosenCharacter();
    void setChosenCharacter(string c);

    int getDamage();
    void setDamage(int d);

    int getUnlockedSkills(int i);
    void setUnlockedSkills(int i);

    //Setnew methods, two number are given, the first number is the number that will be
    //operated upon, the second number corresponds to an operator, 1 = +, 2 = -, 3 = /, 4 = *
    //Example: setNewMoney(15, 2) This subtracts 15 from the players health
    void setNewHealth(int h, int op);
    void setNewFame(int f, int op);
    void setNewMoney(int m, int op);
    void setNewSpirit(int s, int op);

    void setNewMaxHealth(int h, int op);
    void setNewMaxFame(int f, int op);
    void setNewMaxMoney(int m, int op);
    void setNewMaxSpirit(int s, int op);

    void setNewDay(int d, int op);
    void setNewDamage(int d, int op);

    //Getter, setter and newsetter for magician
    int getMagicianHealth();
    void setMagicianHealth(int h);
    void setMagicianNewHealth(int h, int op);

    //Getters and setters for the win condition
    bool getImmor();
    void setImmor(bool w);

    //Random event method
    void randomEvent();

    void saveGame(string character);
    void loadGame();

    //This method shows the players current stats
    string toString(string char_choice_menu, int aHealthM, int aFameM, int aMoneyM, int aSpiritM);

protected:
    //Private stat variables
    int day;
    int health;
    int fame;
    int money;
    int spirit;

    int maxHealth;
    int maxFame;
    int maxMoney;
    int maxSpirit;

    int magicianHealth;

    int damage;

    vector<int> unlockedSkills;

    bool win = false;
    string chosen_character;
};
#endif
