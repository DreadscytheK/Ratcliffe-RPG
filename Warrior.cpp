///Kenny R. - Fantasy RPG Game
#include <iostream>
#include <ctime>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(int h,int f,int m)
{
    Character();

    //Sets stats equal to variables
    setHealth(h);
    setFame(f);
    setMoney(m);
}

Warrior::Warrior()
{
    Character();

    //Sets the classes default stats
    setHealth(35);
    setFame(15);
    setMoney(15);
}

///This method will allow the player to chose a method of gaining health
void Warrior::findFood(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));

    //Declaring variables
    int x=0,result=0,y=0,find_choice=0;

    //While statement checks to make sure the player chooses the right option
    while(find_choice!=1&&find_choice!=2)
        {

            //Asks the player for their choice
            cout << "\nHow would you like to obtain health\n\n    1:  Gamble with a healing magician\n    2:  Buy food\n\n: ";
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
                    setNewHealth(22, 1);

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

            //Gets health then adds 7
            setNewHealth(7, 1);

            //Gets money then subtracts 3
            setNewMoney(3, 2);

            //Tells the user what happened
            cout << "\n\nYou bought some bread for 3$ and gained 7 health\n";
        }
}

///This method gives the user the choice of how to gain fame
void Warrior::fightMonsters(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));

    //Declaring variables
    int x=0,result=0,y=0,fight_choice=0;

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

            //Formating
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

            //Makes a random number that gets added to fame
            x = 3 + (rand() % 5);
            setNewFame(x, 1);

            //Makes a random number that gets subtracted to health
            y = 1 + (rand() % 5);
            setNewHealth(y, 2);

            //Tells the user how much fame they gained and how much health they lost
            cout << "\n\nYou fought a small monster and gained " << x << " fame, but lost " << y << " health\n";

        }//Else statement happens if the player picks the other option
    else
        {

            //Random number is added to fame
            x = 7 + (rand() % 7);
            setNewFame(x, 1);

            //Random number is subtracted to health
            y = 2 + (rand() % 7);
            setNewHealth(y, 2);

            //Tells the user how much fame they gained and how much health they lost
            cout << "\n\nYou fought a big monster and gained " << x << " fame, but lost " << y << " health\n";

        }
}

///Allows the user to decide how they want to gain money
void Warrior::searchTreasure(string graph_choice)
{
    //Makes things random
    srand((unsigned) time(0));

    //Declaring variables
    int treasure_choice=0,x=0,result=0,y=0;

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

            //Gets a random number between 3 and 9
            x = 3 + (rand() % 6);
            setNewMoney(x, 1);

            //Gets a random number between 1 and 6
            y = 1 + (rand() % 6);
            setNewHealth(y, 2);

            cout << "\n\nYou searched through a dungeon and found " << x << "$, but you lost " << y << " health\n";

        } //Else statement happens if the player picks the other option
    else
        {
            //Makes a random number between 0 and 6
            x = 0 + (rand() % 6);
            setNewMoney(x, 1);

            //Makes a random number between 2 and 6
            y = 2 + (rand() % 4);
            setNewFame(y, 2);

            cout << "\n\nYou robbed someone and found " << x << "$, but you lost " << y << " fame\n";
        }

}

///Menu function takes in 4 stat variables for the toString method, graph_choice is used to disable allegro, int statue and poster are used to display achievements
int Warrior::menu(string char_choice_menu, int aHealthM, int aFameM, int aMoneyM, int aSpiritM, string graph_choice, int statue, int poster)
{
    //Declaring variables
    int menu_choice = 0;
    int return_choice = 0;

    //This method displays the user stats, it takes in 4 stat variables
    cout << toString(char_choice_menu, aHealthM, aFameM, aMoneyM, aSpiritM) << endl;

    //Makes sure the player picks the right option
    while(menu_choice!=1&&menu_choice!=2&&menu_choice!=3)
        {

            //Asks the player which option they want
            cout << "\nWhat would you like to do? (0,1,2,3)\n\n" << "    0:  Save Game\n    1:  Look for food\n" << "    2:  Fight monsters\n" << "    3:  Search for treasure\n\n: ";
            cin >> menu_choice;

            //Picks the if choice equal to the input the player gave earlier
            if(menu_choice==0)
                {
                    saveGame("1");
                    cout << "\nGame Save\n";
                }

            //Makes sure the player picks the right option
            if(menu_choice!=1&&menu_choice!=2&&menu_choice!=3)
                {
                    menu_choice = 0;
                }
        }


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
    else
        {

            //This method allows the user to decide how they want to get money, it takes in the graph_choice variable which allows the player to disable allegro
            searchTreasure(graph_choice);
        }



    return return_choice;

}
