#include "dwarf.h"
#include <math.h>


Dwarf::Dwarf(int row, int col) : Enemy{120, 30, 100, row, col, 0} {}

//it just says normal or small

int Dwarf::defend(Character *attacker) {
    int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));
    HP = HP - y;
    if(HP > 0) return -1;
    return 2;
    //some implementations will drop gold here. 
}

//Dwarf doesn't need to override attack

char Dwarf::canPrintType() {
	return 'W';
}

bool Dwarf::attack(Character *defender) {
    return Enemy::attack(defender);
}
