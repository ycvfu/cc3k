#include "woundAttack.h"

WoundAttack::WoundAttack(int x, int y) : Potion{x, y}, attDecr{-5} {}

WoundAttack::~WoundAttack() {if(component) delete component; }

int WoundAttack::getatk() {
	return component->getatk() + attDecr;
}
