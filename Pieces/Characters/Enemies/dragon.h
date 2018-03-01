#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Treasure;

class Dragon: public Enemy {
    Treasure * hoard;
    public:
    // constructor takes in a DragonHoard pointer and creates a dragon next to it
    Dragon(int row, int col, Treasure * hoard); 
    virtual bool attack(Character *defender) override;
    virtual int defend(Character *attacker) override;
    // instead of dropping gold, it tells the DragonHoard that the dragon
    //   is slain
    // std::bool dropGold() override;
    char canPrintType() override;
};
#endif
