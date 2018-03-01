#ifndef POTION_H
#define POTION_H
#include "../Pieces/Characters/Players/player.h"

class Potion : public Player {
	protected:
	Player * component;
	public:
		Potion(int x, int y);
		virtual ~Potion() = default;
		char getType() override;
		char canPrintType() override;
		int getGold();
		virtual int getHP() override;
		virtual int getatk() override;
		virtual int getDef() override;
		int getOriHP() override;
		int getOriatk() override;
		int getOriDef() override;
		virtual int defend(Character *attacker);
		virtual bool attack(Character *defender);
		virtual bool isSlain();
		Player* addPotion(Player * player) override;
		// bool move(int relativeX, int relativeY) override;
};

#endif
