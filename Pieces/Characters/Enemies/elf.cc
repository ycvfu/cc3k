#include "elf.h"
#include "enemy.h"
#include <math.h>

Elf::~Elf(){}
Elf::Elf(int row, int col) : Enemy{30, 10, 140, row, col, 0} {}
    
int Elf::defend(Character *attacker) {
int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));    
HP = HP - y;
    if(HP > 0) return -1;
    return 2;
    //some implementations will drop gold here. 
}


bool Elf::attack(Character * defender){
    int new_gold = 0;
    if(defender->getType() == 'D') {
        new_gold = defender->defend(this);
    }
    new_gold = new_gold + defender->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    return true;
}


char Elf::canPrintType() {
	return 'E';
}

