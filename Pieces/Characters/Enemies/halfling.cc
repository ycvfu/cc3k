#include "halfling.h"
#include "enemy.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <cmath> 
#include <iomanip>

Halfling::Halfling(int row, int col) : Enemy{15, 20, 100, row, col, 0} {}
    
bool Halfling::attack(Character * character){
    int new_gold = character->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    return true;
}

//plAYER

int Halfling::defend(Character *attacker) {
    int prob = rand () % 2 ;  
    if(prob) {
    int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));
		HP = HP - y;
    if(HP > 0) return -1;
    return 2;
    } else {
        return -1;
    }
}

char Halfling::canPrintType() {
    return 'L';
}

