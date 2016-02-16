#include <stdlib.h>
#include <ncurses.h>
#include <time.h>






void initscreen()
{
	initscr();
	raw();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
}



void init_monsters()
{
	//Template creature
	creature blank;
	blank.loc.x = 500; blank.loc.y = 500;
	blank.icon = '#';
	blank.lit = FALSE;
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
