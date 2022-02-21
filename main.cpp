///Kenny R. - Fantasy RPG Game
//This program allows the user to play a fantasy rpg where try to keep their stats above 0
/*
----Errors and Problems----

    Money in the negative for some reason

    Go through and fix formatting of things

    Removes useless variables

----Errors fixed----

Error with loading spirit value
Instant win in magician
Values going outside min and max
Remove extra skill functions and variables

*/

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Warrior.h"
#include "Hunter.h"
#include "Demon.h"

using namespace std;

int main()
{
    //Declaring variables
    string char_choice = " ";
    string graph_choice = " ";
    string char_choice_menu =" ";
    string start_choice = "3";
    int day = 1, x=0,y=0,w=0;
    int first_check = 0;
    int second_check = 0;
    int sleepTime = 0;

    //These variables are used to determine how many of each stat to subtract or add
    int wHealthR = 3, wFameR = 2, wMoneyR = 3;
    int hHealthR = 2, hFameR = 3, hMoneyR = 1;
    int dHealthR = 3, dFameR = 1, dMoneyR = 1, dSpiritA = 3;

    //These variables are used to determine the maximum of each stat
    int wHealthM = 40, wFameM = 30, wMoneyM = 30;
    int hHealthM = 30, hFameM = 30, hMoneyM = 40;
    int dHealthM = 45, dFameM = 30, dMoneyM = 20, dSpiritM = 40;
    int aHealthM = 0, aFameM = 0, aMoneyM = 0, aSpiritM = 0;

    //Declaring child class objects, variables in brackets are the starting health, fame, money and spirit for demon
    Warrior warrior1(35,15,15);
    Hunter hunter1(30,15,20);
    Demon demon1(25,25,15,40);

    //Creates a general character, this object is used for methods like load save
    Character GenChar;

    //Setting the magicians health
    demon1.setMagicianHealth(100);

    //Opening statement
    cout << " _   __                            _       ______ ______ ______  _____ \n";
    sleep(sleepTime);
    cout << "| | / /                           ( )      |  ___|| ___ \\| ___ \\|  __ \\\n";
    sleep(sleepTime);
    cout << "| |/ /   ___  _ __   _ __   _   _ |/  ___  | |_   | |_/ /| |_/ /| |  \\/\n";
    sleep(sleepTime);
    cout << "|    \\  / _ \\| '_ \\ | '_ \\ | | | |   / __| |  _|  |    / |  __/ | | __ \n";
    sleep(sleepTime);
    cout << "| |\\  \\|  __/| | | || | | || |_| |   \\__ \\ | |    | |\\ \\ | |    | |_\\ \\\n";
    sleep(sleepTime);
    cout << "\\_| \\_/ \\___||_| |_||_| |_| \\__, |   |___/ \\_|    \\_| \\_|\\_|     \\____/\n";
    sleep(sleepTime);
    cout << "                             __/ |                                     \n";
    sleep(sleepTime);
    cout << "                            |___/                                      \n\n";

    sleep(1);

    cout << "Welcome to the Fantasy Character Game!\nYou can play as a Warrior, a Hunter or the Demon. \nYou will need to manage your health, fame, and money in order to survive!\nIf any of those go below 0 you will lose\n\n" << endl;

    while(start_choice.compare("3")==0)
        {

            cout << "\nWhat would you like to do?\n    1:  New Game\n    2:  Load Game\n    3:  Info\n    4:  Settings\n    5:  Exit\n\n: ";
            cin >> start_choice;

            if(start_choice.compare("1")==0)
                {

                }
            else if(start_choice.compare("2")==0)
                {
                    //Runs the load game method
                    GenChar.loadGame();

                    //Sets char_choice equal to the character from the text file
                    char_choice = GenChar.getChosenCharacter();

                    //Sets the day variable
                    day = GenChar.getDay();

                    //This section sets the players current stats from the loaded game
                    if(char_choice.compare("2")==0)
                        {
                            hunter1.setHealth(GenChar.getHealth());
                            hunter1.setFame(GenChar.getFame());
                            hunter1.setMoney(GenChar.getMoney());
                        }
                    else if(char_choice.compare("1")==0)
                        {
                            warrior1.setHealth(GenChar.getHealth());
                            warrior1.setFame(GenChar.getFame());
                            warrior1.setMoney(GenChar.getMoney());
                        }
                    else
                        {
                            demon1.setHealth(GenChar.getHealth());
                            demon1.setFame(GenChar.getFame());
                            demon1.setMoney(GenChar.getMoney());
                            demon1.setSpirit(GenChar.getSpirit());
                            demon1.setDamage(GenChar.getDamage());
                        }

                }
            else if(start_choice.compare("3")==0)
                {
                    system("CLS");

                    //Explains to the player what the characters do
                    cout << "\nWarrior: They are a noble knight who embodies power!\nStats: Health 35/40  Fame 15/30  Money 15/30\nDifficulty: Easy\n\n";
                    cout << "Hunter: They are a lone wanderer who hunts for food and seeks out victims in the streets!\nQuirk: The Hunter slays foes with his bow so your arrows will cost money!\nStats: Health 30/30  Fame 15/30  Money 20/40\nDifficulty: Hard\n\n";
                    cout << "Demon: The Demon is a being of unknown origin, some say he comes from the depths of the underworld and some say he is a fallen angel.\nThe only thing that matters in the Demon's eyes are slaying whichever foe lies before him.\n";
                    cout << "Quirk: Unlike the other playable characters, the Demon gives the player control when attacking an enemy.\nThe player is given a set of attacks which drain a new stat called spirit.\n";
                    cout << "Unlike the other stats, spirit can go to zero and increases each day, some attacks will require a certain amount of spirit\nso you may want to be careful with your spending of the stat!\n";
                    cout << "Stats: Health 30/45  Infamy: 30/30  Money 15/20  Spirit 40/40\nDifficulty: Very Hard\n\n";

                    //Pauses the terminal to allow the player to read the text shown
                    system("Pause");
                    system("CLS");
                }
            else if(start_choice.compare("4")==0)
                {
                    //Asks the player if they want to disable the Allegro graphics in the game
                    cout << "Would you like disable graphics (y/n) ";

                    //While statement makes sure the player picked one of the right choices
                    while(graph_choice.compare("y")!=0&&graph_choice.compare("n")!=0)
                        {
                            cin >> graph_choice;

                            //If statement tells the player what to pick if they do not pick one of the correct options
                            if(graph_choice.compare("y")!=0&&graph_choice.compare("n")!=0)
                                {
                                    cout << "Pick y or n ";

                                    //Resets the char_choice variable
                                    char_choice = "t";
                                }

                        }

                    cout << "What would you like the sleep time to be? (enter integer): ";
                }
            else
                {
                    //Exits the game
                    return 0;
                }

        }


    //While statement checks to see if the player picked the right option
    while(char_choice.compare("1")!=0&&char_choice.compare("2")!=0&&char_choice.compare("3")!=0)
        {

            //Asks the player who they want to play as
            cout << endl << "Who would you like to play as?\n\n    1:  Warrior\n    2:  Hunter\n    3:  Demon\n\n: ";
            cin >> char_choice;

            //If statement checks to see if the player picked the right option
            if(char_choice.compare("1")!=0&&char_choice.compare("2")!=0&&char_choice.compare("3")!=0)
                {
                    cout << endl << "Please enter 1, 2 and 3";
                }

        }

    //Clears screen
    system("CLS");

    //This section sets the char_choice_menu name and all maximum stats for each character
    if(char_choice.compare("2")==0)
        {
            char_choice_menu = "Hunter";
            aHealthM = hHealthM;
            aFameM = hFameM;
            aMoneyM = hMoneyM;
            hunter1.setMaxHealth(hHealthM);
            hunter1.setMaxFame(hFameM);
            hunter1.setMaxMoney(hMoneyM);
        }
    else if(char_choice.compare("1")==0)
        {
            char_choice_menu = "Warrior";
            aHealthM = wHealthM;
            aFameM = wFameM;
            aMoneyM = wMoneyM;
            warrior1.setMaxHealth(wHealthM);
            warrior1.setMaxFame(wFameM);
            warrior1.setMaxMoney(wMoneyM);
        }
    else
        {
            char_choice_menu = "Demon";
            aHealthM = dHealthM;
            aFameM = dFameM;
            aMoneyM = dMoneyM;
            aSpiritM = dSpiritM;
            demon1.setMaxHealth(dHealthM);
            demon1.setMaxFame(dFameM);
            demon1.setMaxMoney(dMoneyM);
            demon1.setMaxSpirit(dSpiritM);
        }



    //Tells the player who they chose
    cout << "You have selected " << char_choice_menu << "!" << endl;

    //While loop checks if 1 equals 1, basically it won't ever break out by anything other than the break function
    while(1==1)
        {

            //Tells the user what day they are on
            cout << endl << "         DAY " << day << endl;

            //If statement checks if the player chose warrior
            if(char_choice.compare("1")==0)
                {
                    warrior1.setDay(day);

                    //If statement checks if on day 10 the player has 20 fame or more and first_check equals 0, then the variable first_check is set to 1 and it tells the user this happened
                    if(day>=10&&warrior1.getFame()>=20&&first_check==0)
                        {
                            cout << "\nThe town's people have created a statue in your honour, you're famous!\n";

                            first_check = 1;
                        }

                    //If statement checks if on day 15 the player has 20 money or more and second_check equals 0, then the variable second_check is set to 1 and it tells the user what happened
                    if(day>=15&&warrior1.getMoney()>=20&&second_check==0)
                        {
                            cout << "\nIt's day " << day << " and you feel full of powerful remembering that you have " << hunter1.getMoney(); "$\n";

                            second_check = 1;
                        }

                    //Activates a method that can result in a random event where the player can either gain or lose stats
                    warrior1.randomEvent();

                    //Displays toString and options. It is given graph_choice to allow for disabled graphics, first_check to allow for the statue to be shown
                    //and second_check to allow for the coin to be shown
                    warrior1.menu(char_choice_menu, aHealthM, aFameM, aMoneyM, aSpiritM, graph_choice, first_check, second_check);

                    //If there was a change max health in the class it will also be change here
                    aHealthM = warrior1.getMaxHealth();
                    aFameM = warrior1.getMaxFame();
                    aMoneyM = warrior1.getMaxMoney();

                    //If statement checks if the day is 1, this is to make sure stats are not taken away on the first day
                    if(day!=1)
                        {

                            //These subtract values from wR variables
                            x = warrior1.getFame();
                            x-=wFameR;
                            warrior1.setFame(x);

                            x = warrior1.getHealth();
                            x-=wHealthR;
                            warrior1.setHealth(x);

                            x = warrior1.getMoney();
                            x-=wMoneyR;
                            warrior1.setMoney(x);
                        }

                    //Makes sure the stats do not exceed there limit
                    if(warrior1.getHealth()>aHealthM)
                        {
                            warrior1.setHealth(aHealthM);
                        }
                    if(warrior1.getFame()>aFameM)
                        {
                            warrior1.setFame(aFameM);
                        }
                    if(warrior1.getMoney()>aMoneyM)
                        {
                            warrior1.setMoney(aMoneyM);
                        }

                }
            else if(char_choice.compare("2")==0)
                {
                    hunter1.setDay(day);

                    //If statement checks if on day 10 the player has 20 fame or more and first_check equals 0, then the variable first_check is set to 1 and it tells the user this happened
                    if(day>=10&&hunter1.getFame()>=20&&first_check==0)
                        {
                            cout << "\nThe town's people have put up bounty posters all around town, you're infamous!\n";

                            first_check = 1;
                        }

                    //If statement checks if on day 15 the player has 20 money or more and second_check equals 0, then the variable second_check is set to 1 and it tells the user what happened
                    if(day>=15&&hunter1.getMoney()>=20&&second_check==0)
                        {
                            cout << "\nIt's day " << day << " and you feel full of pride remembering that you have " << hunter1.getMoney(); "$\n";

                            second_check = 1;
                        }

                    //Activates a method that can result in a random event where the player can either gain or lose stats
                    hunter1.randomEvent();

                    //Displays toString and options It is given graph_choice to allow for disabled graphics, first_check to allow for the bounty poster to be shown
                    //and second_check to allow for the coin to be shown
                    hunter1.menu(char_choice_menu, aHealthM, aFameM, aMoneyM, aSpiritM, graph_choice, first_check, second_check);

                    //If there was a change max health in the class it will also be change here
                    aHealthM = hunter1.getMaxHealth();
                    aFameM = hunter1.getMaxFame();
                    aMoneyM = hunter1.getMaxMoney();

                    //If statement checks if the day is 1, this is to make sure food is not taken away on the first day
                    if(day!=1)
                        {

                            //These subtract values from hR variables
                            x = hunter1.getFame();
                            x-=hFameR;
                            hunter1.setFame(x);

                            x = hunter1.getHealth();
                            x-=hHealthR;
                            hunter1.setHealth(x);

                            x = hunter1.getMoney();
                            x-=hMoneyR;
                            hunter1.setMoney(x);
                        }

                    //Makes sure the stats do not exceed there limit
                    if(hunter1.getHealth()>aHealthM)
                        {
                            hunter1.setHealth(aHealthM);
                        }
                    if(hunter1.getFame()>aFameM)
                        {
                            hunter1.setFame(aFameM);
                        }
                    if(hunter1.getMoney()>aMoneyM)
                        {
                            hunter1.setMoney(aMoneyM);
                        }

                }
            else
                {
                    demon1.setDay(day);

                    //If statement checks if on day 10 the player has 20 fame or more and first_check equals 0, then the variable first_check is set to 1 and it tells the user this happened
                    if(day>=10&&demon1.getFame()>=20&&first_check==0)
                        {
                            cout << "\nIt's day " << day << " and you have " << demon1.getFame() << " infamy.\nAll of the town's people are either cowering in their homes or have fled the town!\n";
                            first_check = 1;
                        }

                    //If statement checks if on day 15 the player has 30 health or more and second_check equals 0, then the variable second_check is set to 1 and it tells the user what happened
                    if(day>=15&&demon1.getHealth()>=30&&second_check==0)
                        {
                            cout << "\nIt's day " << day << " and you feel full of pride remembering that you have " << demon1.getHealth(); " health left.\n";
                            second_check = 1;
                        }

                    //Activates a method that can result in a random event where the player can either gain or lose stats
                    demon1.randomEvent();

                    //Displays toString and options
                    demon1.menu(char_choice_menu, aHealthM, aFameM, aMoneyM, aSpiritM, graph_choice, first_check, second_check);

                    //If there was a change max health in the class it will also be change here
                    aHealthM = demon1.getMaxHealth();
                    aFameM = demon1.getMaxFame();
                    aMoneyM = demon1.getMaxMoney();
                    aSpiritM = demon1.getMaxSpirit();

                    //If statement checks if the day is 1, this is to make sure food is not taken away on the first day
                    if(day!=1)
                        {

                            //These subtract values from dR variables
                            x = demon1.getFame();
                            x-=dFameR;
                            demon1.setFame(x);

                            x = demon1.getHealth();
                            x-=dHealthR;
                            demon1.setHealth(x);

                            x = demon1.getMoney();
                            x-=dMoneyR;
                            demon1.setMoney(x);

                            //This one adds from dSpiritA variable
                            x = demon1.getSpirit();
                            x+=dSpiritA;
                            demon1.setSpirit(x);
                        }

                    //Makes sure the stats do not exceed there limit
                    if(demon1.getHealth()>aHealthM)
                        {
                            demon1.setHealth(aHealthM);
                        }
                    if(demon1.getFame()>aFameM)
                        {
                            demon1.setFame(aFameM);
                        }
                    if(demon1.getMoney()>aMoneyM)
                        {
                            demon1.setMoney(aMoneyM);
                        }
                    if(demon1.getSpirit()>aSpiritM)
                        {
                            demon1.setSpirit(aSpiritM);
                        }
                    if(demon1.getSpirit()<0)
                        {
                            demon1.setSpirit(0);
                        }

                }

            //Increases day by one
            day++;

            //This section checks if any of the values go below 0, it will break out of the  while loop if that happens
            x = warrior1.getFame();
            y = warrior1.getHealth();
            w = warrior1.getMoney();

            if(y<1||x<1||w<1)
                {
                    break;
                }

            x = hunter1.getFame();
            y = hunter1.getHealth();
            w = hunter1.getMoney();

            if(y<1||x<1||w<1)
                {
                    break;
                }

            x = demon1.getFame();
            y = demon1.getHealth();
            w = demon1.getMoney();

            if(y<1||x<1||w<1)
                {
                    break;
                }

            //This checks if the methd getImmor equals true, this ends the game, I consider this a win
            if(demon1.getImmor()==true)
                {
                    break;
                }

            //This adds health to the magician each day
            demon1.setMagicianNewHealth(2,1);

            //Clears the screen
            system("CLS");

        }

    //If statement checks if the method getImmor equals true, if it does not it runs the lose dialogue
    if(demon1.getImmor()==false)
        {

            //Displays death text to the player
            cout << "You fought a noble battle " << char_choice_menu << " and managed to survive for " << day << " days, but alas, every good thing has to end\n";
            cout << "Unfortunately you lost due to lack of ";

            //If statement displays different text based on how you died
            if(x<1)
                {
                    cout << "fame, people forgot about you";
                }
            else if(y<1)
                {
                    cout << "health, you died";
                }
            else
                {
                    cout << "money, you couldn't afford food and starved";
                }

            //Says thanks to the player
            cout << ". Thanks for playing!\n\n";
        }

    return 0;
}
