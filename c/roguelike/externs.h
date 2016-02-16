#include <stdlib.h>
#include <ncurses.h>
#include <time.h>


extern creature monsters[MAX_CREATURES]; //Monsters in the game

//generate.c
void m_fill(coord, coord, char);
void m_hall(coord, int, int, char);
int g_scan(coord, coord, char);
void g_dungeon(int);

//creature.c
char getcfd(coord, int);
int c_move(creature *, int);
void draw_creatures(creature cre[], int);
void clear_creatures(creature cre[], int);
void ai_step(creature *cre[], int);

//combat.c
int dice(int, int);
void attack(creature *, creature *);
