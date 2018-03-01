#ifndef GOBLIN_H
#define GOBLIN_H
#include "../character.h"
#include "player.h"
class Goblin: public Player {
    public: 
    Goblin(int row, int col);
		Goblin(Player * old);
   // Goblin(int atkpt, int defence, int HP, Character *character, int gold);
    bool attack(Character *defender) override;
    int defend(Character *attacker) override;
    char getType() override;
    void move(int relativeX, int relativeY) override;
    ~Goblin() = default;
};
#endif
