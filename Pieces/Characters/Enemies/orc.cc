#include "orc.h"
#include "enemy.h"
#include <math.h>
Orc::Orc(int row, int col) : Enemy{30, 25, 180, row, col, 0} {}
    
Orc::~Orc(){}

int Orc::defend(Character *attacker) {
int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));    
HP = HP - y;
    if(HP > 0) return -1;
    return 2;
    //some implementations will drop gold here. 
}

bool Orc::attack(Character * defender){
    int new_gold = defender->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    return true;
}

char Orc::canPrintType() {
    return 'O';
}
