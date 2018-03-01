#include "potion.h"

Potion::Potion(int x, int y) : Player{0, 0, 0, x, y, 0}, component{nullptr} {}

char Potion::getType() {
	if (component) return component->getType();
	return 'P';
}

char Potion::canPrintType() {
	if (component) return component->canPrintType();
	return getType();
}

Player* Potion::addPotion(Player * player) {
	component = player;
	return this;
}

int Potion::getHP() {
	if (component) return component->getHP();
	return 0;
}

int Potion::getatk() {
	if (component) return component->getatk();
	return 0;
}

int Potion::getDef() {
	if (component) return component->getDef();
	return 0;
}

int Potion::getGold() {
	return component->getGold();
}

int Potion::getOriHP() {
	return component->getOriHP();
}

int Potion::getOriatk() {
	return component->getOriatk();
}

int Potion::getOriDef() {
	return component->getOriDef();
}

int Potion::defend(Character *attacker) {
	return component->defend(attacker);
}

bool Potion::attack(Character *defender) {
	if (component) {
		return component->attack(defender);
	} 
	return false;
}

bool Potion::isSlain() {
	if (component) {
		return component->isSlain();
	}
	return false;
}

/*
bool Potion::move(int relativeX, int relativeY) {
	if (component) {
		return component->move(relativeX, relativeY);
	} 
	return false;
}
*/
