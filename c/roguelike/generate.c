void m_fill(coord, coord, char);
void m_hall(coord, int, int, char);
int g_scan(coord, coord, char);
void g_dungeon(int);

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
