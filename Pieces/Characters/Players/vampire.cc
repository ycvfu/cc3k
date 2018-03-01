#include "vampire.h"
#include "player.h"
#include <iostream>
using namespace std; 

Vampire::Vampire(int row, int col) : Player{25,25,50, row, col, 0} {}
Vampire::Vampire(Player * old) : Player{25,25,old->getHP(),old->getX(),old->getY(), old->getGold()} {}
//should this be a character constructor? 

//Vampire::Vampire(int atkpt, int defence, int HP, Character*character, int gold) :
    //Player{atkpt, defence, HP, character, gold} {}
    
char Vampire::getType() {
    return 'V';
}


int Vampire::defend(Character *attacker) {
       return Player::defend(attacker);
}




bool Vampire::attack(Character * character){
    cout<<"attack"<<endl;
    int new_gold = character->defend(this);
    //not slain will return -1
    cout<< new_gold <<endl;
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    if(character->canPrintType()  == 'W') { //always or just sometimes?
        HP = HP - 5;
    } else {
        HP = HP + 5; 
    }
    cout<<new_gold<<endl;
    return true;
}


void Vampire::move(int relativeX, int relativeY) {
        Player::move(relativeX, relativeY);
}

