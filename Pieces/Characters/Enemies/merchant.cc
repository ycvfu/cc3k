#include "merchant.h"
#include <math.h>
bool Merchant::Hostile;
Merchant::Merchant(int row, int col) : Enemy{70, 5, 30, row, col, 0} {} 
    

int Merchant::defend(Character *attacker) {
    Hostile = true;
int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));    
HP = HP - y;
    if(HP > 0) return -1;
    return 0;
    //some implementations will drop gold here. 
}

bool Merchant::attack(Character * character){
    if(Hostile) {
    int new_gold = character->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    return true;
    }
}

char Merchant::canPrintType() {
	return 'M';
}

bool Merchant::isHostile() {
    return Hostile;
}

