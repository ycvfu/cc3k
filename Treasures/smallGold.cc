#include "smallGold.h"

SmallGold::SmallGold(int x, int y) : Treasure{x, y, 1} {}

SmallGold::~SmallGold() {if (component) delete component; }
