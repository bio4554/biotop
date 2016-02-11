#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*

This header file defines the various custom data types used in CRPG.



The location system in this game is called a "Timeline" system. This means that the game progresses on a linear timeline.
Positions in the timeline are stored as numbers that range from 1 to a set limit (The timeline_limit variable)
Locations can either be a road or a town. Here is an example timeline:

    1 -------- 2 -------- 3 -------- 4 -------- 5  	<-- Location on timeline (stored as an int)
 Town 1     Road 1     Town 2     Road 3     Boss 1

*/

typedef struct data //Generic data type
{
    char *name;
    int value;
    int mod; //Modifier, generic as to be used with anything. (Damage, defense, health regen, etc.)
} data;

typedef struct creature //Generic creature type
{
    char *name;
    int hd; //Hit dice, HP gotten from multiplying hit dice by level
    int level;
    int location; //Location of creature 
    data inventory[100]; //Array of data types, for storing items, max of 100 items
    data weapon; //Currently equipped weapon
    data armor; //Currently equipped armor
    int hp;
} creature;

typedef struct location //Location type
{
    char *name;
    int type; //1 for town, 2 for road
    bool bshop;
    bool binn;
    //Shop
    data inventory[100]; //Shop inventory can hold a maximum of 100 items
    
    //Inn
    bool map; //Map or no
    int location; //Location on timeline
} location;










