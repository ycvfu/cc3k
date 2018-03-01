#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include "potion.h"

class RestoreHealth : public Potion {
	int hpInc;
	public:
		RestoreHealth(int x, int y);
		~RestoreHealth();
		int getHP() override;
};

#endif
