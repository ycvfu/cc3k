#include "restoreHealth.h"

RestoreHealth::RestoreHealth(int x, int y) : Potion{x, y}, hpInc{10} {}

 RestoreHealth::~RestoreHealth() {if(component) delete component; }

int RestoreHealth::getHP() {
	return component->getHP() + hpInc;
}
