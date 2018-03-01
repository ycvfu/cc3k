#ifndef SHADE_H
#define SHADE_H
#include "../character.h"
#include "player.h"
class Shade : public Player {
public:
    Shade(int row, int col);
		Shade(Player * old);
    //Shade(int atkpt, int defence, int HP, Character* character, int gold);
    char getType() override;
    ~Shade() = default;
    void move(int relativeX, int relativeY) override;
    bool attack(Character *defender) override;
    int defend(Character *attacker) override;

};
#endif
