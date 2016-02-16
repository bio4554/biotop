char getcfd(coord, int);
int c_move(creature *, int);
void draw_creatures(creature cre[], int);
void clear_creatures(creature cre[], int);
void ai_step(creature *cre[], int);

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

//Monster stuff

void ai_step(creature *cre[], int max)
{

}
