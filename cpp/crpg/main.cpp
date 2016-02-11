#include <iostream>
#include <stdio.h>
#include <stdlib.h>


struct genericData {
    const char* name;
    int value;
    int mod;
}

weapons[] = { {"Sword", 100, 10}, {"Bow", 150, 15}  },
armor[] = { {"Leather Armor",50, 5}  };

class Town {
public:
    std::string name;
    bool hasShop;
    bool hasRest;
};

class Road {
public:
    std::string name;
    bool hasMonster;
};

class Creature {
public:
    std::string name;
    int health;
    genericData inventory[];
    genericData weapon;
    genericData armor;
};


int main() {

    //Creatures
    Creature player = {"Player", 100}; player.inventory[0] = weapons[0]; //sword
    Creature skeleton = {"Skeleton", 10}; skeleton.inventory[0] = weapons[1]; 
    //Town
    Town test = { "Test", false, true  };
    
    return 0;
}


void displayCreature(Creature creature) {
    std::cout << std::endl
}

