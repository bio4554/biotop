#include "god.h"

int god(int, int);

int god(int lower, int upper)
{
	srand(time(NULL));
	return ((rand() % upper) + lower);
}
