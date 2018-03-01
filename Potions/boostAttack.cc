#include "boostAttack.h"

BoostAttack::BoostAttack(int x, int y) : Potion{x, y}, attInc{5} {}

BoostAttack::~BoostAttack() {
	if (component) delete component;
}

int BoostAttack::getatk() {
	return component->getatk() + attInc;
}
