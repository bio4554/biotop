#include <stdlib.h>
#include <ncurses.h>
#include <time.h>


#define rand(a,b) ((rand() % b) + a)

#define TESTMAIN

#define MAP_X 100
#define MAP_Y 50
#define ROOM_X 10
#define ROOM_Y 5
#define MAX_THINGS 20
#define WALL '#'
#define FLOOR ' '
#define FALSE 0
#define TRUE 0

typedef int bool;

typedef struct coord coord;
struct coord {
	int x;
	int y;
};


typedef struct data data;
struct data {
	const char* name;
	float value;
	float damage;
};

typedef struct weapon weapon;
struct weapon {
	const char* name;
	float value;
	int dice;
	int sides;
};

typedef struct creature creature;
struct creature {
	coord loc;
	char icon;
	bool lit;
};

void initscreen()
{
	initscr();
	raw();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
}

creature monsters[100];

void init_monsters()
{
	//Template creature
	creature blank;
	blank.loc.x = 500; blank.loc.y = 500;
	blank.icon = '#';
	blank.lit = FALSE;
}


void m_fill(coord c1, coord c2, char fill)
{
	for(int iy = c1.y; iy < c2.y; iy++)
		for(int ix = c1.x; ix < c2.x; ix++)
			mvaddch(iy, ix, fill);
}

void m_hall(coord c1, int length, int dir, char fill)
{
	if(dir == 1) //Up
	{
		for(int iy = c1.y; iy > iy - length; iy--)
		{
			mvaddch(iy, c1.x, fill);
		}
	} else if(dir == 2) { //Down
		for(int iy = c1.y; iy < (iy + length); iy++)
		{
			mvaddch(iy, c1.x, fill);
		}
	} else if(dir == 3) { //Left
		for(int ix = c1.x; ix > ix - length; ix--)
		{
			mvaddch(c1.y, ix, fill);
		}
	} else if(dir == 4) { //Right
		for(int ix = c1.x; ix < ix + length; ix++)
		{
			mvaddch(c1.y, ix, fill);
		}
	} 
}





char getcfd(coord cord, int dir) //1 = up, 2 = down, 3 = left, 4 = right
{
	if(dir == 1)
		return mvinch(cord.y - 1, cord.x);
	else if(dir == 2)
		return mvinch(cord.y + 1, cord.x);
	else if(dir == 3)
		return mvinch(cord.y, cord.x - 1);
	else if(dir == 4)
		return mvinch(cord.y, cord.x + 1);
	return 0;
}


int g_scan(coord c1, coord c2, char search)
{
	int ix, iy;
	for(iy = c1.y; iy < c2.y; iy++)
	{
		for(ix = c1.x; ix < c2.x; ix++)
		{
			if(mvinch(iy, ix) == search)
				return 1;
		}
	}
	return 0;
}

void g_dungeon(int numof) //Generate dungeon
{
	int test, ix, iy;
	int numofI = 0;
	coord test1, test2;
	coord mc1 = {0, 0};
	coord mc2 = {MAP_X+100, MAP_Y+100}; //HAX
	coord mcCen1 = {(MAP_X/2 - (ROOM_X/2)), (MAP_Y/2 - (ROOM_Y/2))};
	coord mcCen2 = {(MAP_X/2 + (ROOM_X/2)), (MAP_Y/2 + (ROOM_X/2))};
	m_fill(mc1, mc2, WALL);
	m_fill(mcCen1, mcCen2, FLOOR);
	while(numofI < numof) {
	//Get a wall (includes hax, could use rework)
	do
	{
		ix = rand(0, MAP_X);
		iy = rand(0, MAP_Y);
		test1.x = ix; test1.y = iy;
		if(getcfd(test1, 1) == FLOOR&&getcfd(test1, 2)==WALL&&getcfd(test1, 3)==WALL&&getcfd(test1, 4)==WALL)
			test = '1';
		else if(getcfd(test1, 2)==FLOOR&&getcfd(test1, 1)==WALL&&getcfd(test1, 3)==WALL&&getcfd(test1, 4)==WALL)
			test = '2';
		else if(getcfd(test1, 3)==FLOOR&&getcfd(test1, 2)==WALL&&getcfd(test1, 1)==WALL&&getcfd(test1, 4)==WALL)
			test = '3';
		else if(getcfd(test1, 4)==FLOOR&&getcfd(test1, 2)==WALL&&getcfd(test1, 3)==WALL&&getcfd(test1, 1)==WALL)
			test = '4';
		else
			test = '0';
	} while(test == '0');
	mvaddch(0, 0, test);
	//Choose what to build
	int ibuild = rand(0, 2);
	ibuild = 1;
	if(ibuild == 1) //Build room
	{
		if(test == '1') //Build room below
		{
			coord c1 = {ix - ROOM_X, iy};
			coord c2 = {ix, iy + ROOM_Y};
			m_fill(c1, c2, FLOOR);
		}
		else if(test == '2') //Build room above
		{
			coord c1 = {ix - ROOM_X, iy - ROOM_Y};
			coord c2 = {ix, iy + 2};
			m_fill(c1, c2, FLOOR);
		}
		else if(test == '4') //Build room left
		{
			coord c1 = {ix - ROOM_X, iy};
			coord c2 = {ix + 2, iy + ROOM_Y};
			m_fill(c1, c2, FLOOR);
		}
		else if(test == '3') //Build room right
		{
			coord c1 = {ix, iy};
			coord c2 = {ix + ROOM_X, iy + ROOM_Y};
			m_fill(c1, c2, FLOOR);
		}	
	}
	numofI++;
	}
	int iy5, ix5;
	for(iy5 = 0; iy5 < MAP_Y + 100; iy5++)
		mvaddch(iy5, 0, WALL);
	for(ix5 = 0; ix5 < MAP_X + 100; ix5++)
		mvaddch(0, ix5, WALL);
}

//Movement

int c_move(creature *cre, int dir) //Move a creature in a direction, if no wall is present
{
	if(dir == 1)
	{
		if(getcfd((*cre).loc, 1) != WALL)
		{
			(*cre).loc.y--;
		}
	} else if(dir == 2)
	{
		if(getcfd((*cre).loc, 2) != WALL)
		{
			(*cre).loc.y++;
		}
	} else if(dir == 3)
	{
		if(getcfd((*cre).loc, 3) != WALL)
		{
			(*cre).loc.x--;
		}
	} else if(dir == 4)
	{
		if(getcfd((*cre).loc, 4) != WALL)
		{
			(*cre).loc.x++;
		}
	}
}

void draw_creatures(creature cre[], int max) //Draw creatures onto the screen
{
	int i;
	for(i = 0; i < max; i++)
	{
		if(cre[i].lit == TRUE)
			mvaddch(cre[i].loc.y, cre[i].loc.x, cre[i].icon);
	}
}

void clear_creatures(creature cre[], int max) //Clear all creatures from screen
{
	int i;
	for(i = 0; i < max; i++)
	{
		mvaddch(cre[i].loc.y, cre[i].loc.x, ' ');
	}
}


//Combat stuff


int dice(int sides, int times)
{
	int i, counter = 0;
	for(i = 0; i < times; i++)
	{
		counter = counter + rand(0, sides);
	}
}

void attack(creature *attacker, creature *defender)
{
	
}


//Monster stuff

void ai_step(creature *cre[], int max)
{

}




#ifdef TESTMAIN

int main()
{
	char c;
	srand(time(NULL));
	initscreen();
	g_dungeon(25);
	creature player;
	player.loc.x = MAP_X/2;
	player.loc.y = MAP_Y/2;
	mvaddch(player.loc.y, player.loc.x, '@');
	refresh();	
	while((c = getchar()) != 'q')
	{
		mvaddch(player.loc.y, player.loc.x, ' ');
		if(c == 'w')
			c_move(&player, 1);
		else if(c == 's')
			c_move(&player, 2);
		else if(c == 'a')
			c_move(&player, 3);
		else if(c == 'd')
			c_move(&player, 4);
		mvaddch(player.loc.y, player.loc.x, '@');
		refresh();
	}
	endwin();
	return 0;
}

#endif
