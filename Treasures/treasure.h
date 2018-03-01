#ifndef TREASURE_H
#define TREASURE_H
#include "../Pieces/Characters/Players/player.h"
#include "../Pieces/Characters/Enemies/dragon.h"

class Treasure : public Player {
	protected:
	Player * component;
	public:
		Treasure(int x, int y, int gold);
		virtual ~Treasure() = default;
		int getValue();
		virtual bool isAvailable();
		Player* addGold(Player * p);
		char getType() override;
		char canPrintType() override;
		virtual int getGold() override;
		int defend(Character *attacker);
		bool attack(Character *defender);
		bool isSlain();
		int getHP();
		int getatk();
		int getDef();
		int getOriHP();
		int getOriatk();
		int getOriDef();
		virtual void attackThief(Player * p);
		virtual void assignGuard(Dragon * g);
		// bool move(int relativeX, int relativeY) override;
		virtual void open();
};

#endif
