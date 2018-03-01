#include "enemy.h"
#include <cstdlib>
#include <ctype.h>
#include <math.h>
#include <math.h>
 using namespace std; 


Enemy::Enemy(int atkpt, int defence, int HP, int row, int col, int gold) : Character{ atkpt, defence, HP, row, col, gold} {}


Enemy::~Enemy(){}
int Enemy::defend(Character *attacker) {
    int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));
    HP = HP - y;
    if(HP > 0) return -1;
    return 0;
    //some implementations will drop gold here. 
}



//need to change this in subclasses as well. 
bool Enemy::attack(Character * character){
    int new_gold = character->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    return true;
}

char Enemy::getType() {
	return 'E';
}
