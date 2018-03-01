#ifndef PLAYER_H
#define PLAYER_H
#include "../character.h"


class Player : public Character {
public:
    Player(int atkpt, int defence, int HP, int row, int col, int gold);
    // takes in old player with a potion for att, def, or hp, or gold
    //Player (int att, int def, int hp, Player * p, int gold);
    virtual int defend(Character *attacker) override;
    virtual bool attack(Character *defender) override;
	virtual void attackThief(Player * p) override;
	virtual Player* addPotion(Player * player) override;
	virtual Player* addGold(Player * p) override;
    virtual char getType();
    char canPrintType() override;
	virtual bool isAvailable() override;
	virtual int getHP();
	virtual int getatk();
	virtual int getDef();
	virtual int getGold();
	virtual int getOriHP();
	virtual int getOriDef();	
	virtual int getOriAtk();
    virtual ~Player() = default;
};

#endif
