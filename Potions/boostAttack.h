#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H
#include "potion.h"

class BoostAttack : public Potion {
	int attInc;
	public:
		BoostAttack(int x, int y);
		~BoostAttack();
		int getatk() override;
};

#endif
