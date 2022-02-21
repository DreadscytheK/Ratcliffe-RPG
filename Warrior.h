///Kenny R. - Fantasy RPG Game - Ms. Cullum
#include <iostream>
#include "Character.h"

using namespace std;

//Creates child subclass of character
class Warrior: public Character
{
    public:
        Warrior();
        Warrior(int h,int f,int m);

        //This method shows toString and choice options
        int menu(string char_choice_menu, int aHealthM, int aFameM, int aMoneyM, int aSpiritM, string graph_choice, int statue, int poster);

        //Choice methods
        void findFood(string graph_choice);
        void fightMonsters(string graph_choice);
        void searchTreasure(string graph_choice);
};
