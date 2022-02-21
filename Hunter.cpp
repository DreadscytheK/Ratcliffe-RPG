///Kenny R. - Fantasy RPG Game
#include <iostream>
#include <string>
#include "Hunter.h"

using namespace std;

Hunter::Hunter(int h,int f,int m)
{
    Character();

    //Sets stats equal to stat variables
    setHealth(h);
    setFame(f);
    setMoney(m);

}

Hunter::Hunter()
{
    Character();

    //Sets the classes default stats
    setHealth(30);
    setFame(15);
    setMoney(20);

}

///This method will allow the player to chose a method of gaining health
void Hunter::findFood(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));

    //Declaring variables
    int x=0,result=0,y=0,find_choice=0;

    //While statement checks to make sure the player chooses the right option
    while(find_choice!=1&&find_choice!=2)
        {

            //Asks the player for their choice
            cout << "\nHow would you like to obtain health\n\n    1:  Gamble with a healing magician\n    2:  Hunt for an animal\n\n: ";
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
                    setHealth(42);

                    //Tells the players the health is maxed
                    cout << "\n\nThe magician maxed out your health!\n";
                } //Else if checks if result is 2
            else if (result==2)
                {

                    //Gets health, then adds half health
                    setNewHealth(17, 1);

                    //Gets money, then subtracts 4
                    setNewMoney(4, 2);

                    //Tells the user what happened
                    cout << "\n\nThe magician healed half your health, but took 4$\n";

                }
            else
                {

                    //Tells the user they lost gambling lottery
                    cout << "\n\nThe magician did nothing and told you to leave\n";
                }


        }//This else statement happens when the player chooses option 2
    else
        {

            //Makes a random number between 1 and 4
            result = 1 + (rand() % 4);

            if(result==1)
                {
                    cout << "\n\nYou couldn't find any animals\n";
                }
            else if(result==2)
                {

                    setNewHealth(3, 1);

                    setNewMoney(1, 2);

                    cout << "\n\nYou found a bird and got 3 health, but you used 1 arrow which cost you 1$\n";

                }
            else if(result==3)
                {

                    setNewHealth(5, 1);

                    setNewMoney(3, 2);

                    cout << "\n\nYou found a deer and got 5 health, but you used 3 arrows which cost you 3$\n";

                }
            else
                {

                    setNewHealth(8, 1);

                    setNewMoney(4, 2);

                    cout << "\n\nYou found a bear and got 8 health, but you used 4 arrows which cost you 4$\n";
                }
        }

}

///This method gives the user the choice of how to gain fame
void Hunter::fightMonsters(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));

    //Declaring variables
    int x=0,result=0,y=0,z=0,fight_choice=0;

    //While statement makes sure the user picked the right option
    while(fight_choice!=1&&fight_choice!=2)
        {

            //Asks the user which thing they want to fight
            cout << "\nWho do you want to fight?\n\n    1:  Assassinate someone";

            //Checks if the players health is above 14, if it is then they can see this option
            if(getHealth()>14)
                {
                    cout << "\n    2:  Slay a legendary beast";
                }

            //Formatting
            cout << endl << endl << ": ";

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

            //Makes a random number that gets added to fame
            x = 3 + (rand() % 6);
            setNewFame(x, 1);

            //Makes a random number that gets subtracted to health
            y = 1 + (rand() % 2);
            setNewHealth(y, 2);

            setNewMoney(y/2, 2);

            //Tells the user how much fame they gained and how much health they lost
            cout << "\nYou assassinated someone and gained " << x << " fame, but lost " << y << " health and spent " << y/2 << "$ on arrows\n";
        }
    else
        {

            x = 7 + (rand() % 7);
            setNewFame(x, 1);

            y = 3 + (rand() % 7);
            setNewHealth(y, 2);

            z = getMoney();
            setNewMoney(y/2, 2);

            cout << "\nYou fought a legendary beast and gained " << x << " fame, but lost " << y << " health and spent " << x/2 << "$ on arrows\n";
        }

}

///Allows the user to decide how they want to gain money
void Hunter::searchTreasure(string graph_choice)
{
    //Declaring variables
    int treasure_choice=0,x=0,z=0,result=0,y=0;

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

    //Makes things random
    srand((unsigned) time(0));

    //If statement happens if treasure_choice equals 1
    if(treasure_choice==1)
        {

            y = 2 + (rand() % 5);
            setNewHealth(y, 2);

            x = 3 + (rand() % 7);
            setNewMoney(x, 1);
            setNewMoney(y/3, 2);

            cout << "\n\nYou searched through a dungeon and found " << x << "$, but you lost " << y << " health and spent " << y/2 << "$ on arrows\n";
        }//Else statement happens if the player picks the other option
    else
        {
            x = 0 + (rand() % 9);
            setNewMoney(x, 1);

            y = 2 + (rand() % 4);
            setNewFame(y, 2);

            cout << "\n\nYou robbed someone and found " << x << "$, but you lost " << y << " fame\n";
        }

}

///Menu function takes in 4 stat variables for the toString method, graph_choice is used to disable allegro, int statue and poster are used to display achievements
int Hunter::menu(string char_choice_menu, int aHealthM, int aFameM, int aMoneyM, int aSpiritM, string graph_check,  int statue, int poster)
{
    //Declaring variables
    int menu_choice = 0;
    int return_choice = 0;

    //Sets the max variables to the given max variables
    maxHealth = aHealthM;
    maxFame = aFameM;
    maxMoney = aMoneyM;
    maxSpirit = aSpiritM;

    //This method displays the user stats, it takes in 4 stat variables
    cout << toString(char_choice_menu, aHealthM, aFameM, aMoneyM, aSpiritM) << endl;

    //Makes sure the player picks the right option
    while(menu_choice!=1&&menu_choice!=2&&menu_choice!=3)
        {

            //Asks the player which option they want
            cout << "\nWhat would you like to do? (0,1,2,3)\n\n" << "    0:  Save Game\n    1:  Hunt for food\n" << "    2:  Slay something\n" << "    3:  Search for treasure\n\n: ";
            cin >> menu_choice;

            //Picks the if choice equal to the input the player gave earlier
            if(menu_choice==0)
                {
                    saveGame("2");
                    cout << "\nGame Save\n";
                }

            //Makes sure the player picks the right option
            if(menu_choice!=1&&menu_choice!=2&&menu_choice!=3)
                {
                    menu_choice = 0;
                }
        }

    //Picks the if choice equal to the input the player gave earlier
    if(menu_choice==1)
        {

            //This method allows the user to decide how they want to get health, it takes in the graph_choice variable which allows the player to disable allegro
            findFood(graph_check);

        }
    else if(menu_choice==2)
        {

            //This method allows the user to decide how they want to get fame, it takes in the graph_choice variable which allows the player to disable allegro
            fightMonsters(graph_check);

        }
    else
        {

            //This method allows the user to decide how they want to get money, it takes in the graph_choice variable which allows the player to disable allegro
            searchTreasure(graph_check);

        }


    return return_choice;

}

