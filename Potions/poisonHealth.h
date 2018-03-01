#ifndef POISONHEALTH_H
#define POISONHEALTH_H
#include "potion.h"

class PoisonHealth : public Potion {
	int hpDecr;
	public:
		PoisonHealth(int x, int y);
		~PoisonHealth();
		int getHP() override;
};

#endif
