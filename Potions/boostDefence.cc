#include "boostDefence.h"

BoostDefence::BoostDefence(int x, int y) : Potion{x, y}, defInc{5} {}

 BoostDefence::~BoostDefence() { if (component) delete component; }

int BoostDefence::getDef() {
	return component->getDef() + defInc;
}
