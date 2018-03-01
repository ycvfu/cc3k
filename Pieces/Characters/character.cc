#include "character.h"
#include "../../Floor/floor.h"

//you might want to consider adding gold_steal to defend, since we're stealing gold from enemies
using namespace std;

Character::Character(int atkpt, int defence, int HP, int row, int col, int gold) :
    atkpt{atkpt}, defence{defence}, HP{HP}, row{row}, col{col}, gold{gold}, max_HP{HP} {}

void Character::move(int relativeX, int relativeY) {
    col = col + relativeX;
    row = row + relativeY;
}

void Character::attackThief(Player * p) {}

Player* Character::addPotion(Player * player) {
	// overrident in player subclass
	return player;
}

Player* Character::addGold(Player * p) {
	return p;
}


bool Character::isSlain() {
    return HP <= 0;
}

bool Character::isAvailable() {
	return false;
}

int Character::getX() { return col; }
int Character::getY() { return row; } 
int Character::getHP() { return HP; }
int Character::getatk() { return atkpt; }
int Character::getDef() { return defence; }
int Character::getGold() { return gold; }
int Character::getOriHP() { return HP; }
int Character::getOriatk() { return atkpt; }
int Character::getOriDef() { return defence; }

Character::~Character() {}
