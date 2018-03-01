#include "treasure.h"

Treasure::Treasure(int x, int y, int gold) : Player{0, 0, 0, x, y, gold}, component{nullptr} {}

int Treasure::getValue() {
	return gold;
}

Player* Treasure::addGold(Player * player) {
	component = player;
	return this;
}

int Treasure::defend(Character *attacker) {
	return component->defend(attacker);
}

bool Treasure::attack(Character *defender) {
	return component->attack(defender);
}

bool Treasure::isSlain() {
	return component->isSlain();
}

int Treasure::getHP() {
	return component->getHP();
}

int Treasure::getatk() {
	return component->getatk();
}

int Treasure::getDef() {
	return component->getDef();
}

int Treasure::getOriHP() {
	return component->getOriHP();
}

int Treasure::getOriatk() {
	return component->getOriatk();
}

int Treasure::getOriDef() {
	return component->getOriDef();
}

char Treasure::getType() {
	if (component) return component->getType();
	return 'T';
}

int Treasure::getGold() {
	return component->getGold() + gold;
}

char Treasure::canPrintType() {
	if (component) return component->canPrintType();
	return 'G';
}

bool Treasure::isAvailable() {
	return true;
}

void Treasure::attackThief(Player * p) {
	// doesn't do anything here
	// implemented in DragonHoard class
}

void Treasure::assignGuard(Dragon * g) {}

/*
bool Treasure::move(int relativeX, int relativeY) {
	if(component) return component->move(relativeX, relativeY);
	return false;
}
*/

void Treasure::open() {}
