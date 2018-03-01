#include "troll.h"
#include <iostream>

Troll::Troll(int row, int col) : Player{25,15,120, row, col, 0} {}
Troll::Troll(Player * old) : Player{25,15,old->getHP(),old->getX(), old->getY(), old->getGold()} {}

//should this be a character constructor? 
//Troll::Troll(int atkpt, int defence, int HP, Character*character, int gold) :
    //Player{atkpt, defence, HP, character, gold} {}
    


bool Troll::attack(Character *defender) {
   return Player::attack(defender);
}

int Troll::defend(Character *attacker) {
   return Player::defend(attacker);
}




char Troll::getType() {
    return 'T';
}


void Troll::move(int relativeX, int relativeY) {
    std::cout<<"trollingurself"<<std::endl;
    col = col + relativeX;
    row = row + relativeY;
    std::cout<<"row" << row << "col" << col << std::endl;
    HP = HP + 5;
    if(HP == max_HP) HP = max_HP;
}





