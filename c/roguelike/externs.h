
extern creature monsters[MAX_CREATURES]; //Monsters in the game

//generate.c
void m_fill(coord, coord, char);
void m_hall(coord, int, int, char);
int g_scan(coord, coord, char);
void g_dungeon(int);
