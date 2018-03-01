#include "dragon.h"
#include "enemy.h"
#include <math.h>

Dragon::Dragon(int row, int col, Treasure * hoard) : Enemy {20, 20, 150, row, col, 0}, hoard{hoard} {}

bool Dragon::attack(Character *defender) {
        int new_gold = defender->defend(this);
	if(new_gold == -1) return false;
	return true;
}

int Dragon::defend(Character *attacker) {
int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));
    HP = HP - y;
    if(HP > 0) return -1;
   // hoard->open();
    return 0;
}

char Dragon::canPrintType() {
	return 'D';
}
