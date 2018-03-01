#ifndef WOUNDATTACK_H
#define WOUNDATTACK_H
#include "potion.h"

class WoundAttack : public Potion {
	int attDecr;
	public:
		WoundAttack(int x, int y);
		~WoundAttack();
		int getatk() override;
};

#endif
