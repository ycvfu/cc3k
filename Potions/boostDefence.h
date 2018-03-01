#ifndef BOOSTDEFENCE_H
#define BOOSTDEFENCE_H
#include "potion.h"

class BoostDefence : public Potion {
	int defInc;
	public: 
		BoostDefence(int x, int y);
		~BoostDefence();
		int getDef() override;
};

#endif
