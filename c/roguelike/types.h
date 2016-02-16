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
