#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define input(a) getline(std::cin, a)
#define frand() std::uniform_real_distribution<>(0.f, 1.f)(rnd)
#define rand(size) std::uniform_int_distribution<>(0, (size)(rnd)
#define newline std::endl

struct dataType {
    const char* name;
    float value;
    float modifier;
}

    weaponTypes[] = { {"sword", 100, 10}, {"knife", 50, 5}, {"fists", 0, 1}  }, 
    itemTypes[] = { {"food", 10, 5} };
    
struct screen {
    void clear() { for(int i = 0; i < 100; i++) printf("\n"); }
};

struct creature {
    std::string name;
    int life;
};
    
    

void drawRoom();
void printcstats(creature);
    

int main() {
    int life = 100; //Player life
    std::string name; //Player name
    std::string c; //Command
    int i = 0; //Iterator
    screen mainScreen;
    creature player = { &name, &life  };
    
    mainScreen.clear();
    std::cout << "Welcome to CRPG" << std::endl; //Intro
    std::cout << "Enter your name: ";
    input(name);			 //Get name
    
    while(life > 0) {
        mainScreen.clear();
        printcstats(player);
        std::cout << " > "; input(c);
    }
    
    return 0;
}

void clears() { for(int i = 0; i < 100; i++) printf("\n"); }

void drawRoom() {
    int ix, iy; ix = iy = 0; //X Y iterator
    int x, y; //X and Y
    x = 20; y = 10;
    char fill, wall;
    wall = '#'; fill = '.';
    
    for(iy = 0; iy < y; iy++) {
        std::cout << wall;
        for(ix = 0; ix < x; ix++) {
            if(iy == 0 || iy == y-1) fill = '#';
            std::cout << fill;
        }
        fill = '.';
        std::cout << wall << std::endl;
    }    
}

void printcstats(creature stater) {
    std::cout << newline << "     " << stater.name << newline << "Life: " << stater.life << newline;
}