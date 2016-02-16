#include <stdlib.h>
#include <ncurses.h>

#define TESTMAIN
#define MAX_ROOMS 5
#define MAX_X 50
#define MAX_Y 50
#define ROOM_X 20
#define ROOM_Y 10

#define rand(a, b) ((rand() % b) + a)

typedef struct coord coord;
struct coord {
	int x;
	int y;
};


void g_room(coord c1, coord c2)
{
	
}



void g_dungeon(int rooms, int maxx, int maxy)
{
	int i, ix, iy, i2, i3, i4;
	coord lroom[ROOM_X * ROOM_Y];
	coord troom[ROOM_X * ROOM_Y];
	do
	{
		ix = rand(0, MAX_X);
		iy = rand(0, MAX_Y);
		i3 = 0;
		i4 = 0;
		for(i2 = 0; i2 < (ROOM_X * ROOM_Y); i2++)
		{
			if(i3 > ROOM_X)
			{
				i3 = 0;
				i4++;
			} 
			troom[i2].x = ix+i3;
			troom[i2].y = iy+i4;
		}
	} while();
}




#ifdef TESTMAIN

int main()
{	
	srand(TIME(NULL));
	return 0;
}

#endif
