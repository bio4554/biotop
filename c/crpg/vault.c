#include "vault.h"

#define setloc(a, b) timeline[b] = a

location timeline[100];

void initvault();

location town1 = {"Town 1", 1, false, true};
location road1 = {"Road 1", 2, false, false};
location town2 = {"Town 2", 1, false, false};
location road2 = {"Road 2", 2, false, false};

//Weapons
data sword = {"Sword", 10, 10};

//Armor
data leatherarmor = {"Leather armor", 10, 5};

//Creatures
creature skeleton = {"Skeleton", 5, 2, 2};

void initvault()
{
//Weapons


//Locations
 town1.location = 1; setloc(town1, 1); 
 road1.location = 2; setloc(road1, 2);
 town2.location = 3; setloc(town2, 3);
 road2.location = 4; setloc(road2, 4);

//Monsters
 skeleton.weapon = sword; skeleton.armor = leatherarmor;
}
