#include "dragonHoard.h"

DragonHoard::DragonHoard(int x, int y) : Treasure{x, y, 6} {}

DragonHoard::~DragonHoard() {if(component) delete component; }

void DragonHoard::assignGuard(Dragon * g) {
	guard = g;
}

bool DragonHoard::isAvailable() {
	// informs the player of whether the dragon hoard is available or not
	if (! guard) return true;
	return false;
}

void DragonHoard::attackThief(Player * p) {
	// player is in the vicinity of dragon hoard
	// attack player
	guard->attack(p);
}

void DragonHoard::open() {
	// dragon guard was slain and the dragon hoard is now available
	guard = nullptr;
}


