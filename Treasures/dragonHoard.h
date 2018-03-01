#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H
#include "treasure.h"

class DragonHoard : public Treasure {
	Dragon * guard;
	public:
		DragonHoard(int x, int y);
		~DragonHoard();
		void assignGuard(Dragon * g) override;
		bool isAvailable() override;
		void attackThief(Player * p) override;
		void open();
};

#endif
