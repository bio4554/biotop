#include "vault.h"
#define maxlocs 100
/*

This CPP file defines the core of the game engine, the functions. They are broken up into uses.

*/



//Movement functions

void cm_move(creature *cre, int moveto) //Move creature to certain location
{
    (*cre).location = moveto;
}

void cm_forward(creature *cre) //Move creature forward one location
{
    (*cre).location = (*cre).location + 1;
}

void cm_back(creature *cre) //Move creature back one location
{
    (*cre).location = (*cre).location - 1;
}

void cm_nexttown(creature *cre, location locs[]) //Move creature to the next town, if there is one
{
    int i = (*cre).location;
    do{
    i++;
    } 
    while(locs[i].type != 1 && i != maxlocs);
    if(locs[i].type == 1)
        (*cre).location = i;   
}

void cm_prevtown(creature *cre, location locs[]) //Move creature to the previous town, if there is one
{
    int i = (*cre).location;
    do {i--;} 
    while(locs[i].type != 1 && i != 1);
    if(locs[i].type == 1)
        (*cre).location = i;   
}

void cm_nextroad(creature *cre, location locs[]) //Move creature to the next road, if there is one
{
    int i = (*cre).location; 
    do {i++;}
    while(locs[i].type != 2 && i != maxlocs);
    if(locs[i].type == 2)
        (*cre).location = i;   
}

void cm_prevroad(creature *cre, location locs[]) //Move creature to the previous road, if there is one
{
    int i = (*cre).location; 
    do {i--;}
    while(locs[i].type != 2 && i != 1);
    if(locs[i].type == 2)
        (*cre).location = i;   
}


//Display functions

#define clearScreen for(i = 0; i < 100; i++) printf("\n")
#define skip(a) for(i = 0; i < a; i++) printf("\n")

void ds_town(location ltown)
{
    int i;
    clearScreen;
    printf("          %s", ltown.name);
    skip(5);
    printf("   What would you like to do in the town of %s?\n\n\n", ltown.name);
    if(ltown.bshop == true)
    {
        printf("   1: Enter shop\n");
        if(ltown.binn == true)
            printf("   2: Enter inn\n   3: Venture back the way you came\n   4: Venture forward");
        else
            printf("   2: Venture back the way you came\n   3: Venture forward");
    } 
    
    else if(ltown.binn == true)
    
    {
        printf("   1: Enter inn\n   2: Venture back the way you came\n   3: Venture forward");    
    }
    
    else
    
    {
        printf("   1: Venture back the way you came\n   2: Venture forward");
    }
    skip(3);
}

void ds_shop(location ltown)
{
    int i;
    clearScreen;
    printf("          Welcome to the %s shop", ltown.name);
    skip(5);
    printf("   How may I help you?\n\n\n");
    printf("   1: View shop inventory\n   2: Sell items\n   3: Leave");
    skip(3);
}

void ds_inn(location ltown)
{
    int i;
    clearScreen;
    printf("          Welcome to the %s inn", ltown.name);
    skip(5);
    printf("   How may I help you?\n\n\n");
    printf("   1: Rent a room\n   2: View map\n   3: Leave");
    skip(3);
}

void ds_battle(location lroad, creature monster, creature player)
{
    int i;
    clearScreen;
    printf("          %s", monster.name);
    skip(5);
    printf("   HP of monster: %d\n", (monster.hd * monster.level));
    printf("   Level of monster: %d\n", monster.level);
    printf("   Monster's weapon: %s", monster.weapon.name);
    skip(5);
    printf("   What do you want to do on your turn?\n\n\n");
    printf("   1: Attack\n   2: Swap items\n   3: Attempt to run");
    skip(3); 
}

#define printloc printf("\n\nCurrent player location = %d\n\n Type of location = %d\n\n", testdude.location, timeline[testdude.location].type)



int main() {
    initvault();
    creature testdude;
    ds_battle(timeline[2], skeleton, testdude);
    
    return 0;
}
