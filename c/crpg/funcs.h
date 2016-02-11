#include "vault.h"

void cm_move(creature *cre, int moveto);
void cm_forward(creature *cre);
void cm_back(creature *cre);
void cm_nexttown(creature *cre, location locs[]);
void cm_prevtown(creature *cre, location locs[]);
void cm_nextroad(creature *cre, location locs[]);
void cm_prevroad(creature *cre, location locs[]);