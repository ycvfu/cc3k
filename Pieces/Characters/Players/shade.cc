#include "shade.h"


Shade::Shade(int row, int col) : Player{25,25,125, row, col, 0} {}
Shade::Shade(Player * old) : Player{25, 25, old->getHP(), old->getX(), old->getY(), old->getGold()} {}

//should this be a character constructor? 
//Shade::Shade(int atkpt, int defence, int HP, Character*character, int gold) :
  //  Player{atkpt, defence, HP, character, gold} {}
    
char Shade::getType() {
    return 'S';
}

bool Shade::attack(Character *defender) {
    return Player::attack(defender);
  } 
int Shade::defend(Character *attacker) {
    return Player::defend(attacker);
}




void Shade::move(int relativeX, int relativeY) {
        Player::move(relativeX, relativeY);
}
    

    
    

    
