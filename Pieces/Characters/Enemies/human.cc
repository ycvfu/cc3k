#include "human.h"
#include <math.h>

Human::Human(int row, int col) : Enemy{20, 20, 140, row, col, 0} {}

Human::~Human(){}

bool Human::attack(Character * defender){
    int new_gold = defender->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    return true;
}

int Human::defend(Character *attacker) {
int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));    
HP = HP - y;
    if(HP > 0) return -1;
    return 0;
    //some implementations will drop gold here. 
    //issue: I don't think we can drop two golds. Like G G. I think there's only supposed to be one Gold regardless of how much we drop.
}

char Human::canPrintType() {
	return 'H';
}
