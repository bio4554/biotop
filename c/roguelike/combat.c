#include "types.h"

int dice(int, int);
void attack(creature *, creature *);

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
