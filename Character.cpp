///Kenny R. - Fantasy RPG Game
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include "Character.h"

using namespace std;

Character::Character()
{
    //Default stats for a new character
    health = 15;
    fame = 15;
    money = 15;
}

Character::Character(int h, int f, int m)
{
    //This is never used, but is there in case someone wanted to test a new character class
    health = h;
    fame = f;
    money = m;
}
//Health setter and getter
void Character::setHealth(int h)
{
    health = h;
}
int Character::getHealth()
{
    return health;
}

//Fame setter and getter
void Character::setFame(int f)
{
    fame = f;
}
int Character::getFame()
{
    return fame;
}

//Money setter and getter
void Character::setMoney(int m)
{
    money = m;
}
int Character::getMoney()
{
    return money;
}

//Spirit setter and getter
void Character::setSpirit(int s)
{
    spirit = s;
}
int Character::getSpirit()
{
    return spirit;
}

//Health setter and getter
void Character::setMaxHealth(int h)
{
    maxHealth = h;
}
int Character::getMaxHealth()
{
    return maxHealth;
}

//Fame setter and getter
void Character::setMaxFame(int f)
{
    maxFame = f;
}
int Character::getMaxFame()
{
    return maxFame;
}

//Money setter and getter
void Character::setMaxMoney(int m)
{
    maxMoney = m;
}
int Character::getMaxMoney()
{
    return maxMoney;
}

//Spirit setter and getter
void Character::setMaxSpirit(int s)
{
    maxSpirit = s;
}
int Character::getMaxSpirit()
{
    return maxSpirit;
}

//Magician health setter and getter
void Character::setMagicianHealth(int h)
{
    magicianHealth = h;
}

int Character::getMagicianHealth()
{
    return magicianHealth;
}

//Day setter and getter
void Character::setDay(int d)
{
    day = d;
}

int Character::getDay()
{
    return day;
}

void Character::setChosenCharacter(string c)
{
    chosen_character = c;
}

string Character::getChosenCharacter()
{
    return chosen_character;
}

void Character::setDamage(int d)
{
    damage = d;
}

int Character::getDamage()
{
    return damage;
}

void Character::setUnlockedSkills(int i)
{
    switch(i)
        {
        case 1:
            unlockedSkills[0] = 1;
            break;
        case 2:
            unlockedSkills[1] = 1;
            break;
        case 3:
            unlockedSkills[2] = 1;
            break;
        case 4:
            unlockedSkills[3] = 1;
            break;
        }
}

//Adds, subtracts, divides or multiplies numbers given
int Character::operater(int result, int n, int op)
{
    switch(op)
        {
        case 1:
            result += n;
            break;
        case 2:
            result -= n;
            break;
        case 3:
            result /= n;
            break;
        case 4:
            result *= n;
            break;
        }

    return result;
}

//NewSetters, all of them take in two variables
void Character::setNewDamage(int d, int op)
{
    damage = operater(damage,  d,  op);
}

void Character::setNewDay(int d, int op)
{
    day = operater(day,  d,  op);
}

void Character::setMagicianNewHealth(int h, int op)
{
    magicianHealth = operater(magicianHealth,  h,  op);
}

void Character::setNewHealth(int h, int op)
{
    health = operater(health,  h,  op);
}

void Character::setNewFame(int f, int op)
{
    fame = operater(fame,  f,  op);
}

void Character::setNewMoney(int m, int op)
{
    money = operater(money,  m,  op);
}

void Character::setNewSpirit(int s, int op)
{
    spirit = operater(spirit,  s,  op);
}

void Character::setNewMaxHealth(int h, int op)
{
    maxHealth = operater(maxHealth,  h, op);
}

void Character::setNewMaxFame(int f, int op)
{
    maxFame = operater(maxFame,  f,  op);
}

void Character::setNewMaxMoney(int m, int op)
{
    maxMoney = operater(maxMoney,  m,  op);
}

void Character::setNewMaxSpirit(int s, int op)
{
    maxSpirit = operater(maxSpirit,  s,  op);
}


//Random event method, picks a random number and makes something happen
void Character::randomEvent()
{
    //Declaring variables
    string choice = " ";
    int choice2 = 0;

    //Picks a random number between 1 and 30
    int ran_num = 1 + (rand() % 30);

    //Switch statement takes random number and completes actions
    switch(ran_num)
        {
        case 1:
            cout << "\nWow! You found 10$ on the ground, what luck!\n";
            setNewMoney(10, 1);
            break;
        case 2:
            cout << "\nWhat!? You stepped on a nail and lost 7 health!\n";
            setNewHealth(7, 2);
            break;
        case 3:
            while(choice.compare("1")!=0&&choice.compare("2")!=0)
                {
                    cout << "\nYou see some bread on the ground, eat it?\n    1:  Yes\n    2:  No\n\n";
                    cin >> choice;

                    if(choice.compare("1")!=0&&choice.compare("2")!=0)
                        {
                            cout << "\nPick 1 or 2\n";
                        }
                }

            //This asks the user if they want to eat the bread and it has a 1 in 3 chance of healing them
            if(choice.compare("1")==0)
                {
                    choice2 = 1 + (rand() % 3);

                    if(choice2==1)
                        {
                            setNewHealth(5,1);
                            cout << "\nYou gained 5 health\n";
                        }
                    else
                        {
                            setNewHealth(5,2);
                            cout << "\nYou lost 5 health\n";
                        }
                }
            break;
        case 4:
            cout << "\nOh no! Someone stole 5$ from you!\n";
            setNewMoney(5,2);
            break;
        }

    cout << endl;
}

//Setters and getters for immortality
void Character::setImmor(bool w)
{
    win = w;
}

bool Character::getImmor()
{
    return win;
}

///This method displays the characters stats to the screen, takes in 4 variables to display stats
string Character::toString(string char_choice_menu, int aHealthM, int aFameM, int aMoneyM, int aSpiritM)
{

    string stats = "Character: ";
    stats += char_choice_menu;
    stats += "\nHealth: ";
    stats += static_cast<ostringstream*>( &(ostringstream() << health) )->str();
    stats += "/";
    stats += static_cast<ostringstream*>( &(ostringstream() << aHealthM) )->str();
    if(aSpiritM>0)
        {
            stats += "\nInfamy: ";
        }
    else
        {
            stats += "\nFame: ";
        }
    stats += static_cast<ostringstream*>( &(ostringstream() << fame) )->str();
    stats += "/";
    stats += static_cast<ostringstream*>( &(ostringstream() << aFameM) )->str();
    stats += "\nMoney: ";
    stats += static_cast<ostringstream*>( &(ostringstream() << money) )->str();
    stats += "/";
    stats += static_cast<ostringstream*>( &(ostringstream() << aMoneyM) )->str();

    if(aSpiritM>0)
        {
            stats += "\nSpirit: ";
            stats += static_cast<ostringstream*>( &(ostringstream() << spirit) )->str();
            stats += "/";
            stats += static_cast<ostringstream*>( &(ostringstream() << aSpiritM) )->str();
        }

    return stats;
}

///This method takes in graph_choice so it can disable allegro, monster_health is the monster's health,
///monster_name sets the monster's name, p is the difficulty of the monster and h_lost is the total health
///lost while the player was played this, it is returned back.
bool Character::Fight(string graph_choice, int monster_health, string monster_name, int p, int &h_lost)
{
    //Declaring variables
    int result = 0, turn = 1, leave = 0;
    string player_choice = " ";
    string player_choice2 = " ";
    bool win = true;
    int autoBattle = 0;
    int sleepTime = 1;

    //Makes things random
    srand((unsigned) time(0));

    //While statement ends when monster_health equals 0, it also ends if the players health reaches zero with a break command
    while(monster_health>0)
        {

            //Displays the turn
            cout << "\n    Turn " << turn;

            if(autoBattle==0)
                {

                    //Tells the player who they are up against and their stats
                    cout << "\n\nYou are fighting a " << monster_name << " with " << monster_health << " health left.\nYou have " << health << " health left, " << spirit << " spirit left and " << fame << " infamy.\n";

                    //Tells the user their options, they are displayed based on the amount of spirit they have
                    cout << "What would you like to do?\n\n    0:  Auto Battle for three turns (" << 3+damage << " dmg. -0sp)\n    1:  Exchange infamy for health (6 dmg. -6 inf)\n    2:  Attack (" << 3+damage << " dmg, -0 sp)\n";
                    if(spirit>=4)
                        {
                            cout << "    3:  Scratch (" << 7+damage << " dmg, -4 sp)\n";
                        }
                    if(spirit>=8)
                        {
                            cout << "    4:  Double Kick (" << 15+damage << " dmg, -8 sp)\n";
                        }
                    if(spirit>=10&&p!=3)
                        {
                            cout << "    5:  Instant Kill (";
                            if(unlockedSkills[2]==1)
                                {
                                    cout << "60% chance of working, -10 sp)\n";
                                }
                            else if(unlockedSkills[1]==1)
                                {
                                    cout << "40% chance of working, -10 sp)\n";
                                }
                            else
                                {
                                    cout << "20% chance of working, -10 sp)\n";
                                }

                        }
                    if(unlockedSkills[1]==1&&spirit==maxSpirit&&health>=maxHealth/2)
                        {
                            cout << "    6:  Dark Threat (" << 200+damage << " dmg, -all sp, -50% hp)\n";
                        }


                }

            //Formatting
            cout << endl;

            if(autoBattle==0)
                {
                    //Makes sure the player picks the right option
                    while(player_choice2.compare("1337")!=0)
                        {
                            cin >> player_choice;

                            if(player_choice.compare("6")==0&&unlockedSkills[1]==1&&spirit==maxSpirit&&health>=maxHealth/2)
                                {
                                    monster_health-=200+damage;
                                    if(p==3)
                                        {
                                            setMagicianNewHealth(200+damage,2);
                                        }
                                    setSpirit(0);
                                    setNewHealth(maxHealth/2, 2);
                                    cout << "You did " << 200+damage << " damage, lost all spirit and lost " << maxHealth/2 << " health";

                                    sleep(sleepTime);

                                    player_choice2 = "1337";
                                }
                            else if(player_choice.compare("5")==0&&spirit>=10)
                                {
                                    //This one picks a random number between 1 and 10, if the number is 1,2 or 3 then it kills the enemy
                                    result = 1 + (rand() % 10);

                                    if(unlockedSkills[2]==1)
                                    {
                                        if(result>=1&&result<=6)
                                                {
                                                    monster_health = 0;
                                                    setNewSpirit(10,2);
                                                    cout << "Your instant kill hit";
                                                }
                                            else
                                                {
                                                    setNewSpirit(10,2);
                                                    cout << "Your instant kill missed";
                                                }
                                    }
                                    else if(unlockedSkills[0]==1)
                                        {
                                            if(result==1||result==2||result==3||result==4)
                                                {
                                                    monster_health = 0;
                                                    setNewSpirit(10,2);
                                                    cout << "Your instant kill hit";
                                                }
                                            else
                                                {
                                                    setNewSpirit(10,2);
                                                    cout << "Your instant kill missed";
                                                }
                                        }
                                    else
                                        {
                                            if(result==1||result==2)
                                                {
                                                    monster_health = 0;
                                                    setNewSpirit(10,2);
                                                    cout << "Your instant kill hit";
                                                }
                                            else
                                                {
                                                    setNewSpirit(10,2);
                                                    cout << "Your instant kill missed";
                                                }
                                        }

                                    sleep(sleepTime);

                                    player_choice2 = "1337";
                                }
                            else if(player_choice.compare("4")==0&&spirit>=8)
                                {
                                    monster_health-=15+damage;
                                    if(p==3)
                                        {
                                            setMagicianNewHealth(15+damage,2);
                                        }
                                    setNewSpirit(8,2);
                                    cout << "You did " << 15+damage << " damage and lost 8 spirit";

                                    sleep(sleepTime);

                                    player_choice2 = "1337";
                                }
                            else if(player_choice.compare("3")==0&&spirit>=4)
                                {
                                    monster_health-=7+damage;
                                    if(p==3)
                                        {
                                            setMagicianNewHealth(7+damage,2);
                                        }
                                    setNewSpirit(4,2);
                                    cout << "You did " << 7+damage << " damage and lost 4 spirit";

                                    sleep(sleepTime);

                                    player_choice2 = "1337";
                                }
                            else if(player_choice.compare("2")==0)
                                {
                                    monster_health-=3+damage;
                                    if(p==3)
                                        {
                                            setMagicianNewHealth(3+damage,2);
                                        }
                                    cout << "You did " << 3+damage << " damage";

                                    sleep(sleepTime);

                                    player_choice2 = "1337";
                                }
                            else if(player_choice.compare("1")==0)
                                {
                                    setNewHealth(6,1);
                                    setNewFame(6,2);
                                    cout << "You have lost 6 infamy, but gained 6 health";

                                    sleep(sleepTime);

                                    player_choice2 = "1337";
                                }
                            else if(player_choice.compare("0")==0)
                                {
                                    player_choice2 = "1337";
                                }
                            else
                                {
                                    cout << "\nPlease enter a valid option\n";
                                }
                        }
                }

            if(player_choice.compare("0")==0)
                {
                    if(autoBattle==0)
                        {
                            autoBattle = 3;
                        }

                    monster_health-=3+damage;
                    if(p==3)
                        {
                            setMagicianNewHealth(3+damage,2);
                        }
                    cout << "\nYou did " << 3+damage << " damage";
                }

            //If statements activate based on which option the player picked earlier and then change variables based on that choice
            //If p equals 3, meaning you are fighting the magician, then it will subtract health from the monster_health variable
            //and the magicians health
            //After that it tells the player what happened


            //Formatting
            cout << endl;

            //If statement runs as long as the monster still has health
            if(monster_health>0)
                {

                    //If statement runs if p equals 1, lowest difficulty, it then takes away 2 health from the player and add 2 to h_lost
                    if(p==1)
                        {
                            setNewHealth(2,2);
                            h_lost+=2;
                            cout << "\nThe " << monster_name << " did 2 damage to you";
                        } //Else if statement runs if p equals 2, middle difficulty, it then picks a random number from 1 to 10
                    //and based on what it picks, 2, 4, 5, 3 or 7 health can be taken away from the player, or the monster
                    //can gain 30 health
                    else if(p==2)
                        {

                            result = 1 + (rand() % 10);

                            if(result==1||result==2)
                                {
                                    setNewHealth(2,2);
                                    h_lost+=2;
                                    cout << "\nThe " << monster_name << " did 2 damage to you";
                                }
                            else if(result==3||result==4)
                                {
                                    setNewHealth(4,2);
                                    h_lost+=4;
                                    cout << "\nThe " << monster_name << " did 4 damage to you";
                                }
                            else if(result==5||result==6)
                                {
                                    setNewHealth(5,2);
                                    h_lost+=5;
                                    cout << "\nThe " << monster_name << " did 5 damage to you";
                                }
                            else if(result==7||result==8)
                                {
                                    setNewHealth(3,2);
                                    h_lost+=3;
                                    cout << "\nThe " << monster_name << " did 3 damage to you";
                                }
                            else if(result==9)
                                {
                                    setNewHealth(7,2);
                                    h_lost+=7;
                                    cout << "\nThe " << monster_name << " did 7 damage to you";
                                }
                            else if(result==10)
                                {
                                    monster_health+=30;
                                    cout << "\nThe " << monster_name << " gained 30 health";
                                }
                        } //Else if statement runs if p equals 3, hardest difficulty, it makes a random number between 1 and 10
                    //and then it either takes away 4, 5, 3 or 7 health, he tells you to give up, allows you to stop fighting
                    //or gains 30 health
                    else if(p==3)
                        {
                            result = 1 + (rand() % 10);

                            if(result==1)
                                {
                                    cout << "\nThe " << monster_name << " told you that you will lose and you should give up";
                                }
                            else if(result==2||result==3)
                                {
                                    cout << "\nThe " << monster_name << " offer you a chance to stop fighting and leave\nWill you accept?\n";
                                    cout << "    1:  Yes, leave\n    2:  No, keep fighting\n\n";

                                    //Checks to see if the user picked the right option
                                    while(leave!=1&&leave!=2)
                                        {
                                            cin >> leave;

                                            //Checks to see if the user picked the right option
                                            if(leave!=1&&leave!=2)
                                                {
                                                    cout << "\nPick 1 or 2";
                                                }
                                        }

                                    //If the user picks 1, it lets them leave
                                    if(leave==1)
                                        {
                                            monster_health = 0;
                                            win = false;
                                        }
                                }
                            else if(result==4)
                                {
                                    setNewHealth(4,2);
                                    h_lost+=4;
                                    cout << "\nThe " << monster_name << " did 4 damage to you\n";
                                }
                            else if(result==5||result==6)
                                {
                                    setNewHealth(5,2);
                                    h_lost+=5;
                                    cout << "\nThe " << monster_name << " did 5 damage to you\n";
                                }
                            else if(result==7||result==8)
                                {
                                    setNewHealth(3,2);
                                    h_lost+=3;
                                    cout << "\nThe " << monster_name << " did 3 damage to you\n";
                                }
                            else if(result==9)
                                {
                                    setNewHealth(7,2);
                                    h_lost+=7;
                                    cout << "\nThe " << monster_name << " did 7 damage to you\n";
                                }
                            else if(result==10)
                                {
                                    monster_health+=30;
                                    setMagicianNewHealth(30,1);
                                    cout << "\nThe " << monster_name << " gained 30 health\n";
                                }
                        }
                }

            //Checks if the player died then sets the monsters health to 0 and win to false
            if(getHealth()<=0)
                {
                    monster_health = 0;
                    win = false;
                }

            //Resets the leave variable used in the p==3 fight
            leave = 0;

            if(player_choice.compare("0")==0)
                {
                    autoBattle--;
                }
            else
                {
                    //Resets the player choice
                    player_choice = 1000;

                }

            player_choice2 = 1000;

            if(autoBattle==0)
                {
                    player_choice = 1000;
                    player_choice2 = 1000;
                }

            //Formatting
            cout << endl;

            //Adds 1 to variable turn
            turn++;
        }

    //Returns the state of the battle at the end
    return win;
}

void Character::saveGame(string character)
{
    //Opens SaveGame.txt and closes it, this deletes all numbers that were in there
    fstream SaveGameDelete;
    SaveGameDelete.open ("SaveGame.txt", ofstream::out | ofstream::trunc);

    SaveGameDelete.close();

    //Opens RandomNumbers.txt, putting its contents into an array and closing it
    fstream SaveGame;
    SaveGame.open ("SaveGame.txt");

    if (SaveGame.fail())
        {
            cout << "Error with SaveGame.txt";
            SaveGame.clear();
        }

    SaveGame << character;
    SaveGame << endl;
    SaveGame << day;
    SaveGame << endl;
    SaveGame << health;
    SaveGame << endl;
    SaveGame << fame;
    SaveGame << endl;
    SaveGame << money;
    SaveGame << endl;

    if(character.compare("3")==0)
        {
            SaveGame << spirit;
            SaveGame << endl;
            SaveGame << magicianHealth;
            SaveGame << endl;
            SaveGame << damage;
            SaveGame << endl;
        }

    SaveGame.close();
}

void Character::loadGame()
{
    //Opens SaveGame.txt, putting its contents into an array and closing it
    fstream SaveGame;
    SaveGame.open ("SaveGame.txt");

    //Error checking
    if (SaveGame.fail())
        {
            cout << "Error with SaveGame.txt";
            SaveGame.clear( );
        }


    SaveGame >> chosen_character;
    SaveGame >> day;
    SaveGame >> health;
    SaveGame >> fame;
    SaveGame >> money;

    if(chosen_character.compare("3")==0)
        {
            SaveGame >> spirit;
            SaveGame >> magicianHealth;
            SaveGame >> damage;
        }

    SaveGame.close();
}


