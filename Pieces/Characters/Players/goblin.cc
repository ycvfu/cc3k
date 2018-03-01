#include "goblin.h"
#include <math.h>

Goblin::Goblin(int row, int col) : Player{15,20,110, row, col, 0} {}
Goblin::Goblin(Player * old) : Player{15, 20, old->getHP(), old->getX(), old->getY(), old->getGold()} {}
//should this be a character constructor? 
//Goblin::Goblin(int atkpt, int defence, int HP, Character*character, int gold) :
  //  Player{atkpt, defence, HP, character, gold} {}

char Goblin::getType() {
    return 'G';
}

//If goblin steals 5 gold from every character, does that mean that even if it's a merchant, it automatically gains 5 gold? 
bool Goblin::attack(Character * character){
    int new_gold = character->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + 5;
    return true;
}

int Goblin::defend(Character *attacker) {
 int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));    
if(attacker->canPrintType() == 'O') {
        y = y * 1.5;
    } 
    HP = HP - y;
    if(HP > 0) return -1;
    return 0;
    //some implementations will drop gold here. i 
}

void Goblin::move(int relativeX, int relativeY) {
        Player::move(relativeX, relativeY);
}
