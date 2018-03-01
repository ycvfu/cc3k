#ifndef TROLL_H
#define TROLL_H
#include "../character.h"
#include "player.h"
class Troll: public Player {
    public:
    Troll(int row, int col);
		Troll(Player * old);
    //Troll(int atkpt, int defence, int HP, Character *character, int gold);
    void move(int relativeX, int relativeY) override; 
    virtual char getType() override;
    ~Troll() = default;
    bool attack(Character *defender) override;
    int defend(Character *attacker) override;

};
#endif
