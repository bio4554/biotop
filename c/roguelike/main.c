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
