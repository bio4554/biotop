#include "externs.h"

void initscreen()
{
	initscr();
	raw();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
}

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
