#include "drow.h"

Drow::Drow(int row, int col) : Player{25,15,150, row, col, 0} {}
Drow::Drow(Player * old) : Player{25,15, old->getHP(), old->getX(), old->getY(), old->getGold()} {}
//should this be a character constructor? 

//Drow::Drow(int atkpt, int defence, int HP, Character*character, int gold) :
  //  Player{atkpt, defence, HP, character, gold} {}
    

void Drow::move(int relativeX, int relativeY) {
	Player::move(relativeX, relativeY);
}


bool Drow::attack(Character *defender) {
   return Player::attack(defender);
} 

int Drow::defend(Character *attacker) {
   return Player::defend(attacker);
}

    
char Drow::getType() {
    return 'R';
}
