#ifndef WOUNDDEFENCE_H
#define WOUNDDEFENCE_H
#include "potion.h"

class WoundDefence : public Potion {
	int defDecr;
	public:
		WoundDefence(int x, int y);
		~WoundDefence();
		int getDef() override;
};

#endif
