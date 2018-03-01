#ifndef DROW_H
#define DROW_H
#include "../character.h"
#include "player.h"
class Drow: public Player {
    public:
    Drow(int row, int col);
		Drow(Player * old);
//    Drow(int atkpt, int defence, int HP, Character *character, int gold);
    char getType() override;
    ~Drow() = default;
     void move(int relativeX, int relativeY) override;
     bool attack(Character *defender) override;
    int defend(Character *attacker) override;

};
#endif
