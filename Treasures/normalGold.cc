#include "normalGold.h"

NormalGold::NormalGold(int x, int y) : Treasure{x, y, 2} {}

NormalGold::~NormalGold() {
	if(component) delete component;
}
