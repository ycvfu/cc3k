#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire: public Player {
    public:
    Vampire(int row, int col);
		Vampire(Player * old);
    //Vampire(int atkpt, int defence, int HP, Character *character, int gold);
	bool attack(Character *defender) override; 
    virtual char getType() override; 
    ~Vampire() = default;
    void move(int relativeX, int relativeY) override;
    int defend(Character *attacker) override;

};
#endif
