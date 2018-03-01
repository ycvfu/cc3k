#include "player.h"
#include <iostream>
#include <math.h>

using namespace std;

Player::Player(int atkpt, int defence, int HP, int row, int col, int gold) : 
    Character{atkpt, defence, HP, row, col, gold} {}
    
//Player::Player(int att, int def, int hp, Player * p, int g) :
//	Player{p->atkpt + att, p->defence + def, p->HP + hp, p->row, p->col, p->gold + g} {}

//Player::Player(int atkpt, int defence, int HP, Character*character, int gold) :
  //  Character{atkpt, defence, HP, character, gold} {}

void Player::attackThief(Player *p) {}

Player* Player::addGold(Player * p) { return p; }

Player* Player::addPotion(Player *p) { return p; }

int Player::defend(Character *attacker) {
 int y = ceil(double(100.0/(100 + defence) * attacker->getatk()));
    HP = HP - y;
    if(HP > 0) return -1;
    return 0;
    //some implementations will drop gold here. 
}

bool Player::attack(Character * character){
    int new_gold = character->defend(this);
    //not slain will return -1
    if(new_gold == -1) return false;
    if(new_gold > 0) gold = gold + new_gold;
    return true;
}


bool Player::isAvailable() {
	return false;
}



char Player::canPrintType() {
    return '@';
}

char Player::getType() {
	return 'Q';
}

int Player::getHP() {
	return HP;
}

int Player::getatk() {
	return atkpt;
}

int Player::getDef() {
	return defence;
}

int Player::getGold() {
	return gold;
}

int Player::getOriHP() {
	return HP;
}

int Player::getOriAtk() {
	return atkpt;
}

int Player::getOriDef() {
	return defence;
}
