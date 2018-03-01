#include "woundDefence.h"

WoundDefence::WoundDefence(int x, int y) : Potion{x, y}, defDecr{-5} {}

 WoundDefence::~WoundDefence() { if (component) delete component; }

int WoundDefence::getDef() {
	return component->getDef() + defDecr;
}
