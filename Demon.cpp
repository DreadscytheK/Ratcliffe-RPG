///Kenny R. - Fantasy RPG Game
#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h>
#include "Demon.h"

using namespace std;

Demon::Demon(int h,int f,int m,int s)
{
    Character();

    //Sets stats equal to stat variables
    setHealth(h);
    setFame(f);
    setMoney(m);
    setSpirit(s);
    setDamage(0);

    unlockedSkills.resize(5);
}

Demon::Demon()
{
    Character();

    //Sets the classes default stats
    setHealth(25);
    setFame(25);
    setMoney(15);
    setSpirit(40);
}

///This method will allow the player to chose a method of gaining health, takes in graph_choice which can disable allegro graphics
void Demon::findFood(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));
    int sleepTime = 1;

    //Declaring variables
    int x=0,result=0,y=0,find_choice=0, h_lost = 0, monster_num;
    string menu_choice = " ";
    bool win = false;
    string monster_name;

    //While statement checks to make sure the player chooses the right option
    while(find_choice!=1&&find_choice!=2)
        {

            //Asks the player for their choice
            cout << "\nHow would you like to obtain health\n\n    1:  Gamble with a healing magician\n    2:  Eat something\n\n: ";
            cin >> find_choice;

            //If statement asks player to choose the corrects option if they failed the first time
            if(find_choice!=1&&find_choice!=2)
                {
                    cout << "\nPick 1 or 2";
                }
        }

    //if they choose 1, then a random number is generated and if it is 1, the player's health is maxed,
    //if it is 2, half the player's health is filled and 4$ is taken, if it is 3 or 4, nothing happens
    if(find_choice==1)
        {

            //Random number is generated between 1 and 4
            result = 1 + (rand() % 4);

            //If statement checks if result equals 1
            if(result==1)
                {
                    //Sets health to max
                    setHealth(maxHealth);

                    setNewFame(5,2);

                    //Tells the players the health is maxed
                    cout << "\n\nThe magician maxed out your health! But you lost 5 infamy\n";

                } //Else if checks if result is 2
            else if (result==2)
                {

                    setNewHealth(maxHealth/2, 1);

                    setNewMoney(4, 2);

                    setNewFame(3, 2);

                    //Tells the user what happened
                    cout << "\n\nThe magician healed half your health, but took 4$ and you lost 3 infamy\n";

                } //Else activates when result equals 3 or 4
            else
                {

                    //Tells the user they lost gambling lottery
                    cout << "\n\nThe magician did nothing and told you to leave\n";
                    cout << "Will you leave?\n\n    1:  Stay and fight\n    2:  Leave\n\n";

                    //While statement checks to see if the player chose the right option
                    while(menu_choice.compare("1")!=0&&menu_choice.compare("2")!=0)
                        {
                            cin >> menu_choice;

                            //If statement checks to see if the player chose the right option
                            if(menu_choice.compare("1")!=0&&menu_choice.compare("2")!=0)
                                {
                                    cout << "\nPick 1 or 2";
                                }
                        }

                    //If statement happens if the user picks 1
                    if(menu_choice.compare("1")==0)
                        {

                            //Runs the fight method and returns whether the player wins or did not
                            win = Fight(graph_choice, getMagicianHealth(), "Irate Magician", 3, h_lost);
                        }

                    //If the player one this activates
                    if(win==true)
                        {
                            cout << "\n\nYou have bested the magician and in exchange he grants you immortality, you win!\n";

                            //Sets the win setter to true
                            setImmor(true);
                            win = false;
                        }

                }

        } //This else statement happens when the player chooses option 2
    else
        {

            //makes a random numbers between 1 and 3
            monster_num = 1 + (rand() % 3);

            //Picks a name based on which number is picked
            switch(monster_num)
                {
                case 1:
                    monster_name = "Human";
                    break;
                case 2:
                    monster_name = "Rat";
                    break;
                case 3:
                    monster_name = "Mouse";
                    break;
                }

            //Runs the fight command, returns whether the player won or not
            win = Fight(graph_choice, 13, monster_name, 1, h_lost);

            //If win equals true, it runs this
            if(win==true)
                {
                    //Tells the user what happened
                    cout << "\n\nYou ate a " << monster_name << " and gained 7 health, but also lost " << h_lost << " health\n";
                    setNewHealth(7, 1);
                    sleep(sleepTime);
                }

        }
}

///This method gives the user the choice of how to gain fame, takes in graph_choice which can disable allegro
void Demon::fightMonsters(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));
    int sleepTime = 1;

    //Declaring variables
    int x=0,result=0,y=0,fight_choice=0, h_lost = 0, monster_num;
    bool win;
    string monster_name;

    //While statement makes sure the user picked the right option
    while(fight_choice!=1&&fight_choice!=2)
        {

            //Asks the user which monster they want to fight
            cout << "\nWhich monster do you want to fight?\n\n    1:  Fight a small monster";

            //As long as the players health is more than 14, they can pick this option
            if(getHealth()>14)
                {
                    cout << "\n    2:  Fight a big monster";
                }

            //Formatting
            cout << endl << endl << ": ";

            //Asks the player for their choice
            cin >> fight_choice;

            //As long as their health is above 14, they can pick either option, but if their health is less than 15, they can only pick the first
            if(fight_choice!=1&&getHealth()<14)
                {
                    cout << "\nPick 1\n";
                    fight_choice = 0;
                }
            else if(fight_choice!=1&&fight_choice!=2&&getHealth()>14)
                {
                    cout << "\nPick 1 or 2\n";
                    fight_choice = 0;
                }
        }

    //If statement checks if the player chose the first choice
    if(fight_choice==1)
        {

            //Makes a random number between 1 and 4
            monster_num = 1 + (rand() % 4);

            //Assigns monster_name to whichever string was chosen
            switch(monster_num)
                {
                case 1:
                    monster_name = "Slime";
                    break;
                case 2:
                    monster_name = "Dwarf";
                    break;
                case 3:
                    monster_name = "Raccoon";
                    break;
                case 4:
                    monster_name = "Snake";
                    break;
                }

            //Runs the fight method, returns whether the player won or not
            win = Fight(graph_choice, 20, monster_name, 1, h_lost);

            if(win==true)
                {
                    //Tells the user how much fame they gained and how much health they lost
                    cout << "\n\nYou fought a small monster and gained 3 infamy and have lost " << h_lost << " health\n";
                    setNewFame(3, 1);
                    sleep(sleepTime);
                }
        }
    //Else statement happens if the player picks the other option
    else
        {

            //Makes a random number from 1 to 4
            monster_num = 1 + (rand() % 4);

            //Sets monster name to a string depending on which number is picked
            switch(monster_num)
                {
                case 1:
                    monster_name = "Dragon";
                    break;
                case 2:
                    monster_name = "Big Foot";
                    break;
                case 3:
                    monster_name = "Snapping Turtle";
                    break;
                case 4:
                    monster_name = "The Loch Ness Monster";
                    break;
                }

            //Runs the fight method, returns whether the player won or not
            win = Fight(graph_choice, 60, monster_name, 2, h_lost);

            if(win==true)
                {
                    //Tells the user how much fame they gained and how much health they lost
                    cout << "\n\nYou fought a big monster and gained 12 infamy and have lost " << h_lost << " health\n";
                    setNewFame(14, 1);
                    sleep(sleepTime);
                }
        }
}

///Allows the user to decide how they want to gain money, takes in graph_choice which can disable allegro
void Demon::searchTreasure(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));
    int sleepTime = 1;

    //Declaring variables
    int treasure_choice=0,x=0,result=0,y=0, h_lost = 0;
    bool win;

    //While statement makes sure the user chooses an option
    while(treasure_choice!=1&&treasure_choice!=2)
        {

            //Asks the user which option they want
            cout << "\nHow would you like to obtain treasure?\n\n    1:  Search a dungeon\n    2:  Rob someone\n\n: ";
            cin >> treasure_choice;

            //If statement tells the user to pick the right option if they did not already
            if(treasure_choice!=1&&treasure_choice!=2)
                {
                    cout << "\nPick 1 or 2\n";
                }
        }

    //If statement happens if treasure_choice equals 1
    if(treasure_choice==1)
        {

            //Makes a random number from 1 to 3
            x = 1 + (rand() % 3);

            //If that number is 1 or 2, it picks the first option, otherwise it picks the second
            if(x==1||x==2)
                {
                    win = Fight(graph_choice, 20, "Goblin", 1, h_lost);
                }
            else
                {
                    win = Fight(graph_choice, 40, "Goblin King", 2, h_lost);
                }

            setNewMoney(8,1);

            if(win==true)
                {
                    cout << "\n\nYou searched through a dungeon and found 8$, but you lost " << h_lost << " health\n";
                    sleep(sleepTime);
                }

        }
    else
        {

            //Runs the fight method, returns whether the player won or not
            win = Fight(graph_choice, 13, "Human", 1, h_lost);

            setNewFame(2, 1);

            //Makes a random number from 0 to 6

            x = 0 + (rand() % 6);
            setNewMoney(x, 1);

            if(win==true)
                {
                    cout << "\n\nYou robbed someone and found " << x << "$, you gained 2 infamy, but you lost " << h_lost << " health\n";
                    sleep(sleepTime);
                }

        }
}

///This method allows the player to exchange health for fame
void Demon::rest()
{
    //Makes things random
    srand((unsigned) time(0));

    //Makes a random number from 4 to 10
    int result = 4 + (rand() % 6);

    setNewSpirit(result, 1);

    setNewHealth(3, 2);

    //Tells the user what happened
    cout << "\nYou rested for the whole day and gained " << result << " spirit, but lost 3 health\n";
}

///Menu function takes in 4 stat variables for the toString method, graph_choice is used to disable allegro, int statue and poster are used to display achievements
int Demon::menu(string char_choice_menu, int aHealthM, int aFameM, int aMoneyM, int aSpiritM, string graph_choice, int statue, int poster)
{
    //Declaring variables
    int menu_choice = 0;
    int return_choice = 0;

    //Sets the max variables to the given max variables
    maxHealth = aHealthM;
    maxFame = aFameM;
    maxMoney = aMoneyM;
    maxSpirit = aSpiritM;

    //Makes sure the player picks the right option
    while(menu_choice!=1&&menu_choice!=2&&menu_choice!=3&&menu_choice!=4)
        {
            //This method displays the user stats, it takes in 4 stat variables
            cout << toString(char_choice_menu, aHealthM, aFameM, aMoneyM, aSpiritM) << endl;

            //Asks the player which option they want
            cout << "\nWhat would you like to do? (0,1,2,3,4)\n\n    0:  Save Game\n    1:  Look for food\n    2:  Fight monsters\n    3:  Search for treasure\n    4:  Rest\n    5:  Go to the store\n\n: ";
            cin >> menu_choice;

            //Picks the if choice equal to the input the player gave earlier
            if(menu_choice==0)
                {
                    //Clears the screen
                    system("CLS");

                    //Saves the game as the demon
                    saveGame("3");
                    cout << "Game Saved\n";

                    //Tells the user what day they are on
                    cout << endl << "         DAY " << day << endl << endl;
                }
            else if(menu_choice==5)
                {
                    //This method allows the user to decide how they want to get money, it takes in the graph_choice variable which allows the player to disable allegro
                    storeMenu();

                    //Clears the screen
                    system("CLS");

                    //Tells the user what day they are on
                    cout << endl << "         DAY " << day << endl << endl;

                    //Sets the local max variables to the classes max variables
                    aMoneyM = maxMoney;
                    aHealthM = maxHealth;
                }

            //Makes sure the player picks the right option
            if(menu_choice!=1&&menu_choice!=2&&menu_choice!=3&&menu_choice!=4)
                {
                    menu_choice = 0;
                }
        }

    //Picks the if choice equal to the input the player gave earlier
    if(menu_choice==1)
        {

            //This method allows the user to decide how they want to get health, it takes in the graph_choice variable which allows the player to disable allegro
            findFood(graph_choice);

        }
    else if(menu_choice==2)
        {

            //This method allows the user to decide how they want to get fame, it takes in the graph_choice variable which allows the player to disable allegro
            fightMonsters(graph_choice);

        }
    else if(menu_choice==3)
        {

            //This method allows the user to decide how they want to get money, it takes in the graph_choice variable which allows the player to disable allegro
            searchTreasure(graph_choice);
        }
    else if(menu_choice==4)
        {

            //This method allows the user to decide how they want to get money, it takes in the graph_choice variable which allows the player to disable allegro
            rest();
        }



    return return_choice;

}

int Demon::storeMenu()
{
    //Declaring variables
    string player_choice = " ";
    string player_choice2 = " ";

    while(player_choice2.compare("1337")!=0)
        {
            system("CLS");

            cout << "         _____  _   _  _____ ______         \n";
            cout << "        /  ___|| | | ||  _  || ___ \\        \n";
            cout << " ______ \\ `--. | |_| || | | || |_/ / ______ \n";
            cout << "|______| `--. \\|  _  || | | ||  __/ |______|\n";
            cout << "        /\\__/ /| | | |\\ \\_/ /| |            \n";
            cout << "        \\____/ \\_| |_/ \\___/ \\_|            \n\n";

            cout << "What would you like to buy? (You have " << money << "$)\n";
            cout << "    0:     Exit\n    1:  6$ Damage Increase (+1 dmg)\n    2:  7$ Health Increase (+5 hp)\n    3:  7$ Spirit Increase (+5 sp)\n    4:  7$ Max Money Increase (+5 max money)\n    5:     Purchase Skills\n\n";


            cin >> player_choice;

            if(player_choice.compare("3")==0&&money>=7)
                {
                    setNewMaxSpirit(5, 1);
                    setNewMoney(7, 2);
                }
            else if(player_choice.compare("2")==0&&money>=7)
                {
                    setNewMaxHealth(5, 1);
                    setNewMoney(7, 2);

                }
            else if(player_choice.compare("1")==0&&money>=4)
                {
                    setNewDamage(1, 1);
                    setNewMoney(4, 2);
                }
            else if(player_choice.compare("4")==0&&money>=7)
                {
                    setNewMaxMoney(5, 1);
                    setNewMoney(7, 2);
                }
            else if(player_choice.compare("5")==0)
                {
                    skillMenu();
                }
            else
                {
                    return 0;
                }
        }
}

int Demon::skillMenu()
{

    //Declaring variables
    string player_choice = " ";
    string player_choice2 = " ";

    while(player_choice2.compare("1337")!=0)
        {
            system("CLS");

            cout << " _____  _   __ _____  _      _      _____ \n";
            cout << "/  ___|| | / /|_   _|| |    | |    /  ___|\n";
            cout << "\\ `--. | |/ /   | |  | |    | |    \\ `--. \n";
            cout << " `--. \\|    \\   | |  | |    | |     `--. \\\n";
            cout << "/\\__/ /| |\\  \\ _| |_ | |____| |____/\\__/ /\n";
            cout << "\\____/ \\_| \\_/ \\___/ \\_____/\\_____/\\____/ \n\n";

            cout << "What would you like to buy? (You have " << money << "$)\n";
            cout << "    0:     Exit\n    1:  12$ Upgrade Instant Kill (";

            //If statement determines which value to tell the player
            if(unlockedSkills[0]==1)
                {
                    cout << "60";
                }
            else
                {
                    cout << "40";
                }

            cout << "% chance)\n    2:  30$ Dark Threat (200 hp, -All sp, -50% hp)\n\n";

            cin >> player_choice;

            if(player_choice.compare("2")==0&&money>=30)
                {
                    setUnlockedSkills(2);
                    setNewMoney(30, 2);
                }
            else if(player_choice.compare("1")==0&&money>=12)
                {
                    //If statement determines which value to change
                    if(unlockedSkills[0]==1)
                        {
                            setUnlockedSkills(3);
                        }
                    else
                        {
                            setUnlockedSkills(1);
                        }

                    setNewMoney(12, 2);
                }
            else
                {
                    return 0;
                }
        }

}


