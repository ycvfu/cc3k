#include "poisonHealth.h"

PoisonHealth::PoisonHealth(int x, int y) : Potion{x, y}, hpDecr{-10} {}

 PoisonHealth::~PoisonHealth() { if (component) delete component; }

int PoisonHealth::getHP() {
	return component->getHP() + hpDecr;
}
